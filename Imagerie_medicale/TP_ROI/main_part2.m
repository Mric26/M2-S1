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
filename = 'data/dataFB384_2PIx125_SL';
nprojections = 384;
ndetecteurs = 125;
R = 3;

fbSino = litfbsinogramme(filename, nprojections, ndetecteurs);

figure('Name',' Sinograme ')
colormap(gray);
imagesc(fbSino);


%% 
%%%%%%%%%%%%%%%%%%%%%%%% Filtre de Hilbert %%%%%%%%%%%%%%%%%%%%%%%
%%% Calcul du filtre de Hilbert %%%
dfa = asin(1 / R);
halpha = (2 * dfa) / (ndetecteurs - 1);
freqcutoff = (1+R) * nprojections * 0.5;
%for freqcutoff = 80:100

HFilter = fbhilbertfilter(ndetecteurs, halpha, freqcutoff);
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

%%% Filtrage des projections
for p = 1:nprojections
    ftzpdata = fft(zpdata(p,:));
    filteredftzpdata = ftzpdata .* fft_HFilter;
    filteredzpdata(p,:) = real(ifft(filteredftzpdata));
end
filtereddata = filteredzpdata(:,1:ndetecteurs);

figure('Name',' Filtred Data ')
colormap(gray);
imagesc(filtereddata)

pause

clear p zpdata ftzpdata filteredftzpdata filteredzpdata;

%% 
%%%%%%%%%%%%%%%%%%%%%% Derivatative Data %%%%%%%%%%%%%%%%%%%%%
derivativedata = zeros(nprojections, ndetecteurs);
for d = 2:ndetecteurs-1
     fdata_prev = filtereddata(:,d-1);
     fdata_next = filtereddata(:,d+1);
     derivativedata(:,d) = (fdata_next - fdata_prev) / (2*halpha);
end
%derivativedata(:,1) = (filtereddata(:,2) - filtereddata(:,1)) / hs;
%derivativedata(:,ndetecteurs) = (filtereddata(:,ndetecteurs) - filtereddata(:,ndetecteurs-1)) / hs;
derivativedata = derivativedata / (2*pi);

figure('Name',' Derivative Data ')
colormap(gray);
imagesc(derivativedata)

clear d fdata_prev fdata_next;


%% 
%%%%%%%%%%%%%%%%%%% Remplissage en parallele %%%%%%%%%%%%%%%%%%%
% A = zeros(nprojections, ndetecteurs);
% 
% para_hphi = pi / (nprojections-1);
% para_phi = 0:para_hphi:pi;
% para_hs = 2 / (ndetecteurs-1);
% para_S = -1:para_hs:1;
% 
% fb_hphi = (2*pi) / (nprojections-1);
% fb_phi = 0:fb_hphi:2*pi;
% fb_halpha = (2*dfa) / (ndetecteurs-1);
% fb_alpha = -dfa:fb_halpha:dfa;
% 
% for p = 1:nprojections
%     t = fb_phi(p);
%     for n = 1:ndetecteurs
%         alpha = fb_alpha(n);
%         
%         phi = t - (pi/2) + alpha;
%         %s = -R * cos(t - phi);
%         s = -R * sin(alpha);
%         
%         index_para_phi_prev = 1 + floor( (phi - 0) / para_hphi );
%         index_para_s_prev = 1 + floor( (s - (-1)) / para_hs );
%         coef_phi = (phi - para_phi(index_para_phi_prev)) / para_hphi;
%         coef_s = (s - para_S(index_para_s_prev )) / para_hs;
%         
%         data = derivativedata(p,n);
%     end
% end

