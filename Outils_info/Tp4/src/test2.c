#include "tp4.h"

#include <stdio.h>
#include <stdlib.h>

Vecteur *f() {
	Vecteur *v1=Vecteur_create(1, 2, 3);
	Vecteur *v2=Vecteur_create(4, 5, 6);
	Vecteur *v=Vecteur_add(v1, v2);
	stats();
	char *val_v=Vecteur_str(v);
	printf("Vecteur v: %s\n", val_v);
	free(val_v);
	Vecteur_destroy(v2);
	Vecteur_destroy(v1);
	Vecteur_destroy(v);
	return v;
}


int main() {
	stats();
	Vecteur *vecteur=f();
	stats();
	char *val_v=Vecteur_str(vecteur);
	/* Erreur normalement à la ligne précédente : v a été libéré */
	free(val_v);
	return 0;
}
