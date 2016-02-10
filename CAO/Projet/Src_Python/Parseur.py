
from PyQt4 import QtCore, QtGui

def parsage():
	import salome
	from salome.geom import geomBuilder
	geompy = geomBuilder.New(salome.myStudy)	
	
	chemin = str( QtGui.QFileDialog.getOpenFileName( directory="Z:\Documents\M2-S1\CAO\Projet\Data", filter="*.brep" ) )
	if not chemin:
		print "Il faut selectionner un fichier pour que ca marche"
	else:
		#ouverture brep pour affichage futur
		Brep = geompy.ImportBREP( chemin )
		#ouverture file pour parsage
		file = open(chemin, 'r')
		line = file.readline()
		while( line.find( "Curves" ) == -1 ):
			line = file.readline()
		tabline = line.split()
		num_curves = tabline[1]
		print ("Nombre de courbes : " + str(num_curves))