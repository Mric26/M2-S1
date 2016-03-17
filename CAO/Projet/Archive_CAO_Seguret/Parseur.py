
from PyQt4 import QtCore, QtGui
import random

def abs(x):
   return {True: x, False: -x}[x >= 0]

def writeTxt(chemin):
	#ecrit le fichier dans une chaine de caractere
	fichier = open(chemin,'r')
	text = str.join("", fichier.readlines())
	fichier.close()
	return text

def tableauFaces(text):
	#construit le tableau des faces du fichier brep associe en conservant l ordre
	surface = text[ text.find("Surfaces"):text.find("\nTriangulations") ] + "\n"
	surfaceTab = surface.split("\n")
	surfaceTab = surfaceTab[1:-1]
	return surfaceTab

def indiceSurfacePlane(surfaceTab):
	#recupere lindice de la surface plane
	compteur = 0
	for i in surfaceTab:
		if i[0] == "1":
			return compteur
		compteur = compteur + 1

def nbS(chemin):
	#recherche le nombre de Tshapes dans le fichier brep	
	fichier = open(chemin,'r')
	mot = "TShapes"
	for ligne in fichier:
		if mot in ligne:
			tab = ligne.split(" ")
			return int(tab[1])
	fichier.close();

def tableauShapes(text):
	#construit le tableau des shapes du fichier brep associe en conservant l ordre
	tshapes = text[ text.find("TShapes") : -1 ]
	tshapesTab = tshapes.split("*")
	i = 0
	for shape in tshapesTab:
		tshape = shape.split("\n")
		tshape = tshape[1:]
		tshapesTab[i] = tshape
		i = i+1
	return tshapesTab

def findShell(tshapesTab, nbShapes):
	if tshapesTab[nbShapes-1][0] == "Sh":
			return tshapesTab[nbShapes-1]
	else:
		for i in tshapesTab:
			if i[0] == "Sh":
				return i

def creationListeFaces(shell, tshapesTab, nbShapes):
	#construit la liste des faces
	lFacesShapes = (shell[len(shell)-2] + shell[len(shell)-1]).split(" 0 ")
	listF = []
	for i in lFacesShapes[0:-1]:
		listF.append( tshapesTab[ nbShapes - abs(int(i)) ] )
	return listF

def creationListeWiher(listF, tshapesTab, nbShapes):
	#construit la liste des wihers
	listW = []
	for i in listF:
		i = i[4].split(" 0 ")[0:-1]
		listt = []
		for j in i:
			listt.append( tshapesTab[ nbShapes - abs(int(j)) ] )
		listW.append(listt)
	return listW

def creationListeEdges(listW):
	#construit la liste des edges sans signes
	listE = []
	for i in listW:
		listt = []
		for j in i:
			listt.append( j[3].split(" 0 ")[0:-1 ] )
		listtt = []
		for k in listt:
			for l in k:
				l = l.replace('-','')
				l = l.replace('+','')
				listtt.append( l )
		listE.append(listtt)
	return listE

def creationListeEdgesPartage(indicePlane, listE):
	#construit la liste des arretes partages entre la face plane et les cylindres
	listEP = []
	for e in listE[indicePlane]:
		compteur = 0
		for i in listE:
			if compteur != indicePlane:
				if e in i:
					listEP.append(e)
			compteur = compteur + 1
	return listEP

def trouverCentres(listEP, tshapesTab, nbShapes):
	#construit la liste des centres des percages
	#1ere atape : recuperation des edges
	listV = []
	for e in listEP:
		e = tshapesTab[ nbShapes - int(e) ] 
		listVt = e[9].split(" 0 ")[0:2]
		coupleV = []
		for s in listVt:
			s = s.replace('-','')
			s = s.replace('+','')
			coupleV.append(int(s))
		coupleV.sort()
		if not( (coupleV in listV) ):
			listV.append(coupleV)
	#2eme atape : construction des milieux	
	listCentre = []
	for couple in listV:
		p1 = tshapesTab[ nbShapes - couple[0] ][2]
		p1 = p1.split(" ")
		p2 = tshapesTab[ nbShapes - couple[1] ][2]
		p2 = p2.split(" ")
		pres = []
		pres.append( (float(p1[0]) + float(p2[0])) / 2 )
		pres.append( (float(p1[1]) + float(p2[1])) / 2 )
		pres.append( (float(p1[2]) + float(p2[2])) / 2 )
		listCentre.append(pres)
	return listCentre

def tousSurMemePlan(liste):
	#verifie que tout les points de la liste sont sur le meme plan
	copieListeCentre = liste
	random.shuffle(copieListeCentre)
	A = copieListeCentre[0]
	B = copieListeCentre[1]
	C = copieListeCentre[2]
	AB = []
	AB.append( B[0] - A[0] )
	AB.append( B[1] - A[1] )
	AB.append( B[2] - A[2] )
	AC = []
	AC.append( C[0] - A[0] )
	AC.append( C[1] - A[1] )
	AC.append( C[2] - A[2] )
	equation = []
	equation.append( (AB[1]*AC[2]) - (AB[2]*AC[1]) )
	equation.append( (AB[2]*AC[0]) - (AB[0]*AC[2]) )
	equation.append( (AB[0]*AC[1]) - (AB[1]*AC[0]) )
	equation.append( -(( A[0] * equation[0] ) + ( A[1] * equation[1] ) + ( A[2] * equation[2] )) )

	for e in liste:
		verif = (e[0] * equation[0]) + (e[1] * equation[1]) + (e[2] * equation[2]) + equation[3]
		if verif != 0.0:
			return False
	
	return True

def isobarycentre(liste):
	#calcul le barycnetre d'une liste
	sommex = 0
	sommey = 0
	sommez = 0
	for e in liste:
		sommex = sommex + e[0]
		sommey = sommey + e[1]
		sommez = sommez + e[2]
	res = []
	nbElems = len(liste)
	res.append( sommex / nbElems )
	res.append( sommey / nbElems )
	res.append( sommez / nbElems )
	return res

def sqrt(nombre):
	#racine carre
	return nombre**0.5

def distance(p1, p2):
	#distance entre deux points
	x = (p1[0] - p2[0])**2.0
	y = (p1[1] - p2[1])**2.0
	z = (p1[2] - p2[2])**2.0
	return sqrt( x + y + z )

def distanceToutesEgales(b, liste):
	#verifie que tu les points de la liste sont equidistant de b
	epsilon = 0.00001
	d = distance(b, liste[0])
	for e in liste[1:]:
		dt = distance(b, e)
		if ( dt > (d+epsilon) ) or ( dt <  (d-epsilon) ):
			return False
	return True

######################################### Fonction principale ######################################### 

def parsage():
	import salome
	import SALOMEDS
	from salome.geom import geomBuilder
	geompy = geomBuilder.New(salome.myStudy)	
	
	chemin = str( QtGui.QFileDialog.getOpenFileName( directory="Z:\Documents\M2-S1\CAO\Projet\Data", filter="*.brep" ) )
	if not chemin:
		print "Il faut selectionner un fichier pour que ca marche"
	else:
		#ouverture pour affichage du brep
		compound = geompy.ImportBREP( chemin )
		gg = salome.ImportComponentGUI("GEOM")
		compound.SetColor(SALOMEDS.Color(0.5,0.5,0.5))
		
		#ecriture dans text
		text = writeTxt(chemin)
		
		#creation du tableau de faces avec ordre conserve
		surfaceTab = tableauFaces(text)
		
		#recuperation indice de la surface plane (identique par la suite)
		indicePlane = indiceSurfacePlane(surfaceTab)
		
		#nombre de shapes
		nbShapes = nbS(chemin)
		
		#creation du tableau des shapes
		tshapesTab = tableauShapes(text)
		
		#on trouve le shell
		shell = findShell(tshapesTab, nbShapes)
		
		#on cree la Liste des faces
		listF = creationListeFaces(shell, tshapesTab, nbShapes)

		#on cree la Liste des wihers
		listW = creationListeWiher(listF, tshapesTab, nbShapes)

		#on cree la Liste Edges
		listE = creationListeEdges(listW)

		#on cree la Liste Edges partages
		listEP = creationListeEdgesPartage(indicePlane, listE)
		
		#on cree la Liste des centres
		listCentre = trouverCentres(listEP, tshapesTab, nbShapes)
		
		#regarde pour symetrie
		if tousSurMemePlan(listCentre) == True:
			bar = isobarycentre(listCentre)
			if distanceToutesEgales(bar, listCentre) == True:
				print "Rotation possible"
		
		#affichage des centres
		for p in listCentre:
			p0 = geompy.MakeVertex(p[0], p[1]+1, p[2])
			p1 = geompy.MakeVertex(p[0], p[1]-1, p[2])
			p2 = geompy.MakeVertex(p[0], p[1], p[2]+1)
			p3 = geompy.MakeVertex(p[0], p[1], p[2]-1)
			line_1 = geompy.MakeLineTwoPnt(p0, p1)
			line_2 = geompy.MakeLineTwoPnt(p2, p3)
			p_inter = geompy.MakeVertexOnLinesIntersection(line_1, line_2)
			id_p_inter = geompy.addToStudy(p_inter, "Vertex on Lines Intersection")
			gg.createAndDisplayGO(id_p_inter)
		
		#affichage
		id_compound = geompy.addToStudy(compound, "Comp")
		gg.createAndDisplayGO(id_compound)
		salome.sg.updateObjBrowser(1)
