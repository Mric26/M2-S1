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

fg=fft(g);
Ffg=zeros(size(g));
for r=1:nphi
    %fg = fft(g(:,r));
    Ffg(:,r) = filter.*fg(:,r);   
end
gfiltered = ifft(Ffg);
max(max(imag(gfiltered)))
figure('Name',' Image filtrée')
colormap('gray');
imagesc(real(gfiltered));


%%%%%%%%%%%%% backprojection %%%%%%%%%%%%%
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

