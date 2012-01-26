#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "write_to_port.h"

#include "message_manager.h"

void my_free( char* arg_struct ){

  if ( arg_struct ){
    free( arg_struct );
    arg_struct = NULL;
  }
}

void free_struct_option( struct_option opt ){

  my_free( opt.page );
  my_free( opt.lead_cmd );
  my_free( opt.display_meth );
  my_free( opt.wait_time );
  my_free( opt.lag_cmd);
  my_free( opt.priority);
}


char build_message(struct struct_option opt, const char* text, char* target)
{
    // Verifions s'il y a assez de place pour le minimum
    if (LENGTH_T < 36) {
        perror("Transmission buffer is too short!\n");
        return 1;
    }

    // Initialisation du debut de la trame a transmettre
    strcpy(target, "<ID00><L1><PA><FE><MA><WC><FE>");

    /**** Modification des options ****/

    // Changement de la page
    target[12] = (opt.page)[0];
    // Changement de l'effet d'apparition
    target[16] = (opt.lead_cmd)[0];
    // Changement de la methode d'affichage
    target[20] = (opt.display_meth)[0];
    // Changement du temps d'attente
    target[24] = (opt.wait_time)[0];
    // Changement de l'effet de disparition
    target[28] = (opt.lag_cmd)[0];

    /**********************************/
    
    // Longueur max reservee au texte
    size_t max_length = LENGTH_T - 36;

    // Ajout du texte
    // Le texte est tronqué s'il est trop grand
    strncat(target, text, max_length);
    
    // Ajout du checksum
    unsigned char i;
    unsigned char checksum = 0;
    for (i = 7; target[i] != '\0'; i++)
        checksum ^= target[i];
        
    // On ecrit le checksum en hexa
    sprintf(&(target[i]), "%02X", checksum);
    
    // Ajout de la fin de la trame
    strcat(target, "<E>");

    return 0;
}

