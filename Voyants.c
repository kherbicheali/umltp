#include <stdio.h>

#include "Voyants.h"
#include "Timer.h"

entrees *io;
int shmid;

void voyants_initialiser()
{

	io=acces_memoire(&shmid);
	if (io==NULL) printf("Erreur pas de mem sh\n");
}


void voyants_set_charge(led couleur)
{
	io->led_charge=couleur;
}


void voyants_clignote_charge(led couleur)
{
	timer_raz();
  	while (timer_valeur()<=8)
   	{	
  	voyants_set_charge(couleur);
   	voyants_set_charge(OFF);
   	}
}


void voyants_set_dispo(led couleur)
{
	io->led_dispo=couleur;

}

void voyants_set_defaut(led couleur)
{
	io->led_defaut=couleur;

}

void voyants_clignote_defaut(led couleur)
{
  	timer_raz();
  	while (timer_valeur()<=8)
   	{
   	voyants_set_defaut(couleur);
   	voyants_set_defaut(OFF);
   	}
	voyants_set_defaut(OFF);
}


unsigned short int voyants_etat_dispo() {
	if (io->led_dispo==VERT) {
		printf("== Voyants.voyants_etat_dispo() == VERT");
		return 1;
	} else {
		printf("== Voyants.voyants_etat_dispo() == !!!VERT");
		return 0;
               }	
}





