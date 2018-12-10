#include <stdio.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <mem_sh.h>
#include "BaseClients.h"

//author

entrees *io;
int shmid;

unsigned short int num_carte_courant;


int baseclients_autentifier(unsigned short int num_carte)
{
	FILE* fichier;
  	int temp;
  	fichier=fopen("base.txt","r");
  
  	if (fichier==NULL) {
      		printf("\n == BaseClientsLe.baseclients_autentifier() == fichier n'existe pas ou exception lors de l'ouverture..");
		printf("\n == BaseClientsLe.baseclients_autentifier() == Veilliez reessayer la procedure.");                  
        	exit(1);
       	} else {
      		printf("\n == BaseClientsLe.baseclients_autentifier() == Le fichier est ouvert avec succes..");                  
	}

  	while ((fscanf(fichier,"%d",&temp)!= EOF)) {     
        	if(num_carte==temp) {
			fclose(fichier);
      			num_carte_courant=num_carte;
			printf("== BaseClients.baseclients_autentifier == num_carte=%d",num_carte);
			printf("\n == BaseClientsLe.baseclients_autentifier() == Authentification reussie.");
			return 1;
		}
	}

	printf("\n == BaseClientsLe.baseclients_autentifier() == Echec de l'authentification."); 
	printf("\n == BaseClientsLe.baseclients_autentifier() == Veilliez reessayer.");
	fclose(fichier);
	return 0;
}

