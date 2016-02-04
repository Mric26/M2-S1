#include "pointsToSurface.h"
#include <iostream>

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
        //calcul At * A (Si bug pensezr a verifier)
        vector< vector<double> > AtA = vector< vector<double> >(3);
        for (int k = 0; k < AtA.size(); ++k) {
            AtA[k] = vector<double>(3);
        }
        for (int i = 0; i < AtA.size(); ++i) {
            for (int j = 0; j < AtA[i].size(); ++j) {
                double res = 0.0;
                for (int k = 0; k < v.size(); ++k) {
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
//        _noNormals = v_Point3D();
    }
}

void PointsToSurface::computeMinimalSpanningTree() {
  // a remplir : _acm
}

void PointsToSurface::computeOrientedNormals() {
  // a remplir : _oNormals
}

double PointsToSurface::computeImplicitFunc(double x,double y,double z) {
  // a faire : déterminer la fonction implicite (MLS)

  return x+y+z;
}

void PointsToSurface::computeNormalsFromImplicitFunc() {
  // a remplir : _surfacen
}

void PointsToSurface::computeMesh() {
  // a remplir : _surfacep
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
