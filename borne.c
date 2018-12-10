#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>

#include "lecteurcarte.h"
#include "voyants.h"
#include "prise.h"
#include "boutons.h"
#include "generateursave.h"


int main()
{


    lecteurcarte_initialiser();
    voyants_initialiser();   
    prise_initialiser() ;
    boutons_initialiser();
    generateursave_initialiser();

    while (1)
    {
        lecteurcarte_lire_carte();
    }

}

