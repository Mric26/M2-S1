#ifndef IMAGE_H
#define IMAGE_H

#ifdef DEBUG
#define DEB(_x_) _x_
#else
#define DEB(_x_)
#endif

/*=====================================================================================
 * STRUCTURE D'IMAGE 
 *===================================================================================*/

struct image {
   int largeur,hauteur,valmax;
     int* buffer;
};

#endif
