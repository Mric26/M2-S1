function plotCourbure(B)

[X,Y,Z] = peaks; 
[K,H,P1,P2] = surfature(X,Y,Z); 
surf(X,Y,Z,H,'facecolor','interp');  
set(gca,'clim',[-1,1])
