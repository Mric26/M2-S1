#ifndef _TP3_H
#define _TP3_H

/***********************************************************
 * Partie 1
 */

#define VERSION "1.0.3"

extern const double PI;

/* renvoie la valeur PI */
double pi();

/* renvoie la valeur PI à laquelle on a ajouté la valeur v */
double add_pi(double v);

/* démarre/arrête les messages de log permettant de voir quelles
   fonctions C sont appelées */
void set_log(int v);

/* affiche des statistiques à propos des fonctions de la seconde partie */
void stats();

/***********************************************************
 * Partie 2
 */

/* Type opaque Vecteur à 3 composantes */
typedef struct _vecteur Vecteur;

/* Crée un nouveau vecteur à partir des trois composantes */
Vecteur* Vecteur_create(double a, double b, double c);
/* Crée un nouveau vecteur à partir de la somme de 2 autres */
Vecteur* Vecteur_add(Vecteur *v1, Vecteur* v2);
/* Récupère les éléments d'un vecteur */
double Vecteur_elem(Vecteur *v, int coord);
/* Renvoie une chaîne allouée avec malloc contenant une description du vecteur */
char* Vecteur_str(Vecteur *v);
/* Détruit un vecteur (libère la mémoire occupée par ce vecteur) */
void Vecteur_destroy(Vecteur *v);


#endif
