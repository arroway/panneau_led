/**
 * @file board_control.h
 * @brief Interface du module principal
 *
 * @version 1.0
 * @author Stéphanie Ouillon
 * @date février 2011
 *
 * Interface du module principal
 **/

#ifndef _BOARD_CONTROL_H
#define _BOARD_CONTROL_H

/**
 *
 * @def LENGTH_ID
 * @def LENGTH_OPT
 * @def LENGTH_MAX_TEXT
 * @brief Définition des tailles maximales des tableaux d'options utilisés
 **/

#define LENGTH_ID 3
#define LENGTH_OPT 2
#define LENGTH_MAX_TEXT 139


/**
 * @struct struct_option board_control.h
 * @brief Structure contenant les options d'affichage du texte sur le panneau
 *
 **/

typedef struct struct_option {
  char id[LENGTH_ID];			/*!< Numéro d'ID. Il vaut '01' par défaut. */
  char page[LENGTH_OPT];		/*!< Numéro de la page sur lequel le message s'affichera. */
  char lead_cmd[LENGTH_OPT];	/*!< Option d'affichage du message entrant. */
  char display_meth[LENGTH_OPT];/*!< Option d'affichage du message affiché. */
  char wait_time[LENGTH_OPT];	/*!< Temps d'attente du message. */
  char lag_cmd[LENGTH_OPT];		/*!< Option d'affichage du message sortant. */
  char priority[LENGTH_OPT];	/*!< Priorité du message : vaut 0 ( priorité normale ) ou 1 (urgent )*/
} struct_option;

struct struct_option options;

/**
 * @enum text
 * @brief Tableau de pointeurs qui contient les mots du message texte à afficher sur le panneau.
 **/

char* text;



int open_port( void );

#endif
