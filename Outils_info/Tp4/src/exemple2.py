#!/usr/bin/python

import mymodule

def f() :
	v1 = mymodule.Vecteur_create(1, 2, 3)
	v2 = mymodule.Vecteur_create(4, 5, 6)
	v = mymodule.Vecteur_add(v1, v2)
	mymodule.stats()
	val_v = mymodule.Vecteur_str(v)
	print("Vecteur v:" + val_v + "\n")
	mymodule.Vecteur_destroy(v2)
	mymodule.Vecteur_destroy(v1)
	mymodule.Vecteur_destroy(v)
	return v

########### MAIN ############
mymodule.stats()
vecteur = f()
mymodule.stats()
val_v = mymodule.Vecteur_str(vecteur)
# Erreur normalement a la ligne precedente : v a ete libere #

