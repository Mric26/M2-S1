#include "mlsRec.h"
#include <cmath>
#include <algorithm>
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
//        current = Color(255.0f,0.0f,0.0f,255.0f);
        current = estimateColorPlane(img, x, y, sigma);
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
    return sqrt((dX1 - dX0)*(dX1 - dX0) + (dY1 - dY0)*(dY1 - dY0));
}

MLSRec::Color MLSRec::estimateColorPlane(const QImage &img,int x,int y,float sigma) {
    // estimate (and eval) a,b,c such that
    // ax + by + c = z
    // z being the value at pixel x,y (One MLS per channel then!)
    int f = 3 * sigma;
    int taille = 2*f + 1;
    Eigen::MatrixXf A = Eigen::MatrixXf(taille*taille, 3);
    Eigen::MatrixXf W = Eigen::MatrixXf(taille*taille, taille*taille);
    Eigen::VectorXf br = Eigen::VectorXf(taille*taille);
    Eigen::VectorXf bg = Eigen::VectorXf(taille*taille);
    Eigen::VectorXf bb = Eigen::VectorXf(taille*taille);
    float Pi = 3.141592;
    for(int i=-f; i<f+1; ++i) {
        for(int j=-f; j<f+1; ++j) {
            if( ((x+j) >= 0) && ((y+i)>=0) && ((x+j)<img.height()) && ((y+i)<img.width()) ){
                A( (i+f)*5+(j+f), 0) = x+j;
                A( (i+f)*5+(j+f), 1) = y+i;
                A( (i+f)*5+(j+f), 2) = 1;
                if (colorMissing( getColor(img, x+j, y+i )) ) {
                    W( (i+f)*5+(j+f), (i+f)*5+(j+f) ) = 0;
                } else {
                    W( (i+f)*5+(j+f), (i+f)*5+(j+f) ) = ( 1.0 / ( sigma * sqrt( 2 * Pi ) ) ) * exp( - pow(( Distance( x+j, y+i, x, y ) / sigma ),2) );
                }
                br( (i+f)*5+(j+f) ) = qRed( img.pixel(x+j, y+i) );
                bg( (i+f)*5+(j+f) ) = qGreen( img.pixel(x+j, y+i) );
                bb( (i+f)*5+(j+f) ) = qBlue( img.pixel(x+j, y+i) );
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

  // TODO
  return Color(0.0f,0.0f,0.0f,255.0f);
}


float MLSRec::estimateSigma(const QImage &img,int x,int y) {
  // estimate sigma at x,y depending on the positions of nearest valid neighbors
  
  // TODO 
  return 2.0f;
}
