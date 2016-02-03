%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%               Main - TP Fan bean geometry                       %
% Réalisé par                                                     %
%   * Henry Lefèvre - M2 MIA parcours GICAO                       %
%   * Seguret Aymeric - M2 MIA parcours GICAO                     %
% Dans le cadre des TP de gémétrie médicale                       %
%   à l'UFR IM2AG - 2015/16                                       %
%                                                                 %
% Description :                                                   %
%       Cette fonction permet de lancer le TP                     %
%       Elle traite les 2 images en simultannées                  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%% Nettoyage %%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all; close all;

%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%% Paramètres %%%%%%%%%%%%%%%%%%%%%%%%%%%
filename = 'dataFB384_2PIx125_SL';
%filename2 = 'dataFB192_PIx125_SL';
ndetecteurs = 125;
nprojections = 384;
r = 3;

fbSino = litfbsinogramme(filename, nprojections, ndetecteurs);

figure('Name',' Sinograme ')
colormap(gray);
imagesc(fbSino);


%% 
%%%%%%%%%%%%%%%%%%%%%%%% Filtre de Hilbert %%%%%%%%%%%%%%%%%%%%%%%
%%% Calcul du filtre de Hilbert %%%
hs = 2 / (ndetecteurs - 1);
freqcutoff = 1;%(1+r) * nprojections * 0.5;
HFilter = hilbertfilter(ndetecteurs, hs, freqcutoff);
HFilter = fftshift(HFilter);

figure('Name',' Hilbert Filter ')
colormap(gray);
plot(HFilter)

clear freqcutoff;

%% 
%%%%%%%%%%%%%%%%%%%%%% Filtered Data %%%%%%%%%%%%%%%%%%%%%
%%% Zero padding %%%
zpdata = zeros(nprojections, 2*ndetecteurs-1);
zpdata(:,1:ndetecteurs) = fbSino;
filteredzpdata = zeros(nprojections,2*ndetecteurs-1);

%%% Filtrage des projections
for r = 1:nprojections
    ftzpdata = fft(zpdata(r,:));
    filteredftzpdata = ftzpdata .* HFilter;
    filteredzpdata(r,:) = real(ifft(filteredftzpdata));
end
fdata = filteredzpdata(:,1:ndetecteurs);
fdata = fdata / (2*pi);

figure('Name',' Filtred Data ')
colormap(gray);
imagesc(fdata)

clear r zpdata ftzpdata filteredftzpdata filteredzpdata;

%% 
%%%%%%%%%%%%%%%%%%%%%% Derivatative Data %%%%%%%%%%%%%%%%%%%%%
derivativedata = zeros(nprojections, ndetecteurs);
ds = 0.1;
for d = 2:ndetecteurs-1
    fdata_prev = ((1-ds) * fdata(:,d)) + (ds * fdata(:,d-1));
    fdata_next = ((1-ds) * fdata(:,d)) + (ds * fdata(:,d+1));
    derivativedata(:,d) = (fdata_next - fdata_prev) / (2*ds);
end
derivativedata(:,1) = derivativedata(:,2);
derivativedata(:,ndetecteurs) = derivativedata(:,ndetecteurs-1);

figure('Name',' Derivative Data ')
colormap(gray);
imagesc(derivativedata)

clear d ds fdata_prev fdata_next;

%% 
%%%%% Back Projection %%%%

%%%%%%%%%%%%%%%%%%%%%%%% Backprojection 2 %%%%%%%%%%%%%%%%%%%%%%%%
hphi = (2*pi / (nprojections-1));
phi = 0:hphi:2*pi;
cosphi = cos(phi);
sinphi = sin(phi);
arrayS = -1:hs:1;

N = 100;
imgFinale = zeros(N);   % creation de l'image a calculer

for x=1:N
    xn = ((x / N) * 2) - 1;
    for y=1:N
        yn = ((y / N) * 2) - 1;
        if (xn^2 + yn^2 < 1)
            for j=1:nprojections
                xn = ((x / N) * 2) - 1;
                yn = ((y / N) * 2) - 1;
                
                S = xn * cosphi(j) + yn * sinphi(j);    % S : abscisse sur O(phi)
                L = 1 + floor( ((S+1)/2) * (ndetecteurs-1));
                s_prev = fdata(j,L);
                s_next = fdata(j,L+1);
                alpha = (S - arrayS(L)) / hs;
                value = ((1-alpha) * s_prev) + (alpha * s_next);
                
                imgFinale(x,y) = imgFinale(x,y) + value;
            end
        end
    end
end

figure('Name',' Backprojection 2 ', 'position', [1200, 400, 500, 500])
colormap(gray);
imagesc(imgFinale)


clear Reso x y j xn yn S L s_prev s_next alpha value cosphi sinphi;



