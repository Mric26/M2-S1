clear all;
close all;

% Programme de test de la lecture des données
% lecture d'un sinogramme
% et lecture du sinogramme médical

nphi = 127;   % nphi = P = nombre de projections
ns = 80;      % ns = Q = nombre de translations  

% lecture des données simulées
g = litsinogramme('data127x80', nphi, ns);



gFilter = zeros(80,127);
filter = -ns/2 : 1 : (ns/2)-1;
filter = abs(filter);
filter = fftshift(filter);


for k=1:nphi
    % projection n°k en vecteur colonne
    proj_k = g(k,:)';
    % fast fourier transform
    Gk = fft(proj_k);
    % vecteur colonne de 80 valeurs
    FGk = filter' .* Gk;
    % vecteur colonne de 80 valeurs
    gFk = ifft(FGk);
    % stockage dans la matrice finale
    gFilter(:,k) = gFk;
end

gFilter = gFilter';

figure(1);
colormap(gray);
imagesc(g);

figure(2);
colormap(gray);
imagesc(gFilter);



%%%%%%% Retro projection filtree %%%%%%%

N = 200;    % resolution de l'image
hs = 1 / ns;
dPhi = linspace(0,pi-(pi/nphi),nphi);   % discretisation de [0, pi] en 127 intervalle
dS = linspace(-1,1,ns);                  % discretisation de [-1 1] en 80 intervalle
cosphi = cos(dPhi);
sinphi = sin(dPhi);

A = zeros(N);   % creation de l'image a calculer

for x=1:N
    for y=1:N
        
        for j=1:nphi
            xn = ((x / N) * 2) - 1;
            yn = ((y / N) * 2) - 1;
            if (xn^2 + yn^2 < 1)
                S = xn * cosphi(j) + yn * sinphi(j);    % S : abscisse sur O(phi)
                %((S + 1) / 2.0) * 80;
                L = 1 + floor( ((S+1)/2) * 79);
                %L = 1 + floor((S + 1) * 2 / ns);
                %if (L == 80)
                %   v = gFilter(j,L);
                %else
                    a = gFilter(j,L);
                    b = gFilter(j,L+1);
                    t = (S - dS(L)) / hs;
                    v = (1-t) * a + t * b;
                %end
                
                A(x,y) = A(x,y) + v;
            end 
        end
        
    end
end

figure(3);
colormap(gray);
imagesc(A);



%contour(g,10); pause(1); surf(g); pause(1); mesh(g); pause(1);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% lecture des données médicales
% gmed = (load('data180x100'))';
% dimg = size(gmed);
% nphi = dimg(2);
% ns = dimg(1);
% figure(2)
% colormap(gray);
% imagesc(gmed);

