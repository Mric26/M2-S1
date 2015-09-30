rm(list=ls())

library(biwavelet)

#rotation avec boucle
rotation <- function (image, rot = 90) {
  if (is.matrix(image) && ((rot==90)||(rot==180)||(rot==270)) ){
    #rotation
    dimension <- dim(image)
    if( rot == 90){
      res <- matrix(0, dimension[2], dimension[1])
      for (i in 1:dimension[2]) {
        res[i,]<-rev(image[,i]);
      }
    }
    else if( rot == 180){
      res <- rotation(image, 90)
      res <- rotation(res, 90);
    } 
    else{
      res <- rotation(image, 90)
      res <- rotation(res, 90)
      res <- rotation(res, 90);
    }
    return ( res );
  }
  else{
    #echec car mauvais format ou mauvais angle
    return ( image );
  }
}

#rotation sans boucle
rotation2 <- function (image, rot = 90) {
  if (is.matrix(image) && ((rot==90)||(rot==180)||(rot==270)) ){
    #rotation
    dimension <- dim(image)
    if( rot == 90){
      res <- rotation2(image, 180)
      res <- rotation2(res, 270);
    }
    else if( rot == 180){
      res <- rotation2(image, 270)
      res <- rotation2(res, 270);
    } 
    else{
      res <- apply(t(image),2,rev)
    }
    return ( res );
  }
  else{
    #echec car mauvais format ou mauvais angle
    return ( image );
  }
}

#quantification
quantification <- function (image, k) {
  if( (k<1) || (k>8) ){
    image( image );
  }
  else{
    image(image, col=gray.colors(2^k));
  }
}

#reduction sans boucle
reduction <- function (image, k) {
  dimension <- dim(image)
  ligne <- seq(1,dimension[1],k)
  colonne <- seq(1,dimension[2],k)
  res <- image[ligne, colonne]
  return( res );
}

#svd
svdp <- function (image, i) {
  image.svd <- svd(image,i)
  
  d <- image.svd$d
  u <- image.svd$u
  v <- image.svd$v
  
  image.compressed <- u[,1:i] %*% diag(d[1:i]) %*% t(v[,1:i])
  
  return( image.compressed )
}

#moyenneur
moyenneur <- function (image, taille) {
  noyaux <- matrix( 1/(taille*taille), 1, taille)
  res <- convolve2D(image, noyaux,type="open")
  res <- rotation2(res, 90)
  res <- convolve2D(res, noyaux,type="open")
  return( res );
}

########################################### CODE ###########################################

lena <- read.csv(file="Documents/M2-S1/Outils info/29-09-15/lena.csv",head=TRUE,sep=",")
mode(lena)
lenaI <- as.matrix(lena)
dim(lena)
image(lenaI)

image(lenaI, col=gray.colors(255))

lenaRot <- rotation2(lenaI, 90)
image(lenaRot)
lenaRot <- rotation2(lenaI, 180)
image(lenaRot)
lenaRot <- rotation2(lenaI, 270)
image(lenaRot)

quantification(lenaI, 1)
quantification(lenaI, 4)

lenaRedu <- reduction(lenaI, 5)
image( lenaRedu )

lenaSvd <- svdp(lenaI, 20)
image(lenaSvd)

lenaMoyen <- moyenneur(lenaI,3)
image(lenaMoyen)

############################################################################################
