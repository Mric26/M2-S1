
clear all;
close all;

%% Import data from text file.
% Script for importing data from the following text file:
%
%    /user/0/.base/lefevreh/home/Documents/Modelisation_Scientifique/Data/synop.2015110912.csv
%
% To extend the code to different selected data or a different text file,
% generate a function instead of a script.

% Auto-generated by MATLAB on 2015/11/09 16:53:31

%% Initialize variables.
%filename = '/user/0/.base/lefevreh/home/Documents/Modelisation_Scientifique/Data/synop.2015110912.csv';
filename = fullfile(pwd,'/Data/synop.2015110912.csv');
delimiter = ';';

%% Read columns of data as strings:
% For more information, see the TEXTSCAN documentation.
formatSpec = '%s%*s%*s%*s%*s%*s%*s%s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%s%[^\n\r]';

%% Open the text file.
fileID = fopen(filename,'r');

%% Read columns of data according to format string.
% This call is based on the structure of the file used to generate this
% code. If an error occurs for a different file, try regenerating the code
% from the Import Tool.
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter,  'ReturnOnError', false);

%% Close the text file.
fclose(fileID);

%% Convert the contents of columns containing numeric strings to numbers.
% Replace non-numeric strings with NaN.
raw = repmat({''},length(dataArray{1}),length(dataArray)-1);
for col=1:length(dataArray)-1
    raw(1:length(dataArray{col}),col) = dataArray{col};
end
numericData = NaN(size(dataArray{1},1),size(dataArray,2));

for col=[1,2,3]
    % Converts strings in the input cell array to numbers. Replaced non-numeric
    % strings with NaN.
    rawData = dataArray{col};
    for row=1:size(rawData, 1);
        % Create a regular expression to detect and remove non-numeric prefixes and
        % suffixes.
        regexstr = '(?<prefix>.*?)(?<numbers>([-]*(\d+[\,]*)+[\.]{0,1}\d*[eEdD]{0,1}[-+]*\d*[i]{0,1})|([-]*(\d+[\,]*)*[\.]{1,1}\d+[eEdD]{0,1}[-+]*\d*[i]{0,1}))(?<suffix>.*)';
        try
            result = regexp(rawData{row}, regexstr, 'names');
            numbers = result.numbers;
            
            % Detected commas in non-thousand locations.
            invalidThousandsSeparator = false;
            if any(numbers==',');
                thousandsRegExp = '^\d+?(\,\d{3})*\.{0,1}\d*$';
                if isempty(regexp(thousandsRegExp, ',', 'once'));
                    numbers = NaN;
                    invalidThousandsSeparator = true;
                end
            end
            % Convert numeric strings to numbers.
            if ~invalidThousandsSeparator;
                numbers = textscan(strrep(numbers, ',', ''), '%f');
                numericData(row, col) = numbers{1};
                raw{row, col} = numbers{1};
            end
        catch me
        end
    end
end


%% Replace non-numeric cells with NaN
R = cellfun(@(x) ~isnumeric(x) && ~islogical(x),raw); % Find non-numeric cells
raw(R) = {NaN}; % Replace non-numeric cells

%% Allocate imported array to column variable names
numer_sta = cell2mat(raw(:, 1));
t = cell2mat(raw(:, 2));
pres = cell2mat(raw(:, 3));

%% Clear temporary variables
clearvars filename delimiter formatSpec fileID dataArray ans raw col numericData rawData row regexstr result numbers invalidThousandsSeparator thousandsRegExp me R;


%% Extraction des donn�es pour lesquelle on a une coordonn�e g�ographique

% importation de la table de positions geographiques
m = importFile(fullfile(pwd,'/postesSynop.csv'));

setId = m(:,1);
indices = [];

% Extraction des indices n�cessaires
for k=1:size(setId,1)
    id = find(numer_sta == setId(k));
    if (id ~= 0)
        indices = [indices; id];
    end
end

numer_sta = numer_sta(indices);
pres = pres(indices);
t = t(indices);

% latitude = m(indices,3);
% longitude = m(indices,4);
% altitude = m(indices,5);
m = m(indices,:);


%% Interpolation des donn�es sur une grille r�guli�re

nb = size(indices,1);  % Nombre de donnees acquises
N = 10;    % Echantillonnage de la grille
mu = 2;     % Coefficient de l'interpolant

u = linspace(0,1,N);
v = linspace(0,1,N);

minX = min(m(:,3));
maxX = max(m(:,3));
minY = min(m(:,4));
maxY = max(m(:,4));

interpoleShepard = zeros(N,N);

for i=1:N
    for j=1:N
        X = minX + u(i) * (maxX - minX);
        Y = minY + v(j) * (maxY - minY);
        iii = [X Y];
        
        % Interpolation de la temperature
        eval = 0;
        for k=1:nb
            xk = [m(k,3) m(k,4)];
            
            % Calcul de wk
            s = 0;
            for l=1:nb
                xl = [m(l,3) m(l,4)];
                s = s + (1/(distance(iii, xl) ^ mu));
            end
            wk = (1 / (distance(iii, xk) ^ mu)) * (1 / s);
            
            eval = eval + (wk * t(k));
        end
        
        interpoleShepard(i,j) = eval;
    end
end

clear X Y iii eval xk wk xl s i j k l;

% Calcul de la colormap

mini = min(min(interpoleShepard));
maxi = max(max(interpoleShepard));

% Ensemble de valeurs des isocontours
lambda = [];
table = zeros(N-1,N-1);
lambda(1) = 290.0;

% Parcourt des rectangles pour determiner leur etat
for k=1:length(lambda)
    elem = lambda(k);
    for i=1:(N-1)
        for j=1:(N-1)
            v1 = (interpoleShepard(i,j) >= elem);
            v2 = (interpoleShepard(i,j+1) >= elem);
            v3 = (interpoleShepard(i+1,j+1) >= elem);
            v4 = (interpoleShepard(i+1,j) >= elem);
            bit = v1 + (v2 * 2) + (v3 * 4) + (v4 * 8);
            table(i,j) = bit;
        end
    end
end


% Tableau des segments presents dans chaque case de la grille
%   premier entier : nombre de segments
%   ensemble de 4 entiers : un segment
segTable = zeros(N-1,N-1,9);

% Remplissage de la segTable
for k=1:length(lambda)
    for i=1:(N-1)
        for j=1:(N-1)
            switch table(i,j)
                case 1
                    % haut gauche
                    segTable(i,j,0) = 1;
                    alpha1 = (lambda(k) - table(i,j)) / (table(i,j+1) - table(i,j));
                    alpha2 = (lambda(k) - table(i,j)) / (table(i+1,j) - table(i,j));
                case 2
                    % haut droite
                    segTable(i,j,0) = 1;
                case 3
                    % horizontal
                case 4
                    % bas droite
                    segTable(i,j,0) = 1;
                case 5
                    % cas casse co...ille
                case 6
                    % vertical
                case 7
                    % bas gauche
                    segTable(i,j,0) = 1;
                case 8
                    % bas gauche
                    segTable(i,j,0) = 1;
                case 9
                    %vertical
                case 10
                    % cas casse co...ille
                case 11
                    % bas droite
                    segTable(i,j,0) = 1;
                case 12
                    %horizontal
                case 13
                    % haut droite
                    segTable(i,j,0) = 1;
                case 14
                    % haut gauche
                    segTable(i,j,0) = 1;
            end
        end
    end
end

