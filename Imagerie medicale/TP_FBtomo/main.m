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

% Weighting


% Filtrage
%fbSLfilter1 = fbshepploganfilter(ndetecteurs1, halpha1, freqcutoff1);
%fbSLfilter2 = fbshepploganfilter(ndetecteurs2, halpha2, freqcutoff2);

%%%%%%%%%%%%
% Main end %
%%%%%%%%%%%%