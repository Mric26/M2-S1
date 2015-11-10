function plotCourbure(S)

[X,Y,Z] = peaks;
X = S(:,:,1);
Y = S(:,:,2);
Z = S(:,:,3);
[K,H,P1,P2] = surfature(X,Y,Z); 
surf(X,Y,Z,H,'facecolor','interp');  
set(gca,'clim',[-1,1])
