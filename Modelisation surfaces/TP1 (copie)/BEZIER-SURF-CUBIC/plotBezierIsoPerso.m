function plotBezierIsoPerso(B,S,I)

str1='\bf Control Point';
str2='\bf Control Polygon';
str3='\bf Patch (bi-directional Bezier curve)';

% % Plot de Patch de Bezier
figure, hold on
surface(S(:,:,1),S(:,:,2),S(:,:,3),'FaceColor','r')
quiver3(S(:,:,1),S(:,:,2),S(:,:,3), I(:,:,1),I(:,:,2),I(:,:,3))
title('\bf Surface de Bezier');
view(3); box;  view(21,19)