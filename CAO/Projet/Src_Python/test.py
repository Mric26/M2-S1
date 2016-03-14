import string

def abs(x):
   return {True: x, False: -x}[x >= 0]

chemin = "/home/s/segureta/Documents/M2-S1/CAO/Projet/Data/Piece-01.brep"

fichier = open(chemin,'r')
text = str.join("", fichier.readlines())
fichier.close()

#construit le tableau des faces du fichier brep associe en conservant l ordre
surface = text[ text.find("Surfaces"):text.find("\nTriangulations") ] + "\n"
surfaceTab = surface.split("\n")
surfaceTab = surfaceTab[1:-1]

#recherche le nombre de Tshapes dans le fichier brep	
fichier = open(chemin,'r')
mot = "TShapes"
for ligne in fichier:
	if mot in ligne:
		tab = ligne.split(" ")
		nbShapes = int(tab[1])
fichier.close();

#construit le tableau des shapes du fichier brep associe en conservant l ordre
tshapes = text[ text.find("TShapes") : -1 ]
tshapesTab = tshapes.split("*")
i = 0
for shape in tshapesTab:
	tshape = shape.split("\r\n")
	tshape = tshape[1:]
	tshapesTab[i] = tshape
	i = i+1

indiceSurfacePlane = 2

############################################# ici je travail #############################################

shell = tshapesTab[nbShapes-1]
#['Sh', '', '0101000', '-189 0 -185 0 +52 0 -45 0 -42 0 -35 0 -32 0 -25 0 -22 0 -15 0 ', '-12 0 -5 0 -2 0 ']
lFacesShapes = (shell[len(shell)-2] + shell[len(shell)-1]).split(" 0 ")

listF = []
for i in lFacesShapes[0:-1]:
	listF.append( tshapesTab[ 198 - abs(int(i)) ] )

print "\n Liste des wihers :"
listW = []
for i in listF:
	i = i[4].split(" 0 ")[0:-1]
	listt = []
	for j in i:
		listt.append( tshapesTab[ 198 - abs(int(j)) ] )
	print listt
	listW.append(listt)

print "\n Liste Edges :"
listE = []
for i in listW:
	listt = []
	for j in i:
		listt.append( j[3].split(" 0 ")[0:-1 ] )
	print listt
	listE.append(listt)

print "\n test :"
listEdgesFacePlane = []
for k in listE[indiceSurfacePlane]:
	listt = []
	for l in k:
		l = l.replace('-','')
		l = l.replace('+','')
		listt.append( l )
	#print listt
	listEdgesFacePlane.append( listt )
print listEdgesFacePlane
