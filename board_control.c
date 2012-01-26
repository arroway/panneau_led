/**
 * @file board_control.c
 * @brief Programme principal
 *
 * @version 1.0
 * @author Stéphanie Ouillon, Vincent Jacquot
 * @date mai 2011
 *
 * Programme principal de gestion du panneau à led
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "board_control.h"
#include "parse_command_line.h"
#include "check_arguments.h"
#include "write_to_port.h"
#include "message_manager.h"

/**
 * @fn int main( int argc, char** argv );
 * @brief Fonction principale lançant le programme
 *
 * @param argc nombre d'arguments sur la ligne de commande
 * @param argv chaîne de textes sur la ligne de commande
 *
 * Fonction principale lançant le programme et qui effectue les fonctions suivantes :
 * 		- récupération des options et du texte sur la ligne de commande
 * 		- vérification des options
 * 		- ouverture du port série pour communiquer avec le panneau
 * 		- contruction de la trame (options + message texte ) à envoyer au panneau
 * 		- écriture de la trame dans le port
 * 		- fermeture du port
 */

int main( int argc, char** argv ){

  text = malloc( LENGTH_MAX_TEXT * sizeof(char) );
  text[0] = '\0';

  printf("Parsing the command line...\n");
  if ( parse_command_line( argc, argv ) != 0 )
	  return EXIT_FAILURE;

  printf("Checking option arguments are correct...\n");
  if ( check_arguments( arg_options, text ) == 0 ){

    if (add_frame(options, text, options.priority[0]) != 0)
      printf("[!!]ERROR add_frame() failed.\n");
      
  }
  else {
	printf("[!!]ERROR check_arguments() failed.\n");
	printf("\nMessage wasn't sent to the display board.\n");
  }

  return EXIT_SUCCESS;
}
