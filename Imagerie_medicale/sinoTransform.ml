open CamlToolsProg
open MathConst


(*integr fl->fl interMin interMax dx*)

(*une image est considéré comme une fonction qui va de [-1,1][-1,1] et au dela de cet intervale rempli de valeur 0*)
(*un sinogram est crée à partir d'un cercle de rayon r*)
(*toutes parties de l'image contenu en dehors de r sont considéré comme vallant 0*)
let to_parralel_sino (img:float->float->float) (r:float) (nbDiscrPhi:int) (nbProj:int) (nbIntegrDx:int)=
	(*transforme une fonction f R²->R vers sa tranformé de radon avec un cercle de rayon r en géométrie parralelle
	cette transformé de radon est une fonction définit sur [0,pi][-1,1]
	nbDiscrPhi, nbProj et nbIntegrDx sont des parametre permettant d'améliorer l'aproximation obtenue.
	plus ces valeurs sont élevé plus l'échantillonage est précis.
	*)
	let sino phi p=
		let rotImg=rotateFun img phi in
		(*p=x de la rot image et integrer pour y variant de -r à r*)
		(integr (rotImg (p*.r)) (-.r) (r) (1./.( float_of_int (nbIntegrDx) ) ))
	in
	sino
	
	
	
let to_parralel_sino2 (img:float->float->float) (r:float) (nbDiscrPhi:int) (nbProj:int) (nbIntegrDx:int)=
	(*
	fonction quasi identique à la précédente sauf que lors de l'intégration les valeurs d'absorbtion
	des pixel en dehors du cercle unitaire ont pour valeur 0
	*)
	let imgCercle x y=
			if (sqrt((x*.x) +. (y*.y))>r) then 0. else img x y
		in
	
	let sino phi p=
		let rotImg=rotateFun imgCercle phi in
		(*p=x de la rot image et integrer pour y variant de -r à r*)
		(integr (rotImg (p*.r)) (-.r) (r) (1./.( float_of_int (nbIntegrDx) ) ))
	in
	sino