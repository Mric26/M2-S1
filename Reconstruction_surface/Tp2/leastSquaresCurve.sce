function mc(fitType,inputs,plotres,jpgfilename)
  nargin = argn(2);
  
  if nargin<3 then plotres = 1;end
  if nargin<2 then inputs  = 1;end
  if nargin<1 then fitType = 1;end
  rand('seed',0) 
  if inputs==2 then
    // quadrique
    a = -1.3;
    b = 0;
    c = 2;
    x = linspace(-25,25,50);
    y = a.*x^2+b.*x+c+rand(1,50)*200-100;
  elseif inputs==3 then 
    // cubique
    a = 1.3;
    b = 2;
    c = 1;
    d = 1;
    x = linspace(-25,25,50);
    y = a.*x^3+b.*x^2+c.*x+d+rand(1,50)*5000-2500;
  else
    // droite
    a = 1.3;
    b = 2;
    x = linspace(-25,25,50);
    y = a.*x+b+rand(1,50)*20-10;
  end
  
  scf();
  plot(x,y,'ro');
  
  if plotres then 
    if fitType==3 then
      c  = mcCubique(x,y);
    elseif fitType==2 then 
      c  = mcQuadrique(x,y);
    else
      c  = mcDroite(x,y);
    end
    
    xx = linspace(min(x),max(x),1000);
    yy = evalPoly(xx,c);
    plot(xx,yy,'b-','linewidth',3);
  end
  
  a = gca();
  a.data_bounds = [min(x)-1,min(y)-1;max(x)+1,max(y)+1];
  f = gcf();
  f.anti_aliasing = "16x"; 
  
  if nargin>=4 then
    xs2jpg(f, jpgfilename);
  end
endfunction

function c = mcDroite(x,y)
  // entrées 
  // x et y -> les abcisses et ordonnées des points que l'on cherche à approcher
  
  // sorties 
  // c = [a,b] -> les coeficients de la droite obtenue, tels que y=ax+b
  
  // **** A MODIFIER/COMPLETER ****
  n = size(x,2);                    // nombre de colonnes de x
  one = ones(n,1);                  // vecteur de 1
  A = matrix([x';one],n,2);         // creation de la matrice A
  c = inv(A' * A) * A' * y';        // solution au sens des moindre carres
  // ******************************
  
endfunction

function c = mcQuadrique(x,y)
  // entrées 
  // x et y -> les abcisses et ordonnées des points que l'on cherche à approcher
  
  // sorties 
  // c = [a,b,c] -> les coeficients de la quadrique obtenue, tels que y=ax^2+bx+c
  // **** A MODIFIER/COMPLETER ****
  line = size(x,2);                    // nombre de colonnes de x
  one = ones(line,1);                  // vecteur de 1
  x2 = (x').^2;
  A = matrix([x2;x';one], line, 3);    // creation de la matrice A
  c = inv(A' * A) * A' * y';           // solution au sens des moindre carres
  // ******************************
  
endfunction

function c = mcCubique(x,y)
  // entrées 
  // x et y -> les abcisses et ordonnées des points que l'on cherche à approcher
  
  // sorties 
  // c = [a,b,c,d] -> les coeficients de la cubique obtenue, tels que y=ax^3+bx^2+cx+d
  
  // **** A MODIFIER/COMPLETER ****
  line = size(x,2);                       // nombre de colonnes de x
  one = ones(line,1);                     // vecteur de 1
  x3 = (x').^3;
  x2 = (x').^2;
  A = matrix([x3;x2;x';one], line, 4);    // creation de la matrice A
  c = inv(A' * A) * A' * y';              // solution au sens des moindre carres
  // ******************************
  
endfunction

function y = evalPoly(x,c)
  d = length(c);
  y = zeros(x);
  for i=1:d
    y = y+x.^(d-i).*c(i);
  end
endfunction

