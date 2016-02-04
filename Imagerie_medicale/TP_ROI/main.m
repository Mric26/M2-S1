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
freqcutoff = 124;%(1+r) * nprojections * 0.5;
HFilter = hilbertfilter(ndetecteurs, hs, freqcutoff);
fft_HFilter = fft( HFilter );

figure('Name',' Hilbert Filter ')
colormap(gray);
plot( fftshift(HFilter) )

clear freqcutoff;

%% 
%%%%%%%%%%%%%%%%%%%%%% Filtered Data %%%%%%%%%%%%%%%%%%%%%
%%% Zero padding %%%
zpdata = zeros(nprojections, 2*ndetecteurs-1);
zpdata(:,1:ndetecteurs) = fbSino;
filteredzpdata = zeros(nprojections,2*ndetecteurs-1);
%filtereddata = zeros(nprojections,ndetecteurs);

%%% Filtrage des projections
for p = 1:nprojections
    %zeropaddedproj = [fbSino(p,:) zeros(1,ndetecteurs-1)]; % zeropadding
    %paddedHproj = cconv(zeropaddedproj, HFilter, 2*ndetecteurs-1); % circular convolution
    %filtereddata(p,:) = paddedHproj(1:ndetecteurs); % unzeropadding

    ftzpdata = fft(zpdata(p,:));
    filteredftzpdata = ftzpdata .* fft_HFilter;
    filteredzpdata(p,:) = real(ifft(filteredftzpdata));
end
filtereddata = filteredzpdata(:,1:ndetecteurs);

figure('Name',' Filtred Data ')
colormap(gray);
imagesc(filtereddata)

clear p zpdata ftzpdata filteredftzpdata filteredzpdata;

%% 
%%%%%%%%%%%%%%%%%%%%%% Derivatative Data %%%%%%%%%%%%%%%%%%%%%
derivativedata = zeros(nprojections, ndetecteurs);
ds = 0.2;
for d = 2:ndetecteurs-1
    fdata_prev = ((1-ds) * filtereddata(:,d)) + (ds * filtereddata(:,d-1));
    fdata_next = ((1-ds) * filtereddata(:,d)) + (ds * filtereddata(:,d+1));
    derivativedata(:,d) = ((fdata_next - fdata_prev) / (2*hs));
%     fdata_prev = filtereddata(:,d-1);
%     fdata_next = filtereddata(:,d+1);
%     derivativedata(:,d) = (fdata_next - fdata_prev) / (2*hs);
end
derivativedata(:,1) = (filtereddata(:,2) - filtereddata(:,1)) / hs;
derivativedata(:,ndetecteurs) = (filtereddata(:,ndetecteurs) - filtereddata(:,ndetecteurs-1)) / hs;
derivativedata = derivativedata / (2*pi);

figure('Name',' Derivative Data ')
colormap(gray);
imagesc(derivativedata)

clear d fdata_prev fdata_next;

%% 
%%%%%%%%%%%%%%%%%%%%%%%% Backprojection %%%%%%%%%%%%%%%%%%%%%%%%
hphi = (2*pi / (nprojections-1));
phi = 0:hphi:2*pi;
cosphi = cos(phi);
sinphi = sin(phi);
arrayS = -1:hs:1;

N = nprojections;
imgFinale = zeros(N);   % creation de l'image a calculer

for x=1:N
    xn = ((x / N) * 2) - 1;
    for y=1:N
        yn = ((y / N) * 2) - 1;
        if (xn^2 + yn^2 < 1)
            for p=1:nprojections
                xn = ((x / N) * 2) - 1;
                yn = ((y / N) * 2) - 1;
                
                S = xn * cosphi(p) + yn * sinphi(p);    % S : abscisse sur O(phi)
                L = 1 + floor( ((S+1)/2) * (ndetecteurs-1));
                s_prev = derivativedata(p,L);
                s_next = derivativedata(p,L+1);
                alpha = (S - arrayS(L)) / hs;
                value = ((1-alpha) * s_prev) + (alpha * s_next);
                
                imgFinale(x,y) = imgFinale(x,y) + value;
            end
        end
    end
end

figure('Name',' Backprojection ')
colormap(gray);
imagesc(imgFinale)

clear r N x y xn yn p arrayS S L s_prev s_next alpha value phi hphi cosphi sinphi;



