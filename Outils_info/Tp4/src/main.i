%module mymodule
%{
#include "/home/s/segureta/Documents/M2-S1/Outils_info/Tp4/libtp4/lib/tp4.h"
%}

#define VERSION "1.0.3"

extern const double PI;
double pi();
double add_pi(double v);
void set_log(int v);
void stats();

Vecteur* Vecteur_create(double a, double b, double c);
Vecteur* Vecteur_add(Vecteur *v1, Vecteur* v2);
double Vecteur_elem(Vecteur *v, int coord);
char* Vecteur_str(Vecteur *v);
void Vecteur_destroy(Vecteur *v);
