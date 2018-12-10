
#include "prise.h"

entrees *io;
int shmid;


void prise_initialiser()
{
	io=acces_memoire(&shmid);
	if (io==NULL) printf("Erreur pas de mem sh\n");
}

void prise_set_prise(led couleur)
{
	io->led_prise=couleur;

}

void prise_verouiller_trape()
{
	io->led_trappe=OFF;

}

void prise_deverouiller_trape()
{
	io->led_trappe=VERT;

}




