%construit sur la base de ce qui a �t� donn�
clear all; close all;
nphi = 180;                                       % nombre de projections
ns = 100;                                          % nombre de translations  

g = litsinogramme('data127x80',nphi,ns);          % lecture des donn�es simul�es

%image de base
g = g';
figure('Name',' Image originale')
colormap('gray');
imagesc(g);

%%%%%%%%%%%%% image filtr�e %%%%%%%%%%%%%
filter = [-ns/2:ns/2-1]';
filter = abs(filter);
filter = fftshift(filter);

figure('Name',' Graphe')
colormap('gray');
plot(-ns/2:ns/2-1,filter');

fg=fft(g);
Ffg=zeros(size(g));
for r=1:nphi
    Ffg(:,r) = filter.*fg(:,r);   
end
gfiltered = ifft(Ffg);
max(max(imag(gfiltered)))
figure('Name',' Image filtr�e')
colormap('gray');
imagesc(real(gfiltered));


%%%%%%%%%%%%% backprojection %%%%%%%%%%%%%
N = 400;                                                % resolution de l'image
hs = 2 / (ns-1);
hphi = pi / (nphi-1);
dPhi = 0:hphi:pi;                                       % discretisation de [0, pi] en 127 intervalle
dS = -1:hs:1;                                           % discretisation de [-1 1] en 80 intervalle
cosphi = cos(dPhi);
sinphi = sin(dPhi);

A = zeros(N);                                           % creation de l'image a calculer

for x=1:N
    for y=1:N
        
        for j=1:nphi
            xn = ((x / N) * 2) - 1;
            yn = ((y / N) * 2) - 1;
            if (xn^2 + yn^2 < 1)
                S = xn * cosphi(j) + yn * sinphi(j);    % S : abscisse sur O(phi)
                L = 1 + floor( (S - (-1)) / hs );
                %L = 1 + floor( ((S+1)/2) * 79);
                a = g(L,j);
                b = g(L+1,j);
                t = (S - dS(L)) / hs;
                v = (1-t) * a + t * b;
                A(x,y) = A(x,y) + v;
            end 
        end
        
    end
end

figure('Name',' Resultat FBP ')
colormap(gray);
imagesc(A);
