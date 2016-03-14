import string

def abs(x):
   return {True: x, False: -x}[x >= 0]
   
def creationListeFaces(shell):
	#construit la liste des faces
	lFacesShapes = (shell[len(shell)-2] + shell[len(shell)-1]).split(" 0 ")
	listF = []
	for i in lFacesShapes[0:-1]:
		listF.append( tshapesTab[ 198 - abs(int(i)) ] )
	return listF

def creationListeWiher(listF):
	#construit la liste des wihers
	listW = []
	for i in listF:
		i = i[4].split(" 0 ")[0:-1]
		listt = []
		for j in i:
			listt.append( tshapesTab[ 198 - abs(int(j)) ] )
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

def printperso(listA):
	for i in listA:
		print i

def trouverCentres(listEP, tshapesTab):
	#construit la liste des centres des percages
	#1ere atape : recuperation des edges
	listV = []
	for e in listEP:
		e = tshapesTab[ 198 - int(e) ] 
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
		p1 = tshapesTab[ 198 - couple[0] ][2]
		p1 = p1.split(" ")
		p2 = tshapesTab[ 198 - couple[1] ][2]
		p2 = p2.split(" ")
		pres = []
		pres.append( (float(p1[0]) + float(p2[0])) / 2 )
		pres.append( (float(p1[1]) + float(p2[2])) / 2 )
		pres.append( (float(p1[2]) + float(p2[2])) / 2 )
		listCentre.append(pres)
	return listCentre

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

if tshapesTab[nbShapes-1][0] == "Sh":
		shell = tshapesTab[nbShapes-1]
else:
	for i in tshapesTab:
		if i[0] == "Sh":
			shell = i
#['Sh', '', '0101000', '-189 0 -185 0 +52 0 -45 0 -42 0 -35 0 -32 0 -25 0 -22 0 -15 0 ', '-12 0 -5 0 -2 0 ']

indicePlane = 2

print "\n Liste des faces :"
listF = creationListeFaces(shell)
#printperso(listF)
print "	ok"

print "\n Liste des wihers :"
listW = creationListeWiher(listF)
#printperso(listW)
print "	ok"

print "\n Liste Edges :"
listE = creationListeEdges(listW)
#printperso(listE)
print "	ok"

print "\n Liste Edges partages:"
listEP = creationListeEdgesPartage(indicePlane, listE)
#print(listEP)
print "	ok"

print "\n Liste des centres:"
listCentre2 = trouverCentres(listEP, tshapesTab)
#printperso(listCentre2)
print "	ok"


print "\n test :"


