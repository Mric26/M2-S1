rm(list=ls())

rotation <- function(pic, rot=90) {
  matrix <- as.matrix(pic)
  dim <- dim(matrix)
  
  
  if (rot == 90) {
    res <- matrix(0, dim[2], dim[1])
    for (i in 1:dim[2]) {
      res[i,] <- rev(matrix[,i])
    }
  }
  if (rot == 180) {
    res <- rotation(matrix, 90)
    res <- rotation(res, 90)
  }
  if (rot == 270) {
    res <- rotation(matrix, 90)
    res <- rotation(res, 90)
    res <- rotation(res, 90)
  }
  
  return ( res )
}

quantize <- function(pic, k=1) {
  image(as.matrix(pic), col = gray.colors(2^k))
}

reduction <- function(pic, m) {
  dim <- dim(pic)
  matrix <- as.matrix(pic)
  
  tmp <- matrix(0, dim[1]/m, dim[2])
  for (i in 1:dim[1]) {
    tmp[i/m,] <- matrix[i,]
  }
  
  res <- matrix(0,dim[1]/m, dim[2]/m)
  for (i in 1:dim[2]) {
    res[,i/m] <- tmp[,i]
  }
  
  return ( res )
}

pic <- read.csv(file="Documents/M2/M2-S1/Outils info/29-09-15/lena.csv", head=TRUE, sep=",")
image(as.matrix(pic), col = gray.colors(256))

#res <- rotation(img, rot=270)
#image(res)

#res <- quantize(pic, 3)

#res <- reduction(pic, 5)
#image(res)

