function plotBezierSurfacePerso(B,S,N)

str1='\bf Control Point';
str2='\bf Control Polygon';
str3='\bf Patch (bi-directional Bezier curve)';

% %-----------------------------------------------
% % lot de Reseau de controle 
figure, hold on
surface(B(:,:,1),B(:,:,2),B(:,:,3),'FaceColor','y')
title('\bf Reseau de controle');
view(3); box;  view(21,19)
% %-----------------------------------------------% 
% % Plot de Patch de Bezier
figure, hold on
surface(S(:,:,1),S(:,:,2),S(:,:,3),'FaceColor','r')
quiver3(S(:,:,1),S(:,:,2),S(:,:,3), N(:,:,1),N(:,:,2),N(:,:,3))
title('\bf Surface de Bezier');
view(3); box;  view(21,19)