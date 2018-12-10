#if !defined(voyants_h_)
#define voyants_h_

#include "donnees_borne.h"
#include "memoire_borne.h"


void voyants_initialiser();

void voyants_set_charge(led couleur);

void voyants_clignote_charge(led couleur);

void voyants_set_dispo(led couleur);

void voyants_set_defaut(led couleur);

void voyants_clignote_defaut(led couleur);

unsigned short int voyants_etat_dispo();

#endif 


