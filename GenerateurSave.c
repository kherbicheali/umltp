#include <stdio.h>
#include "generateursave.h"


entrees *io;
int shmid;

typedef enum _etat{etat1,etat2,etat3,etat4,etat5,etat6,etat7} etat;

void generateursave_MEF(etat etat_initial);
void generateursave_genererPMW(pwm tension);
int generateursave_test_tension();
void generateursave_fermerAC();
void generateursave_ouvrireAC();



void generateursave_initialiser()
{
	io=acces_memoire(&shmid);
	if (io==NULL) printf("Erreur pas de mem sh\n");

}

void generateursave_charger()
{
    	generateursave_MEF(etat1);
	
}

void generateursave_deconnecter()
{	
    	generateursave_MEF(etat6);

}

void generateursave_MEF(etat etat_initial)
{
	etat etatPresent=etat_initial, etatSuivant=etat_initial;

	while (1)
	{
		switch (etatPresent)
     		{
      		case etat1:
      		if(generateursave_test_tension()==9) etatSuivant=etat2;
        	break;

      		case etat2:
           	if (generateursave_test_tension()==6) etatSuivant=etat3;
           	if (generateursave_test_tension()==12) etatSuivant=etat1;
           	if (boutons_stop()==1 )etatSuivant=etat5;
       		break;

       		case etat3:
           	if (generateursave_test_tension()==6) etatSuivant=etat4;
           	if (generateursave_test_tension()==9) etatSuivant=etat2;
           	if (boutons_stop()==1 )etatSuivant=etat5;
       		break;

       		case etat4:
           	if (generateursave_test_tension()==9) etatSuivant=etat5;
            	if (boutons_stop()==1 )etatSuivant=etat5;      
       		break;
      
      		case etat5:
            
       		break;
      		
		case etat6:
            	if(generateursave_test_tension()==12) etatSuivant=etat7;
       		break;
	   	
		case etat7:
           
       		break;
    		} 

	etatPresent=etatSuivant;

	if(etatPresent==etat1)      
       	{
        voyants_set_charge(ROUGE);
        prise_deverouiller_trape();
        generateursave_genererPMW(DC);
       	}
	if(etatPresent==etat2)      
       	{
        prise_verouiller_trape();
        prise_set_prise(VERT);
        generateursave_genererPMW(AC_1K);   
        }
	if(etatPresent==etat3) 
       	{
        generateursave_fermerAC();
        generateursave_genererPMW(AC_CL);
       	}

	if(etatPresent==etat4) 
       	{
       
       	}
	if(etatPresent==etat5)      
       	{
         if (boutons_stop()==1 )boutons_reset_stop() ; 
         voyants_set_charge(VERT);
         generateursave_ouvrireAC();
         generateursave_genererPMW(DC);
         break; 
        }
		
	if(etatPresent==etat6)      
        {
         prise_deverouiller_trape();
        }
		
	if(etatPresent==etat7)      
       	{
        voyants_set_charge(OFF);
        prise_verouiller_trape();
        prise_set_prise(OFF);
        generateursave_genererPMW(STOP);
        break; 
       	}   
	}

}


void generateursave_genererPMW(pwm tension)
{
	io->gene_pwm=tension ;

}

int generateursave_test_tension()
{
	return io->gene_u ;

}

void generateursave_fermerAC()
{
	io->contacteur_AC=1;

}

void generateursave_ouvrireAC()
{
	io->contacteur_AC=0;

}


