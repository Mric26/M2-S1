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
A = zeros(nprojections, ndetecteurs);

para_hphi = pi / (nprojections-1);
para_phi = 0:para_hphi:pi;
para_hs = 2 / (ndetecteurs-1);
para_S = -1:para_hs:1;

fb_hphi = (2*pi) / (nprojections-1);
fb_phi = 0:fb_hphi:2*pi;
fb_halpha = (2*dfa) / (ndetecteurs-1);
fb_alpha = -dfa:fb_halpha:dfa;

for p = 1:nprojections
    pphi = para_phi(p);
    for n = 1:ndetecteurs
        s = para_S(n);
        
        fb_alpha = (2*pphi) - acos(s/R);
        fb_t = pphi + (pi/2) - fb_alpha;
        index_fb_phi_prev = 1 + floor( (fb_t - 0) / fb_hphi );
        index_fb_alpha_prev = 1 + floor( (fb_alpha - (-dfa)) / fb_halpha );
        
        coef_t = (fb_t - fb_phi(index_fb_phi_prev)) / fb_hphi;
        projection1 = derivativedata(index_fb_phi_prev,:);
        projection2 = derivativedata(index_fb_phi_prev+1,:);
        line_fb_phi = ((1.0 - coef_t) * projection1) + (coef_t * projection2);
        
        coef_alpha = (fb_alpha - fb_alpha(index_fb_alpha_prev)) / fb_halpha;
        interpole = ((1.0 - coef_alpha) * line_fb_phi(index_fb_alpha_prev)) + (coef_alpha * line_fb_phi(index_fb_alpha_prev+1));
    end
end



%% 
%%%%%%%%%%%%%%%%%%%%%%%% Backprojection %%%%%%%%%%%%%%%%%%%%%%%%
%hphi = (pi / (nprojections-1));
%phi = 0:hphi:pi;
cosphi = cos(para_phi);
sinphi = sin(para_phi);
%hs = 2 / (ndetecteurs-1);
%S = -1:hs:1;
% 
% N = 400;
% imgFinale = zeros(N);   % creation de l'image a calculer
% 
% figure('Name',' Backprojection ')
% colormap(gray);
% 
% for p=1:nprojections
%     for x=1:N
%         xn = ((x / N) * 2) - 1;
%         for y=1:N
%             yn = ((y / N) * 2) - 1;
%             if (xn^2 + yn^2 < 1)
%                 s = xn * cosphi(p) + yn * sinphi(p);            % S : abscisse sur O(phi)
%                 index_prev = 1 + floor( (s - (-1)) / hs );      % indice precedent s dans la tableau des abscisses
%                 alpha = (s - S(index_prev)) / hs;
%                 value = ((1-alpha) * derivativedata(p,index_prev)) + (alpha * derivativedata(p,index_prev+1));
%                 
%                 imgFinale(x,y) = imgFinale(x,y) + value;
%             end
%         end
%     end
%     imagesc(imgFinale);
%     drawnow;
% end
% 
% %figure('Name',' Backprojection ')
% %colormap(gray);
% %imagesc(imgFinale)
% 
% clear r N x y xn yn p S s L index_prev alpha value phi hphi cosphi sinphi;
% 
% %end
% 
