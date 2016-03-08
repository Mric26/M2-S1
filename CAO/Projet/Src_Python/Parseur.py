
from PyQt4 import QtCore, QtGui

def parsage():
	import salome
	import SALOMEDS
	from salome.geom import geomBuilder
	geompy = geomBuilder.New(salome.myStudy)	
	
	chemin = str( QtGui.QFileDialog.getOpenFileName( directory="Z:\Documents\M2-S1\CAO\Projet\Data", filter="*.brep" ) )
	if not chemin:
		print "Il faut selectionner un fichier pour que ca marche"
	else:
		#ouverture et affichage brep
		compound = geompy.ImportBREP( chemin )
		gg = salome.ImportComponentGUI("GEOM")
		compound.SetColor(SALOMEDS.Color(0.5,0.5,0.5))
		
		#ouverture fichier et ecriture dans text
		file = open(chemin,'r')
		text = str.join("", file.readlines())
		file.close()
		
		#explosion en faces
		listFaces = geompy.SubShapeAll(compound, geompy.ShapeType["FACE"])
		
		#parsage de 1 face plane
		surface = text[ text.find("Surfaces"):text.find("\nTriangulations") ] + "\n"
		surfaceTab = surface.split("\n")
		surfaceTab.sort()
		surfaceTab = surfaceTab[1:-1]
		#print(surfaceTab[0])
		
		#affichage
		id_compound = geompy.addToStudy(compound, "Comp")
		gg.createAndDisplayGO(id_compound)
		salome.sg.updateObjBrowser(1)
			
		
