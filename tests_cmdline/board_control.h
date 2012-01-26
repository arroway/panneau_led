/**
 * @file board_control.h
 *
 * Interface du module principal
 *
 * @version 1.1
 * @author Stéphanie Ouillon
 * @date février 2011
 */

#ifndef _BOARD_CONTROL_H
#define _BOARD_CONTROL_H

/**
 * Structure contenant les options d'affichage du texte sur le panneau
 */

#define LENGTH_ID 3
#define LENGHT_OPT 2
#define LENGTH_MAX_TEXT 141

int compt;

typedef struct struct_option {
  char id[LENGTH_ID];
  char page[LENGHT_OPT];
  char lead_cmd[LENGHT_OPT];
  char display_meth[LENGHT_OPT];
  char wait_time[LENGHT_OPT];
  char lag_cmd[LENGHT_OPT];
  char priority[LENGHT_OPT];
} struct_option;

struct struct_option options;

char* text;

void free_struct_option( struct_option );
void my_free( char );

/**
 * Verification de la compatibilité des arguments de la ligne de commande
 */
int check_arguments();

/**
 * Ouverture et configuration du port série 
 * @ param nom_du_port : nom du port à ouvrir
 */
int open_port( void );

#endif
