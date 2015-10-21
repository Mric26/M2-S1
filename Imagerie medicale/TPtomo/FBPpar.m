% Programme de test de la lecture des données
% lecture d'un sinogramme
% et lecture du sinogramme médical
% 
clear all; close all;
nphi=127;% nphi=P=nombre de projections
ns=80;% ns=Q=nombre de translations  
g=litsinogramme('data127x80',nphi,ns); % lecture des données simulées

g = g';


filter = [-ns/2:ns/2-1]';
filter = abs(filter);
filter = fftshift(filter);


plot(-ns/2:ns/2-1,filter');

fg=fft(g);
Ffg=zeros(size(g));
for r=1:nphi
%     fg = fft(g(:,r));
     Ffg(:,r) = filter.*fg(:,r);   
end
gfiltered = ifft(Ffg);
max(max(imag(gfiltered)))
figure
imagesc(real(gfiltered));


