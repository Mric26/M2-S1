function plotCourbure(S)

[X,Y,Z] = peaks;
X = S(:,:,1);
Y = S(:,:,2);
Z = S(:,:,3);
[K,H] = surfature(X,Y,Z);

surf(X,Y,Z,K,'facecolor','interp');  
set(gca,'clim',[-1,1])
