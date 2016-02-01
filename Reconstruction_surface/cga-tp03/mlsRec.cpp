#include "mlsRec.h"
#include <cmath>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

QImage MLSRec::apply(const QImage &img,float sigma) {

  // TODO apply weighted least squares on each pixel of the input image
  // example of image manipulation using Qt: 

  // copy input 
  QImage newImg = img;
  // iterate eover pixels 
  for(int x=0;x<img.width();++x) {
    for(int y=0;y<img.height();++y) {
      // get color at x,y
      Color current = getColor(img,x,y);
      
      // check if this color is missing in the image
      if(colorMissing(current)) {
	// set color as red 
//    current = Color(255.0f,0.0f,0.0f,255.0f);
//    current = estimateColorPlane(img, x, y, sigma);
//    current = estimateColorQuadric(img, x, y, sigma);
          current = estimateColorPlane(img, x, y, estimateSigma2(img, x, y) );
      }
      // set color in the new image
      setColor(newImg,x,y,current);
    }

    // show progression 
    if(!(x%10))
      cout << "MLS: " << (int)(((float)x/(float)(img.width()-2))*100.0f) << " percent done..." << '\r' << flush;
  }


  // example of matrix manip using Eigen:
  
  // 0 matrix with 4 rows, 3 columns
  MatrixXf M = MatrixXf::Zero(4,3);
  
  // set row 1 and column 3 to 5.0f
  M(0,2) = 5.0f;
  
  // transposed matrix 
  MatrixXf T = M.transpose();
  
  // multiplication 
  MatrixXf MT = M*T;

  // matrix inversion
  MatrixXf MTi = MT.inverse();

  // vector of size 4
  VectorXf v = VectorXf::Zero(4); 

  // matrix vector multiplication
  VectorXf Mv = MTi*v;

  return newImg;
}

double Distance(double dX0, double dY0, double dX1, double dY1){
    return sqrt(pow(dX1 - dX0, 2) + pow(dY1 - dY0, 2));
}

MLSRec::Color MLSRec::estimateColorPlane(const QImage &img,int x,int y,float sigma) {
    // estimate (and eval) a,b,c such that
    // ax + by + c = z
    // z being the value at pixel x,y (One MLS per channel then!)
    int f = 3 * sigma;
    int taille = 2*f + 1;
    // Initialisation des differentes matrices
    Eigen::MatrixXf A = Eigen::MatrixXf::Zero(taille*taille, 3);
    Eigen::MatrixXf W = Eigen::MatrixXf::Zero(taille*taille, taille*taille);
    Eigen::VectorXf br = Eigen::VectorXf::Zero(taille*taille);
    Eigen::VectorXf bg = Eigen::VectorXf::Zero(taille*taille);
    Eigen::VectorXf bb = Eigen::VectorXf::Zero(taille*taille);
    float PI = 3.141592;
    for(int i=-f; i<f+1; ++i) {
        for(int j=-f; j<f+1; ++j) {
            if( ((x+j) >= 0) && ((y+i)>=0) && ((x+j)<img.width()) && ((y+i)<img.height()) ){
                if ( !colorMissing( getColor(img, x+j, y+i )) ) {
                    A( (j+f)*taille+(i+f), 0) = x+j;
                    A( (j+f)*taille+(i+f), 1) = y+i;
                    A( (j+f)*taille+(i+f), 2) = 1;
                    float dist = pow( Distance( x+j, y+i, x, y ),2);
                    W( (j+f)*taille+(i+f), (j+f)*taille+(i+f) ) = ( 1.0 / ( sigma * sqrt( 2 * PI ) ) ) * exp( - (dist / (2*sigma*sigma)) );
                    br( (j+f)*taille+(i+f) ) = qRed( img.pixel(x+j, y+i) );
                    bg( (j+f)*taille+(i+f) ) = qGreen( img.pixel(x+j, y+i) );
                    bb( (j+f)*taille+(i+f) ) = qBlue( img.pixel(x+j, y+i) );
                }
            }
        }
    }
    Eigen::MatrixXf ATA = A.transpose() * W * A;
    Eigen::VectorXf xr = ATA.ldlt().solve(A.transpose() * W * br);
    Eigen::VectorXf xg = ATA.ldlt().solve(A.transpose() * W * bg);
    Eigen::VectorXf xb = ATA.ldlt().solve(A.transpose() * W * bb);
    float r = max(0, min( (int) (xr(0) * x + xr(1) * y + xr(2)), 255));
    float g = max(0, min( (int) (xg(0) * x + xg(1) * y + xg(2)), 255));
    float b = max(0, min( (int) (xb(0) * x + xb(1) * y + xb(2)), 255));
    return Color( r, g, b, 255.0f );
}

MLSRec::Color MLSRec::estimateColorQuadric(const QImage &img,int x,int y,float sigma) {
    // estimate (and eval) a,b,c,d,e,f such that
    // ax^2 + by^2 + cxy + dx + ey + f = z
    // z being the value at pixel x,y (One MLS per channel then!)
    int f = 3 * sigma;
    int taille = 2*f + 1;
    Eigen::MatrixXf A = Eigen::MatrixXf::Zero(taille*taille, 6);
    Eigen::MatrixXf W = Eigen::MatrixXf::Zero(taille*taille, taille*taille);
    Eigen::VectorXf br = Eigen::VectorXf::Zero(taille*taille);
    Eigen::VectorXf bg = Eigen::VectorXf::Zero(taille*taille);
    Eigen::VectorXf bb = Eigen::VectorXf::Zero(taille*taille);
    float PI = 3.141592;
    for(int i=-f; i<f+1; ++i) {
        for(int j=-f; j<f+1; ++j) {
            if( ((x+j) >= 0) && ((y+i)>=0) && ((x+j)<img.width()) && ((y+i)<img.height()) ){
                if ( !colorMissing( getColor(img, x+j, y+i )) ) {
                    A( (j+f)*taille+(i+f), 0) = pow(x+j, 2);
                    A( (j+f)*taille+(i+f), 1) = pow(y+i, 2);
                    A( (j+f)*taille+(i+f), 2) = (x+j) * (y+i);
                    A( (j+f)*taille+(i+f), 3) = x+j;
                    A( (j+f)*taille+(i+f), 4) = y+i;
                    A( (j+f)*taille+(i+f), 5) = 1;
                    float dist = pow( Distance( x+j, y+i, x, y ),2);
                    W( (j+f)*taille+(i+f), (j+f)*taille+(i+f) ) = ( 1.0 / ( sigma * sqrt( 2 * PI ) ) ) * exp( - (dist / (2*sigma*sigma)) );
                    br( (j+f)*taille+(i+f) ) = qRed( img.pixel(x+j, y+i) );
                    bg( (j+f)*taille+(i+f) ) = qGreen( img.pixel(x+j, y+i) );
                    bb( (j+f)*taille+(i+f) ) = qBlue( img.pixel(x+j, y+i) );
                }
            }
        }
    }
    Eigen::MatrixXf ATA = A.transpose() * W * A;
    Eigen::VectorXf xr = ATA.ldlt().solve(A.transpose() * W * br);
    Eigen::VectorXf xg = ATA.ldlt().solve(A.transpose() * W * bg);
    Eigen::VectorXf xb = ATA.ldlt().solve(A.transpose() * W * bb);
    float r = max(0, min( (int) (xr(0) * (x*x) + xr(1) * (y*y) + xr(2)*x*y + xr(3) * x + xr(4) * y + xr(5)), 255));
    float g = max(0, min( (int) (xg(0) * (x*x) + xg(1) * (y*y) + xg(2)*x*y + xg(3) * x + xg(4) * y + xg(5)), 255));
    float b = max(0, min( (int) (xb(0) * (x*x) + xb(1) * (y*y) + xb(2)*x*y + xb(3) * x + xb(4) * y + xb(5)), 255));
    return Color( r, g, b, 255.0f );
}


float MLSRec::estimateSigma(const QImage &img,int x,int y) {
    int d = 5;
    int somme = 0;
    int nb_elems = 0;
    for (int i = -d; i <= d; ++i) {
        for (int j = -d; j <= d; ++j) {
            if( ((x+j) >= 0) && ((y+i)>=0) && ((x+j)<img.width()) && ((y+i)<img.height()) ){
                if ( !colorMissing( getColor(img, x+j, y+i )) ) {
                    nb_elems++;
                    somme += Distance( x+j, y+i, x, y );
                }
            }
        }
    }
    return somme / nb_elems;
}

float MLSRec::estimateSigma2(const QImage &img,int x,int y) {
    // estimate sigma at x,y depending on the positions of nearest valid neighbors
    int seuil = 3;
    int sigma = 1.0;
    int count = 0;
    while (count < seuil && sigma < 100) {
        for(int i=-sigma; i<sigma+1; ++i) {
            for(int j=-sigma; j<sigma+1; ++j) {
                if( ((x+j) >= 0) && ((y+i)>=0) && ((x+j)<img.width()) && ((y+i)<img.height()) && (i != 0 || j != 0) ){
                    if ( !colorMissing( getColor(img, x+j, y+i )) ) {
                        count += 1;
                        if (count >= seuil) {
                            return sigma;
                        }
                    }
                }
            }
        }
        sigma++;
    }
    return sigma;
}
