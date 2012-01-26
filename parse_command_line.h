/**
 * @file parse_command_line.h
 * @brief Interface du module de parsing
 *
 * @version 1.0
 * @author Stéphanie Ouillon
 * @date mai 2011
 *
 * Interface du module de parsing de la ligne de commande en entrée du programme principal
 **/


#ifndef _PARSE_H
#define _PARSE_H

#include <stdio.h>
#include <errno.h>
#include <getopt.h>
#include "board_control.h"

/**
 * @struct struct_arg_option parse_command_line.h
 * @brief Structure intermédiaire pour les options d'affichage du texte
 *
 * Cette structure est une structure intermédiaire utilisée par la fonction get_opt_long de la librairie C standard getopt.h :
 * elle récupère les arguments parsés de la ligne de commande.
 * Puis chaque élément sera contrôlé dans check_arguments.c avant d'être copié dans la structure finale
 * struct_options définie dans board_control.h
 *
 * Les éléments de la structure sont les mêmes que ceux de la structure struct_options.
 *
 **/

typedef struct struct_arg_options {
	char page;         /* -p */
	char lead_cmd;     /* -l */
	char display_meth; /* -d */
	char wait_time;    /* -t */
	char lag_cmd;      /* -g */
	char priority;      /* -P */
} struct_arg_options;

struct struct_arg_options arg_options;


void help( void );

int parse_command_line(int, char **);




#endif
