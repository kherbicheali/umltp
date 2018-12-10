#include <unistd.h>
#include <stdio.h>
#include "LecteurCarte.h"
#include "BaseClients.h"
#include "lcarte.h"
#include "Voyants.h"
#include <memoire_borne.h>
#include <donnees_borne.h>
#include "Timer.h"

entrees *io;

void lecteurcarte_initialiser() {
         printf("== LecteurCarte.lecteurcarte_initialiser() ==");
	 initialisations_ports();
	}


void lecteurcarte_lire_carte() {
	unsigned short int num_carte,num_1,num_2;
	int fin=0;
	 
	attente_insertion_carte();
	 
	if (carte_inseree()) {
		num_carte=lecture_numero_carte();
 		printf("== LecteurCarte.lecteurcarte_lire_carte() == num_carte=%d",num_carte);
 	
		if( baseclients_autentifier(num_carte) && voyants_etat_dispo()) {
			//printf("==LecteurCarte.lecteurcarte_lire_carte()== %s",io->led.VERT);
        		voyants_clignote_charge(io->led.VERT);
        		timer_raz();
      			while (timer_valeur()<=60) {
         			if(boutons_charge()) break;
        		}   
        		if(boutons_charge()) { 
				boutons_reset_charge();   
				voyants_set_dispo(OFF);
				attente_retrait_carte();
				generateursave_charger();
		  
				while (!fin) {
					attente_insertion_carte();
					if (carte_inseree()) {
						num_2=lecture_numero_carte();
						if(num_2==num_carte) {
							generateursave_deconnecter();
							fin=1;
						} else {
							voyants_clignote_defaut(ROUGE);
							attente_retrait_carte();
							}
					}
				}  
			} else {  
				voyants_clignote_defaut(ROUGE);
				attente_retrait_carte();
				}
		} else {
			voyants_clignote_defaut(ROUGE);
			attente_retrait_carte();
			}
	}
 
	attente_retrait_carte();
	voyants_set_dispo(VERT);
}
