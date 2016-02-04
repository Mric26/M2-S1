
def accesFichier():
	msg = "Veuillez selectionner une piece avant de lancer le plugin, merci."
	selCount = salome.sg.SelectedCount()
	if selCount < 1:
        print msg
        return
	print "Je suis fier de toi tu as selectionne une piece"