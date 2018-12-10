#include "boutons.h"

entrees *io;
int shmid;


void boutons_initialiser()
{
	io=acces_memoire(&shmid);
	if (io==NULL) printf("Erreur pas de mem sh\n");
}


int boutons_charge()
{
	if (io->bouton_charge==1) return 1;
	else return 0;

}

int boutons_stop()
{
	if (io->bouton_stop==1) return 1;
	else return 0;

}

void boutons_reset_charge()
{
	io->bouton_charge=0;

}

void boutons_reset_stop()
{
	io->bouton_stop=0;

}


