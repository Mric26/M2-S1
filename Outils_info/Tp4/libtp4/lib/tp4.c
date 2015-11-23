
#include "tp4.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define log(str...) \
	if (log_enabled()) { \
		fprintf(stderr, "\tLOG: " str);	\
        }

const double PI=3.14;

static int do_log=0;

static inline int log_enabled() {
	return do_log;
}

void set_log(int v) {
	log("Invocation de set_log(%i)\n", v);
	do_log=v;
}

double pi() {
	log("Invocation de pi()\n");
	return PI;
}

double add_pi(double v) {
	log("Invocation de add_pi(%lg)\n", v);
	return pi()+v;
}

static int nb_created=0;
static int nb_destroyed=0;

void stats(void) {
	fprintf(stderr, "Nombre de Vecteur créés : %i\n", nb_created);
	fprintf(stderr, "Nombre de Vecteur détruits : %i\n", nb_destroyed);
}

/* Type opaque Vecteur à 3 composantes */
struct _vecteur {
	int valid;
	double cs[3];
};

static Vecteur* alloc() {
	Vecteur *v=malloc(sizeof(Vecteur));
	v->valid=0xBEEF;
	nb_created++;
	return v;
}

static void desalloc(Vecteur *v) {
	v->valid=0;
	nb_destroyed++;
	free(v);
}

static void check(Vecteur *v) {
	assert(v->valid == 0xBEEF);
}

/* Crée un nouveau vecteur à partir des trois composantes */
Vecteur* Vecteur_create(double a, double b, double c) {
	log("Vecteur_create\n");
	Vecteur *v=alloc();
	check(v);
	v->cs[0]=a;
	v->cs[1]=b;
	v->cs[2]=c;
	return v;
}

/* Crée un nouveau vecteur à partir de la somme de 2 autres */
Vecteur* Vecteur_add(Vecteur *v1, Vecteur* v2) {
	log("Vecteur_add\n");
	Vecteur *v=alloc();
	int i;
	check(v);
	check(v1);
	check(v2);
	for(i=0; i<3; i++) {
		v->cs[i]=v1->cs[i]+v2->cs[i];
	}
	return v;	
}

/* Récupère les éléments d'un vecteur */
double Vecteur_elem(Vecteur *v, int coord) {
	log("Vecteur_elem\n");
	check(v);
	return v->cs[coord];
}

/* Renvoie une chaîne allouée avec malloc contenant une description du vecteur */
char* Vecteur_str(Vecteur *v) {
	log("Vecteur_str\n");
	check(v);
	int lg;
	lg=snprintf(NULL, 0, "[%lg,%lg,%lg]", v->cs[0], v->cs[1], v->cs[2]);
	char*ret=malloc(lg+1);
	snprintf(ret, lg+1, "[%lg,%lg,%lg]", v->cs[0], v->cs[1], v->cs[2]);
	return ret;
}

/* Détruit un vecteur (libère la mémoire occupée par ce vecteur) */
void Vecteur_destroy(Vecteur *v) {
	log("Vecteur_destroy\n");
	check(v);
	desalloc(v);
}

