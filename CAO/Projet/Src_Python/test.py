chemin = "/home/s/segureta/Documents/M2-S1/CAO/Projet/Data/Piece-01.brep"

#parsage face place
file = open(chemin,'r')
text = str.join("", file.readlines())
file.close()
		
surface = text[ text.find("Surfaces"):text.find("\nTriangulations") ] + "\n"
surfaceTab = surface.split("\r\n")
surfaceTab.sort()
surfaceTab = surfaceTab[1:-1]
print(surfaceTab[0])

