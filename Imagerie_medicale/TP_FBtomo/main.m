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

%%%%%%%%%%%%%%%%%%%%%%%%%%%% Paramètres %%%%%%%%%%%%%%%%%%%%%%%%%%%
filename1 = 'dataFB384x125_SL';
ndetecteurs1 = 125;
nprojections1 = 384;
r1 = 3;

filename2 = 'dataFBR3_128x41_Disk';
ndetecteurs2 = 41;
nprojections2 = 128;
r2 = 3;

%%%%%%%%%%%%%%%%%% Lecture des données & Affichage %%%%%%%%%%%%%%%%%
fbsino1 = litfbsinogramme(filename1, nprojections1, ndetecteurs1);
figure('Name',' Sinograme 1 ', 'position', [400, 400, 550, 400])
colormap(gray);
imagesc(fbsino1);
xlabel('Pan Axis    or   Detector Axis')
ylabel('Projection   or   Source Position Number')

fbsino2 = litfbsinogramme(filename2, nprojections2, ndetecteurs2);
figure('Name',' Sinograme 2 ', 'position', [1200, 400, 200, 500])
colormap(gray);
imagesc(fbsino2);
xlabel('Pan Axis    or   Detector Axis')
ylabel('Projection   or   Source Position Number')

%%%%%%%%%%%%%%%%%%%%% Ponderation des donnees %%%%%%%%%%%%%%%%%%%%%
dfa1 = asin(1./r1);
hpsi1 = 2 * dfa1 / (ndetecteurs1 - 1);
psi1 = -dfa1:hpsi1:dfa1+hpsi1/100;
cospsi1 = r1 * cos(psi1);
hphi1 = (2*pi / (nprojections1-1));
phi1 = 0:hphi1:2*pi;
cosphi1 = cos(phi1);
sinphi1 = sin(phi1);

dfa2 = asin(1./r2);
hpsi2 = 2 * dfa2 / (ndetecteurs2 - 1);
psi2 = -dfa2:hpsi2:dfa2+hpsi1/100;
cospsi2 = r2 * cos(psi2);
hphi2 = (2*pi / (nprojections2-1));
phi2 = 0:hphi2:2*pi;
cosphi2 = cos(phi2);
sinphi2 = sin(phi2);

%%%%%%%%%%%%%%%% Ponderation sur chaque projection %%%%%%%%%%%%%%%%
WFBsino1 = zeros(nprojections1, ndetecteurs1);
for k=1:nprojections1
    WFBsino1(k,:) = fbsino1(k,:) .* cospsi1(1,:);
end
figure('Name',' Weighting 1 ', 'position', [400, 400, 550, 400])
colormap(gray);
imagesc(WFBsino1);

WFBsino2 = zeros(nprojections2, ndetecteurs2);
for k=1:nprojections2
    WFBsino2(k,:) = fbsino2(k,:) .* cospsi2(1,:);
end
figure('Name',' Weighting 2 ', 'position', [1200, 400, 200, 500])
colormap(gray);
imagesc(WFBsino2);

%%%%%%%%%%%%%%%%%%%%%%%%%%%% Filtrage %%%%%%%%%%%%%%%%%%%%%%%%%%%%
freqcutoff1 = (1+r1) * nprojections1 * 0.5;
fbSLfilter1 = fbshepploganfilter(ndetecteurs1, hpsi1, freqcutoff1);
figure('Name',' Filtre 1 ', 'position', [400, 400, 550, 400])
xalpha1 = -ndetecteurs1 * hpsi1:hpsi1:ndetecteurs1*hpsi1;
fftFbSLfilter1 = fft(fbSLfilter1);
plot(xalpha1, real(fftFbSLfilter1))

zpwdata1 = zeros(nprojections1, 2*ndetecteurs1+1);
zpwdata1(:,1:ndetecteurs1) = WFBsino1;
% initialisation
filteredzpwdata1 = zeros(nprojections1,2*ndetecteurs1+1);
% data zero padding
for r = 1:nprojections1
    ftzpwdata1 = fft(zpwdata1(r,:));
    filteredftzpwdata1 = ftzpwdata1 .* fftFbSLfilter1;
    filteredzpwdata1(r,:) = real(ifft(filteredftzpwdata1));
end
filteredwdata1 = filteredzpwdata1(:,1:ndetecteurs1);

figure('Name',' Filtred 1 ', 'position', [400, 400, 550, 400])
colormap(gray);
imagesc(filteredwdata1)

%%donnée2%%
freqcutoff2 = (1+r2) * nprojections2 * 0.5;
fbSLfilter2 = fbshepploganfilter(ndetecteurs2, hpsi2, freqcutoff2);
figure('Name',' Filtre 2 ', 'position', [1200, 400, 550, 400])
xalpha2 = -ndetecteurs2 * hpsi2:hpsi2:ndetecteurs2*hpsi2;
fftFbSLfilter2 = fft(fbSLfilter2);
plot(xalpha2, fftFbSLfilter2)

zpwdata2 = zeros(nprojections2, 2*ndetecteurs2+1);
zpwdata2(:,1:ndetecteurs2) = WFBsino2;
% initialisation
filteredzpwdata2 = zeros(nprojections2,2*ndetecteurs2+1);
% data zero padding
for r = 1:nprojections2
    ftzpwdata2 = fft(zpwdata2(r,:));
    filteredftzpwdata2 = ftzpwdata2 .* fftFbSLfilter2;
    filteredzpwdata2(r,:) = real(ifft(filteredftzpwdata2));
end
filteredwdata2 = filteredzpwdata2(:,1:ndetecteurs2);

figure('Name',' Filtred 2 ', 'position', [1200, 400, 200, 500])
colormap(gray);
imagesc(filteredwdata2)

%%%%%%%%%%%%%%%%%%%%%%%% Backprojection 1 %%%%%%%%%%%%%%%%%%%%%%%%
Reso = 400;        % resolution de l'image
res1 = zeros(Reso);   % creation de l'image a calculer

for x=1:Reso
    xn = ((x / Reso) * 2) - 1;
    for y=1:Reso
        yn = ((y / Reso) * 2) - 1;
        if (xn^2 + yn^2 < 1)
            for j=1:nprojections1
                % Changement de base dans (teta, zeta)
                xTeta1 = (xn * cosphi1(j)) + (yn * sinphi1(j));           % xTeta : abscisse de (xn,yn) sur teta(phi)
                yZeta1 = (xn * -sinphi1(j)) + (yn * cosphi1(j));          % yZeta : ordonnee de (xn,yn) sur zeta(phi)
                dist_xy1 = sqrt(((xTeta1+r1) * (xTeta1+r1)) + (yZeta1 * yZeta1));     % distance du pixel par rapport a l'origine (teta,zeta)
                
                
                radian1 = acos((xTeta1+r1) / dist_xy1);   % radian compris entre [0 dfa]
                if (yZeta1 < 0)               % ajustement du signe en fonction de l'orientation par rapport à zeta
                    radian1 = -radian1;       % radian compris entre [-dfa dfa]
                end
                
                L = 1 + floor( (radian1 + dfa1) / hpsi1 );
                if (L == ndetecteurs1)
                    L = ndetecteurs1-1;
                end
                
                a = filteredwdata1(j,L);
                b = filteredwdata1(j,L+1);
                
                %r = (radian - psi(L)) / hpsi;  % acces a psi(L) tres long ...
                r = (radian1 - (-dfa1 + (L-1)*hpsi1)) / hpsi1;
                res1(x,y) = res1(x,y) + ((1-r)*a + r*b);      % accumulation dans l'image finale
            end 
        end
        
    end
end

figure('Name',' Backprojection 1 ', 'position', [400, 400, 550, 400])
colormap(gray);
imagesc(res1)

%%%%%%%%%%%%%%%%%%%%%%%% Backprojection 2 %%%%%%%%%%%%%%%%%%%%%%%%
res2 = zeros(Reso);   % creation de l'image a calculer

for x=1:Reso
    xn = ((x / Reso) * 2) - 1;
    for y=1:Reso
        yn = ((y / Reso) * 2) - 1;
        if (xn^2 + yn^2 < 1)
            for j=1:nprojections2
                % Changement de base dans (teta, zeta)
                xTeta2 = (xn * cosphi2(j)) + (yn * sinphi2(j));           % xTeta : abscisse de (xn,yn) sur teta(phi)
                yZeta2 = (xn * -sinphi2(j)) + (yn * cosphi2(j));          % yZeta : ordonnee de (xn,yn) sur zeta(phi)
                dist_xy2 = sqrt(((xTeta2+r2) * (xTeta2+r2)) + (yZeta2 * yZeta2));     % distance du pixel par rapport a l'origine (teta,zeta)
                
                
                radian2 = acos((xTeta2+r2) / dist_xy2);   % radian compris entre [0 dfa]
                if (yZeta2 < 0)               % ajustement du signe en fonction de l'orientation par rapport à zeta
                    radian2 = -radian2;       % radian compris entre [-dfa dfa]
                end
                
                L = 1 + floor( (radian2 + dfa2) / hpsi2 );
                if (L == ndetecteurs2)
                    L = ndetecteurs2-1;
                end
                
                a = filteredwdata2(j,L);
                b = filteredwdata2(j,L+1);
                
                %r = (radian - psi(L)) / hpsi;  % acces a psi(L) tres long ...
                r = (radian2 - (-dfa2 + (L-1)*hpsi2)) / hpsi2;
                res2(x,y) = res2(x,y) + ((1-r)*a + r*b);      % accumulation dans l'image finale
            end 
        end
        
    end
end

figure('Name',' Backprojection 2 ', 'position', [1200, 400, 500, 500])
colormap(gray);
imagesc(res2)


%%%%%%%%%%%%
% Main end %
%%%%%%%%%%%%