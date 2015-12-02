function [K,H] = surfature(X,Y,Z),
% renvois :
%       K : the gaussian curvature
%       H : mean curvature

% Dérivées premières
[Xu,Xv] = gradient(X);
[Yu,Yv] = gradient(Y);
[Zu,Zv] = gradient(Z);

% Dérivées secondes
[Xuu,Xuv] = gradient(Xu);
[Yuu,Yuv] = gradient(Yu);
[Zuu,Zuv] = gradient(Zu);

[Xuv,Xvv] = gradient(Xv);
[Yuv,Yvv] = gradient(Yv);
[Zuv,Zvv] = gradient(Zv);

Xu = Xu(:);   Yu = Yu(:);   Zu = Zu(:); 
Xv = Xv(:);   Yv = Yv(:);   Zv = Zv(:); 
Xuu = Xuu(:); Yuu = Yuu(:); Zuu = Zuu(:); 
Xuv = Xuv(:); Yuv = Yuv(:); Zuv = Zuv(:); 
Xvv = Xvv(:); Yvv = Yvv(:); Zvv = Zvv(:); 

Xu =   [Xu Yu Zu];
Xv =   [Xv Yv Zv];
Xuu =   [Xuu Yuu Zuu];
Xuv =   [Xuv Yuv Zuv];
Xvv =   [Xvv Yvv Zvv];

E =   dot(Xu,Xu,2);
F =   dot(Xu,Xv,2);
G =   dot(Xv,Xv,2);

m =   cross(Xu,Xv,2);
p =   sqrt(dot(m,m,2));
n =   m./[p p p]; 

L =   dot(Xuu,n,2);
M =   dot(Xuv,n,2);
N =   dot(Xvv,n,2);

[s,t] = size(Z);

% Gaussian Curvature
K = (L.*N - M.^2)./(E.*G - F.^2);
K = reshape(K,s,t);

% Mean Curvature
H = (E.*N + G.*L - 2.*F.*M)./(2*(E.*G - F.^2));
H = reshape(H,s,t);
