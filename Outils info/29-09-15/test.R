rm(list=ls())

rotation_opti90 <- function(pic) {
  matrix <- as.matrix(pic)
  return ( apply(t(matrix), 2, rev) )
}

rotation_opti180 <- function(pic) {
  matrix <- rotation_opti90(pic)
  matrix <- rotation_opti90(matrix)
  return ( matrix )
}

rotation_opti270 <- function(pic) {
  matrix <- rotation_opti90(pic)
  matrix <- rotation_opti90(matrix)
  matrix <- rotation_opti90(matrix)
  return ( matrix )
}

quantize <- function(pic, k=1) {
  image(as.matrix(pic), col = gray.colors(2^k))
}

reduction_opti <- function(pic, m) {
  matrix <- as.matrix(pic)
  dim <- dim(matrix)
  seq_line <- seq(1, dim[1], m)
  seq_column <- seq(1, dim[2], m)
  return ( matrix[seq_line, seq_column] )
}


compression <- function(pic, k=1) {
  matrix <- as.matrix(pic)
  svd <- svd(matrix, k)
  d <- svd$d
  u <- svd$u
  v <- svd$v
  return ( u[,1:k] %*% diag(d[1:k]) %*% t(v[,1:k]) )
}

distance <- function(matrix1, matrix2) {
  dim1 <- dim(matrix1)
  dim2 <- dim(matrix2)
  if (dim1[1] == dim2[1] && dim1[2] == dim2[2]) {
    return ( sqrt( sum( (matrix1-matrix2)^2 )) )
  } else {
    return ( -1 ) # GG Noob !
  }
}


################################################
pic <- read.csv(file="Documents/M2/M2-S1/Outils info/29-09-15/lena.csv", head=TRUE, sep=",")
image(as.matrix(pic), col = gray.colors(256))

res <- rotation_opti90(pic)
image(res)

res <- rotation_opti180(pic)
image(res)

res <- rotation_opti270(pic)
image(res)

#res <- quantize(pic, 3)

#res <- reduction_opti(pic, 2)
#image(res)

m <- as.matrix(pic)
res1 <- compression(pic, 2)
res2 <- compression(pic, 10)
res3 <- compression(pic, 15)
res4 <- compression(pic, 30)

distance(m, res1)
distance(m, res2)
distance(m, res3)
distance(m, res4)

image(res4)
