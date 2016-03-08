# -*- coding: iso-8859-1 -*-
# Copyright (C) 2010-2015  CEA/DEN, EDF R&D, OPEN CASCADE
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#
# Author : Guillaume Boulant (EDF)

import salome_pluginsmanager

  # -------------------------------------------------------------------------
  # Example 1: creation of basic objects.
  # The plugin function is implemented here and declared in the pluginsmanager.
  #
import salome



def sameFamily(context):
  
	from PyQt4 import QtCore, QtGui
	#from fonctions import ask_path
	def ask_path():
		return str(QtGui.QFileDialog.getOpenFileName())
  
	
	import GEOM
	import SALOMEDS
	from salome.geom import geomBuilder
	geompy = geomBuilder.New(salome.myStudy)

	def search_shape(fichier):
    #with open(fichier) as f:
		f=open(fichier)
		for num, line in enumerate(f,1):
			if "Surfaces" in line: 
				ligne = num
				
				f2=open(fichier)
				lines = f2.readlines()
				lignesplit = lines[num - 1].split(" ")
				number = int(lignesplit[1])
				limite = num
				number+= limite
				print(limite)
				print(number)
				while limite < number:
					fnum=open("/home/jihl/Documents/M2/CAO/plugins/"+str(limite),"a")
					if (lines[limite][0] == "1" or lines[limite][0] == "2" or lines[limite][0] == "4" or lines[limite][0] == "5"):
						fnum.write(lines[limite])
						limite+= 1
						
						
					elif (lines[limite][0] == "3" or lines[limite][0] == "6" or lines[limite][0] == "7"):
						fnum.write(lines[limite])
						fnum.write(lines[limite+1])
						limite+= 2
						
						
					else :
						fnum.write(lines[limite])
						fnum.write(lines[limite+1])
						fnum.write(lines[limite+2])
						limite+= 2
						
					fnum.close()
				f2.close()
		f.close()
		return
  
  
	def creation_rep_brep(fichier):
		
		# On récupère le fichier à analyser
		chemin = ask_path()
		
		# Import du fichier BREP du compound
		compound = geompy.ImportBREP(chemin)
  
  
  
  
  
	gg = salome.ImportComponentGUI("GEOM")
  
	# Intialize the geompy factory with the active study
	activeStudy = context.study
	chemin = ask_path()
	
	#chemin2 = ask_path()
	
	# Import du fichier BREP du compound
	compound = geompy.ImportBREP(chemin)
	
	# Import du fichier BREP du solid
	#goujon = geompy.ImportBREP(chemin2)
	
	# Affiche le nombre de solid dans le compound
	nbrSolid = geompy.NumberOfSubShapes(compound, geompy.ShapeType["SOLID"])
	# nbrSolid = geompy.NumberOfSolids(compound) 	
	print(nbrSolid)
	
	compound.SetColor(SALOMEDS.Color(0,0,0))
	
	# Explose un shape en un type de shape
	listSolid = geompy.SubShapeAll(compound, geompy.ShapeType["SOLID"])
	#print(listSolid)
	
	for i in listSolid:
		
	
	
	
	
	#Marche pas
	#listSame = geompy.GetSame(compound, goujon)
	#goujonID = geompy.GetSubShapeID(compound, goujon)
	
	#Fonction qui permet de résoudre le problème de la shape identique
	#geompy.GetSharedShapes(self,theShape1, theShape2, theShapeType) 		
	
	# create a group from the faces of the box
	#group = geompy.CreateGroup(compound, geompy.ShapeType["SOLID"])
	
	#id_group1 = geompy.addToStudy(group, "Group1")
	id_compound = geompy.addToStudy(compound, "Comp")
	
	# display the contents of the group
	gg.createAndDisplayGO(id_compound)
	salome.sg.updateObjBrowser(1)
	
	# update Object browser contents
	#salome.sg.updateObjBrowser(True)
	
	# get the active study ID
	#studyId = salome.sg.getActiveStudyId() 

	# get the active study name
	#studyName = salome.sg.getActiveStudyName()
	
	#print(studyName)
	
	# get the selected objects
	#selCount = salome.sg.SelectedCount() # the number of selected items
	#print(selCount)
	#for i in range(selCount):
	#	print salome.sg.getSelected(i) # print the entry ID of i-th selected item
	
	
	#gg = salome.ImportComponentGUI("GEOM")
	
	#print(gg)
	#UnitName1 = geompy.GetIGESUnit(chemin)
	#geompy = geomBuilder.New(salome.myStudy)
	#geompy = geomBuilder.New(activeStudy)
	
	#Fonction qui crée des fichiers des faces
	#search_shape(chemin)
	#listID = activeStudy.getGeompy
	#print(UnitName1)
	
	#print(chemin)
	#print("TESTETSTETET")


salome_pluginsmanager.AddFunction('We are a Family',
                                    'Check for objects of the same family',
                                    sameFamily)



