/**
 * \file message_manager.h
 * \brief Fonctions pour mettre en forme des trames
 * 
 * \author Jacquot V.
 * \version 0.2
 * \date 10/04/11
 */


#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H


#define LENGTH_ID 3
#define LENGHT_OPT 2
#define LENGTH_MAX_TEXT 141

/***** Emprunte a board_control.h *****/

typedef struct struct_option {
  char id[LENGTH_ID];
  char page[LENGHT_OPT];
  char lead_cmd[LENGHT_OPT];
  char display_meth[LENGHT_OPT];
  char wait_time[LENGHT_OPT];
  char lag_cmd[LENGHT_OPT];
  char priority[LENGHT_OPT];
} struct_option;

void my_free( char* arg_struct );


void free_struct_option( struct_option opt );

/**************************************/


/**
 * \fn char build_message(struct_option options, char* text)
 * \brief Envoie une trame au panneau
 *
 * \param options Options a envoyer au panneau
 * \param message Texte a envoyer au panneau
 * \param target Tableau destine a contenir la trame
 * \return 0 si reussite,1 si échec
 */
char build_message(struct struct_option opt, const char* text, char* target);


#endif
