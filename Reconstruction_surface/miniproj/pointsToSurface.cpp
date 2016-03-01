#include "pointsToSurface.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <QHash>
#include <fstream>

using namespace std;

PointsToSurface::PointsToSurface(const QString &filename) 
  : _acm(0) {
  setlocale(LC_ALL,"C");

  if(!readInputFile(filename)) {
    cout << "Error while loading" << filename.toStdString() << endl;
    exit(0);
  }
}

PointsToSurface::~PointsToSurface() {
  _points.clear();
}

Point3D PointsToSurface::barycentre( v_Point3D v) {
    double taille = v.size();
    Point3D res;
    foreach (Point3D p, v) {
        res = res + p;
    }
    return Point3D( res/taille );
}

void PointsToSurface::computeNonOrientedNormals() {
    foreach (Point3D p, _points) {
        //calcul voisins
        v_Point3D v = kneighborhoodPoints(p, _points, 6);
        //calcul barycentre
        Point3D B = barycentre( v );
        //calcul A
        vector< vector<double> > A = vector< vector<double> >();
        foreach (Point3D p2, v) {
            vector<double> temp = vector<double>();
            temp.push_back( p2.x - B.x );
            temp.push_back( p2.y - B.y );
            temp.push_back( p2.z - B.z );
            A.push_back( temp);
        }
        //calcul At * A
        vector< vector<double> > AtA = vector< vector<double> >(3);
        for (size_t k = 0; k < AtA.size(); ++k) {
            AtA[k] = vector<double>(3);
        }
        for (size_t i = 0; i < AtA.size(); ++i) {
            for (size_t j = 0; j < AtA[i].size(); ++j) {
                double res = 0.0;
                for (size_t k = 0; k < v.size(); ++k) {
                    res += A[k][i] * A[k][j];
                }
                AtA[i][j] = res;
            }
        }
        //calculs des vecteurs propres
        Point3D a = Point3D();
        Point3D b = Point3D();
        Point3D c = Point3D();
        calcul_repere_vecteurs_propres( AtA[0][0], AtA[0][1], AtA[0][2], AtA[1][1], AtA[1][2], AtA[2][2], a, b, c );
        //recuperation normales non orientés
        Point3D norm = Point3D(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
        _noNormals.push_back(norm);
    }
}

double PointsToSurface::calculR() {
    double r = 0;
    foreach (Point3D p1, _points) {
        v_Point3D v = kneighborhoodPoints(p1, _points, 2);
        Point3D p2 = v.at(1);
        r = max(r, distance_(p1, p2) );
    }
    return r+(r/100);
}

void PointsToSurface::computeMinimalSpanningTree() {
    //construction graphe de proximité
    double r = calculR();
    int t = _points.size();
    _acm = Graphe(t);
    for (int i = 0; i < t; ++i) {
        Point3D p1 = _points.at(i);
        //recherche selon la distance
        for (int k = i; k < t; ++k) {
            Point3D p2 = _points.at(k);
            if( (i!=k) && (distance_(p1, p2) < r) ){
                //calcul du poids
                double poids = 0.0;
                Point3D n1 = _noNormals.at(i);
                Point3D n2 = _noNormals.at(k);
                poids = 1 - abs( n1.x*n2.x + n1.y*n2.y + n1.z*n2.z );
                //ajout arc
                _acm.ajouter_arc(i, k, poids );
            }
        }
    }
    //calcul arbre couvrant de poids minimal
    _acm = _acm.arbre_couvrant_minimal();
}

void PointsToSurface::computeOrientedNormals() {
  // a remplir : _oNormals
    _oNormals = v_Point3D( _noNormals );
    unsigned int racine = 0;
    //paramètre recursifs
    vector<int> v;
    bool t[ _acm.nb_noeuds() ];
    for (unsigned int a = 0; a < _acm.nb_noeuds(); ++a) {
       t[a] = false;
    }
    //recursions
    v.push_back(racine);
    computeRecursiveOrientedNormals( v, t );
}

void PointsToSurface::computeRecursiveOrientedNormals( vector<int> v, bool t[]  ) {
    vector<int> v2;
    foreach (unsigned int racine, v) {
        Noeud racineN = _acm.noeud(racine);
        foreach ( int n, racineN.la ) {
            Arc a = _acm.arc(n);
            Point3D n1 = _oNormals.at(a.n1);
            n1.normalise();
            Point3D n2 = _oNormals.at(a.n2);
            n2.normalise();
            double ps = n1.x*n2.x + n1.y*n2.y + n1.z*n2.z;
            //si negatif on inverse la bonne normale
            if( ps < 0 ){
                if( a.n1 == racine ){
                    _oNormals[a.n2] = -n2;
                }
                else{
                    _oNormals[a.n1] = -n1;
                }
            }
            //on ajoute aux points à visiter
            if( (a.n1 == racine) && (t[a.n2] == false) ){
                v2.push_back( a.n2 );
                t[a.n2] = true;
            }
            else if ( (a.n2 == racine) && (t[a.n1] == false) ){
                v2.push_back( a.n1 );
                t[a.n1] = true;
            }
        }
    }
    if( v2.size() != 0 ){
        computeRecursiveOrientedNormals( v2, t );
    }
}

double PointsToSurface::computeImplicitFunc(double x,double y,double z) {
  // a faire : déterminer la fonction implicite (MLS)
    double sigma = 1.0;
    Point3D p = Point3D(x, y, z);
    Point3D pi;
    double somme_haut = 0.0;
    double somme_bas = 0.0;
    for (size_t i = 0; i < _points.size(); ++i) {
        pi = _points.at(i);
        double disti = distance_(p, pi);
        double wi = exp( - pow( disti/sigma, 2.0 ) );
        Point3D ni = _oNormals.at(i);
        Point3D diff = p - pi;
        double ps = ni.x*diff.x + ni.y*diff.y + ni.z*diff.z;
        somme_haut += ps*wi;
        somme_bas += wi;
    }
  return somme_haut/somme_bas;
}

void PointsToSurface::computeNormalsFromImplicitFunc() {
  // a remplir : _surfacen
    vector<Point3D> v;
    Point3D p1, p2, p3, res1, res2, res3;
    double x, y, z;
    Triangle3D rest;
    foreach (Triangle3D t, _surfacep) {
        p1 = t.S0;
        p2 = t.S1;
        p3 = t.S2;
        if( !v.empty() && (find(v.begin(), v.end(), p1) == v.end()) ){
            x = p1.x; y = p1.y; z = p1.z;
            double nx = computeImplicitFunc( x-0.01, y, z ) - computeImplicitFunc( x+0.01, y, z );
            double ny = computeImplicitFunc( x, y-0.01, z ) - computeImplicitFunc( x, y+0.01, z );
            double nz = computeImplicitFunc( x, y, z-0.01 ) - computeImplicitFunc( x, y, z+0.01 );
            res1 = Point3D(nx, ny, nz);
            v.push_back(p1);
        }
        if( !v.empty() && (find(v.begin(), v.end(), p2) == v.end()) ){
            x = p2.x; y = p2.y; z = p2.z;
            double nx = computeImplicitFunc( x-0.01, y, z ) - computeImplicitFunc( x+0.01, y, z );
            double ny = computeImplicitFunc( x, y-0.01, z ) - computeImplicitFunc( x, y+0.01, z );
            double nz = computeImplicitFunc( x, y, z-0.01 ) - computeImplicitFunc( x, y, z+0.01 );
            res2 = Point3D(nx, ny, nz);
            res2.normalise();
            v.push_back(p2);
        }
        if( !v.empty() && (find(v.begin(), v.end(), p3) == v.end()) ){
            x = p3.x; y = p3.y; z = p3.z;
            double nx = computeImplicitFunc( x-0.01, y, z ) - computeImplicitFunc( x+0.01, y, z );
            double ny = computeImplicitFunc( x, y-0.01, z ) - computeImplicitFunc( x, y+0.01, z );
            double nz = computeImplicitFunc( x, y, z-0.01 ) - computeImplicitFunc( x, y, z+0.01 );
            res3 = Point3D(nx, ny, nz);
            res3.normalise();
            v.push_back(p3);
        }

        rest.S0 = res1;
        rest.S1 = res2;
        rest.S2 = res3;
        _surfacen.push_back( rest );
    }
}

void PointsToSurface::save_obj(){
    string save_path = "/home/s/segureta/Documents/M2-S1/Reconstruction_surface/surface.obj";
    vector<glm::vec3> v;
    Point3D p1, p2, p3;
    foreach (Triangle3D t, _surfacep) {
//        cout << "Suivant : " << endl;
        p1 = t.S0;
        v.push_back( glm::vec3(p1.x, p1.y, p1.z) );
//        cout << p1.x << " ; " << p1.y << " ; "<< p1.z << endl;
        p2 = t.S1;
        v.push_back( glm::vec3(p2.x, p2.y, p2.z) );
//        cout << p2.x << " ; " << p2.y << " ; "<< p2.z << endl;
        p3 = t.S2;
        v.push_back( glm::vec3(p3.x, p3.y, p3.z) );
//        cout << p3.x << " ; " << p3.y << " ; "<< p3.z << endl;
    }

    assert(v.size()%3==0);
    ofstream f;
    f.open (save_path.c_str());
    for (unsigned int i=0;i<v.size();++i){
        f<<"v "<<v.at(i).x<<" "<<v.at(i).y<<" "<<v.at(i).z<<"\n";
    }
    for (unsigned int i=0;i<v.size()/3;++i){
        f<<"f "<<(3*i+1)<<" "<<(3*i+2)<<" "<<(3*i+3)<<"\n";
    }
    f.close();
}

void PointsToSurface::computeMesh() {
//    for (int i = 0; i < _points.size(); ++i) {
//        Point3D p = _points.at(i);
//        Point3D n = _oNormals.at(i);
//        cout << "Next" << endl;
//        cout << computeImplicitFunc(p.x-(n.x/10), p.y-(n.y/10), p.z-(n.z/10)) << endl;
//        cout << computeImplicitFunc(p.x, p.y, p.z) << endl;
//        cout << computeImplicitFunc(p.x+(n.x/10), p.y+(n.y/10), p.z+(n.z/10)) << endl;
//        cout << computeImplicitFunc(p.x+(n.x/10*3), p.y+(n.y/10*3), p.z+(n.z/10*3)) << endl;
//        cout << computeImplicitFunc(p.x+(n.x/10*4), p.y+(n.y/10*4), p.z+(n.z/10*4)) << endl;
//    }
    //creation de la grille 3D
    double xmin0 = 10000000;
    double ymin0 = 10000000;
    double zmin0 = 10000000;
    double xmax0 = -10000000;
    double ymax0 = -10000000;
    double zmax0 = -10000000;
    foreach ( Point3D p, _points ) {
        xmin0 = min( xmin0, p.x );
        ymin0 = min( ymin0, p.y );
        zmin0 = min( zmin0, p.z );
        xmax0 = max( xmax0, p.x );
        ymax0 = max( ymax0, p.y );
        zmax0 = max( zmax0, p.z );
    }
    xmin0 = xmin0 - 0.1 ;
    ymin0 = ymin0 - 0.1 ;
    zmin0 = zmin0 - 0.1 ;
    xmax0 = xmax0 + 0.1 ;
    ymax0 = ymax0 + 0.1 ;
    zmax0 = zmax0 + 0.1 ;
    unsigned int nx0 = 10;
    unsigned int ny0 = 10;
    unsigned int nz0 = 10;
    Grille3D G = Grille3D(xmin0, ymin0, zmin0, xmax0, ymax0, zmax0, nx0, ny0, nz0);
    //création d'un tableau contenant les valeurs de la fonction implicite
    double vf[ nx0 * ny0 * nz0 ];
    int DIM_X = G.nx();
    int DIM_Y = G.ny();
    double x, y, z;
    for (unsigned int i = 0; i < nx0; ++i) {
        x = G.x(i);
        for (unsigned int j = 0; j < ny0; ++j) {
            y = G.y(j);
            for (unsigned int k = 0; k < nz0; ++k) {
                z = G.z(k);
                vf[i+DIM_X*(j+DIM_Y*k)] = computeImplicitFunc( x, y, z );
//                cout << vf[i+DIM_X*(j+DIM_Y*k)] << endl;
            }
        }
    }
    //calcul surface
    double v0 = 0.0;
    SurfaceIsovaleurGrille sig;
    sig.surface_isovaleur( _surfacep, G, vf, v0 );
//    save_obj();
}

void PointsToSurface::computeSurface() {
  // appelle toutes les fonctions pour reconstruire la surface 
  cout << "computing non-oriented normals..." << endl;
  computeNonOrientedNormals();
  cout << "computing minimal spanning tree..." << endl;
  computeMinimalSpanningTree();
  cout << "computing oriented normals..." << endl;
  computeOrientedNormals();
  cout << "computing mesh surface..." << endl;
  computeMesh();
  cout << "computing final normals..." << endl;
  computeNormalsFromImplicitFunc();
}

v_Point3D  PointsToSurface::kneighborhoodPoints(const Point3D &p,const v_Point3D &pts,unsigned int k) const {
  // renvoie les k points les plus proches de p dans la liste de points pts

  v_Point3D neighbors;

  if(k==0) return neighbors;

  if(pts.size()<k) k=pts.size();
  neighbors.resize(k);
  
  std::vector<double> dist(pts.size());
  unsigned int imax = 0;

  for(unsigned int i=0;i<pts.size();++i) {
    dist[i]=distance_(p,pts[i]);
    
    if(dist[i]>dist[imax]) 
      imax=i;
  }


  for(unsigned int i=0;i<k;++i) {
    unsigned int index=0;
    
    for(unsigned int j=0;j<pts.size();++j) {
      if(dist[j]<dist[index]) 
	index=j;
    }

    neighbors[i]=pts[index];
    dist[index] = dist[imax]+1;
  }

  return neighbors;
}

bool PointsToSurface::readInputFile(const QString &filename) {

  _points.clear();
  
  FILE *f;
  unsigned int nS;
  double r;
  
  // ouverture du fichier
  if ((f = fopen(filename.toStdString().c_str(),"r"))==(FILE *)NULL)
    return false;
	
  // lecture du nombre de points et du rayon d'échantillonnage
  if(fscanf(f, "%i %lf\n", &nS, &r)==EOF) return false;
	
  // lecture des points
  _points.resize(nS);
  for (unsigned int i=0; i<nS; i++) {
    if(fscanf(f, " %lf %lf %lf\n", &_points[i].x, &_points[i].y, &_points[i].z)==EOF) return false;
  }

  boite_englobante(_points,_boundingBox[0],_boundingBox[1]);

  // mean of the min distance between 2 points
  _meanDist = 0.0;
  for(unsigned int i=0;i<_points.size();++i) {
    v_Point3D pts = kneighborhoodPoints(_points[i],_points,2);
    _meanDist = _meanDist+distance_(pts[0],pts[1]);
  }
  _meanDist = _meanDist/(double)_points.size();

  // fermeture du fichier
  fclose(f);
	
  return true;
}
