
from PyQt4 import QtCore, QtGui

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
		tshape = shape.split("\r\n")		######## ATTENTION LE \r SOUS LINUX ET NON WINDOWS ########
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
		
		#affichage
		id_compound = geompy.addToStudy(compound, "Comp")
		gg.createAndDisplayGO(id_compound)
		salome.sg.updateObjBrowser(1)
