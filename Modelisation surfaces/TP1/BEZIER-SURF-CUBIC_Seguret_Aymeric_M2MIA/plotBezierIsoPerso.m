function plotBezierIsoPerso(B,S,N,I)

str1='\bf Control Point';
str2='\bf Control Polygon';
str3='\bf Patch (bi-directional Bezier curve)';

% % Plot de Patch de Bezier
figure, hold on
colormap hsv
surface(S(:,:,1),S(:,:,2),S(:,:,3),I)

title('\bf Surface de Bezier');
view(3); box;  view(21,19)