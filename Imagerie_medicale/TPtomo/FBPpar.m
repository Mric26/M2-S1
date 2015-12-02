%construit sur la base de ce qui a été donné
clear all; close all;
nphi = 127;                                       % nombre de projections
ns = 80;                                          % nombre de translations  
g = litsinogramme('data127x80',nphi,ns);          % lecture des données simulées

%image de base
g = g';
figure('Name',' Image originale')
colormap('gray');
imagesc(g);

%%%%%%%%%%%%% image filtrée %%%%%%%%%%%%%
filter = [-ns/2:ns/2-1]';
filter = abs(filter);
filter = fftshift(filter);

figure('Name',' Graphe')
colormap('gray');
plot(-ns/2:ns/2-1,filter');

<<<<<<< HEAD
fg=fft(g);
Ffg=zeros(size(g));
for r=1:nphi
    %fg = fft(g(:,r));
=======
fg = fft(g);
Ffg = zeros(size(g));
for r = 1:nphi
>>>>>>> 3e894ed2df1ecf527ebe437aa434e54dbe34761a
    Ffg(:,r) = filter.*fg(:,r);   
end
gfiltered = ifft(Ffg);
max(max(imag(gfiltered)))
figure('Name',' Image filtrée')
colormap('gray');
imagesc(real(gfiltered));


%%%%%%%%%%%%% backprojection %%%%%%%%%%%%%
<<<<<<< HEAD
%precalcul cos/sin
for j = 1:nphi
    phi = j*pi/nphi;
    cosphi(j) = cos(phi);
    sinphi(j) = sin(phi);
end

%%calcul
imagemu = zeros(N);
N = nphi/2;
for m1 = 1:N
    for m2 = 1:N
        %calcul de imagemu(m1,m2)
        for k = 1:N
            imagemu(m1,m2) = 69;
        end
    end
end

=======
N = 200;                                                % resolution de l'image
hs = 1 / ns;
dPhi = linspace(0,pi-(pi/nphi),nphi);                   % discretisation de [0, pi] en 127 intervalle
dS = linspace(-1,1,ns);                                 % discretisation de [-1 1] en 80 intervalle
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
                L = 1 + floor( ((S+1)/2) * 79);
                a = gfiltered(L,j);
                b = gfiltered(L+1,j);
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

>>>>>>> 3e894ed2df1ecf527ebe437aa434e54dbe34761a
