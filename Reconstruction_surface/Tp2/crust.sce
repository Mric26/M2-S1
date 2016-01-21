function Crust(S)
  // **** A MODIFIER/COMPLETER ****
  // R should contain a list of pair of indices connecting the initial points in S
  // for instance: 
  // R = [R ; [1,2]] adds the edge connecting points 1 and 2 in the array R
  R = [];
  
  // Triangle de Delaunay sur les sommets initiaux
  [T,C,r] = delaunay(S);
  
  // Trianglulation de Delaunay sur les sommets + les centres des cercles
  SP = cat(1,S,C);
  [T,C,r] = delaunay(SP);
  
  nbS = size(S,1);
  // Parcours des triangles
  for i = 1:size(T,1);
      i1 = T(i,1);
      i2 = T(i,2);
      i3 = T(i,3);
      
      // Construction de R si les segments appartiennent aux points d'origines
      if (i1 <= nbS & i2 <= nbS)  then
          R = [R ; [i1 i2]];
      elseif (i1 <= nbS & i3 <= nbS) then
          R = [R ; [i1 i3]];
      elseif (i2 <= nbS & i3 <= nbS) then
          R = [R ; [i2 i3]];
      end
  end
  // ******************************
  
  
  // nouvelle figure 
  scf();
  
  // affichage des points en entrée
  plot(S(:,1),S(:,2),'ro');
  
  // affichage des connections
  for i=1:size(R,1)
    plot([S(R(i,1),1);S(R(i,2),1)],[S(R(i,1),2);S(R(i,2),2)],'b-');
  end
  for i=1:size(T,1)
    plot([S(T(i,1),1);S(T(i,2),1)],[S(T(i,1),2);S(T(i,2),2)],'b-');
  end
  
  set(gca(),"auto_clear","off")
  set(gca(),"margins",[0.05 , 0.05 , 0.05 , 0.05])
  set(gca(),"box","off")
  set(gca(),"isoview","on")
  set(gca(),"auto_scale","on")
endfunction


function test_crust(num_test)
  //exec("qdelaunay.sce",-1);
  
  if argn(2)<1
    num_test=0;
  end
  select num_test
  case 1
    // // test 1
    // les donnees
    S = [0 0; 2 0; 4 0; 0 2; 1 2; 3 2; 2 3];
    Crust(S);
  case 2 then
    // // test 2 − points aleatoires
    S = rand(100,2);
    Crust(S);
  case 3 then
    // // test 3 − points suivant une grille reguliere
    S = zeros(100,2);
    for i =0:9
      for j =1:10
        S(i*10+j,:) = [2*j+i 2*i];
      end
    end
    Crust(S);
  case 4 then
    // // test 4 − points entres à la souris
    S = inputpoints()';
    Crust(S);
    
  end // select
endfunction
