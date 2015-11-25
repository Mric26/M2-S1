%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%               Main - TP Fan bean geometry                   %
% Réalisé par                                                 %
%   * Henry Lefèvre - M2 MIA parcours GICAO                   %
%   * Seguret Aymeric - M2 MIA parcours GICAO                 %
% Dans le cadre des TP de gémétrie médicale                   %
%   à l'UFR IM2AG - 2015/16                                   %
%                                                             %
% Description :                                               %
%   Cette fonction permet de lancer le TP                     %
%                                                             %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Nettoyage
clear all; close all;

% Paramètres
filename1 = 'dataFB384x125_SL';
ndetecteurs1 = 125;
nprojections1 = 384;
r1 = 3;

filename2 = 'dataFBR3_128x41_Disk';
ndetecteurs2 = 41;
nprojections2 = 128;
r2 = 3;

% Lecture des donnée & Affichage
fbsino1 = litfbsinogramme(filename1, nprojections1, ndetecteurs1);
figure('Name',' Sinograme 1 ')
colormap(gray);
imagesc(fbsino1);
xlabel('Pan Axis    or   Detector Axis')
ylabel('Projection   or   Source Position Number')

fbsino2 = litfbsinogramme(filename2, nprojections2, ndetecteurs2);
figure('Name',' Sinograme 2 ')
colormap(gray);
imagesc(fbsino2);
xlabel('Pan Axis    or   Detector Axis')
ylabel('Projection   or   Source Position Number')

% Ponderation des donnees
demifanangle1 = asin(1./r1);
halpha1 = 2 * demifanangle1 / (ndetecteurs1 - 1);
hpsi1 = halpha1;
psi1 = -demifanangle1:hpsi1:demifanangle1+hpsi1/100;

demifanangle2 = asin(1./r2);
halpha2 = 2 * demifanangle2 / (ndetecteurs2 - 1);
hpsi2 = halpha2;
psi2 = -demifanangle2:hpsi2:demifanangle2+hpsi1/100;

% Weighting
cospsi1 = r1 * cos(psi1);
cospsi2 = r2 * cos(psi2);

% Ponderation sur chaque projection
WFBsino1 = zeros(nprojections1, ndetecteurs1);
for k=1:nprojections1
    WFBsino1(k,:) = fbsino1(k,:) .* cospsi1(1,:);
end
figure('Name',' Weighting 1 ')
colormap(gray);
imagesc(WFBsino1);

WFBsino2 = zeros(nprojections2, ndetecteurs2);
for k=1:nprojections2
    WFBsino2(k,:) = fbsino2(k,:) .* cospsi2(1,:);
end
figure('Name',' Weighting 2 ')
colormap(gray);
imagesc(WFBsino2);

% Filtrage
freqcutoff1 = (1+r1) * nprojections1 * 0.5;
fbSLfilter1 = fbshepploganfilter(ndetecteurs1, halpha1, freqcutoff1);
figure('Name',' Fonction 1 ')
xalpha1 = -ndetecteurs1 * hpsi1:hpsi1:ndetecteurs1*hpsi1;
plot(xalpha1, fftshift(fbSLfilter1))

freqcutoff2 = (1+r2) * nprojections2 * 0.5;
fbSLfilter2 = fbshepploganfilter(ndetecteurs2, halpha2, freqcutoff2);
figure('Name',' Fonction 2 ')
xalpha2 = -ndetecteurs2 * hpsi2:hpsi2:ndetecteurs2*hpsi2;
plot(xalpha2, fftshift(fbSLfilter2))

%%%%%%%%%%%%
% Main end %
%%%%%%%%%%%%