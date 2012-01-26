/**
 * @file check_arguments.c
 * @brief Verification des trames à envoyer au panneau à LED
 *
 * @author Stéphanie Ouillon
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "board_control.h"
#include "parse_command_line.h"
#include "check_arguments.h"

/* Par défaut, l'ID est mis à 1. */
#define ID "01"


/* Check and save display options and text. */

int check_arguments( struct_arg_options arg_options, char* text ){

    /* On enregistre l'ID par défaut.*/

    if ( ( strlen( ID ) == ( LENGTH_ID - 1 ) ) && ( atoi( ID ) == 1 ) )
    	strcpy( options.id, ID );
    else{
    	printf( "Bad value of ID in check_arguments.\n" );
    	return EXIT_FAILURE;
    }

    /* Check each display option */

    if ( check_option_page( arg_options.page ) != 0 )
    	return EXIT_FAILURE;

    if ( check_option_lead_cmd( arg_options.lead_cmd ) != 0 )
    	return EXIT_FAILURE;

    if ( check_option_display_meth( arg_options.display_meth ) !=0 )
    	return EXIT_FAILURE;

    if ( check_option_wait_time( arg_options.wait_time ) != 0 )
    	return EXIT_FAILURE;

    if ( check_option_lag_cmd( arg_options.lag_cmd ) != 0 )
    	return EXIT_FAILURE;


    /* Check priority and save it */

    if ( ( arg_options.priority != '0' ) && ( arg_options.priority != '1' ) ){
   	 printf("[!!]ERROR the option 'priority' is not correct.\n");
   	 return EXIT_FAILURE;
    }


    /* Save options to be written in the framework */

    if ( save_option( options.page, arg_options.page ) != 0 )
        	return EXIT_FAILURE;

     if ( save_option( options.lead_cmd, arg_options.lead_cmd ) != 0 )
     	return EXIT_FAILURE;

     if ( save_option( options.display_meth, arg_options.display_meth ) != 0 )
     	return EXIT_FAILURE;

     if ( save_option( options.wait_time, arg_options.wait_time ) != 0 )
     	return EXIT_FAILURE;

     if ( save_option( options.lag_cmd, arg_options.lag_cmd ) != 0 )
     	return EXIT_FAILURE;

     options.priority[0] = arg_options.priority;

    /* Check test message doesn't have any non-supported characters, or replace them */
    if ( check_text( text ) != 0 )
    	return EXIT_FAILURE;

	return EXIT_SUCCESS;
}


/* Check validity of text */
int check_text( char* text ){

	//debug
       	//printf("We enter check_text.\n");

    if ( remove_spec_char( text ) != 0 ){
    	printf("[!!]ERROR remove_spec_char() has failed.\n");
    	return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}


/* Check display options are capital letters. */

int check_option_page( char argv ){

	char letter_begin = 'A';
	char letter_end = 'Z';
	if ( check_option( argv, letter_begin, letter_end ) != 0 ){
		printf("[!!]ERROR the option 'page' is not correct.\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}

int check_option_lead_cmd( char argv ){

	char letter_begin = 'A';
	char letter_end = 'S';
	if ( check_option( argv, letter_begin, letter_end ) != 0 ){
		printf("[!!]ERROR the option 'lead command' is not correct.\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}

int check_option_display_meth( char argv ){

	int var = 0;
	char letter_begin = 'A';
	char letter_end = 'B';

	if ( check_option( argv, letter_begin, letter_end ) != 0 ){
		var++ ;
	}

	letter_begin = 'Q';
	letter_end = 'R';
	if ( check_option( argv, letter_begin, letter_end ) != 0 ){
		var++ ;
	}

	letter_begin = 'a';
	letter_end = 'b';
	if ( check_option( argv, letter_begin, letter_end ) != 0 ){
		var++ ;
	}

	letter_begin = 'q';
	letter_end = 'r';
	if ( check_option( argv, letter_begin, letter_end ) != 0 ){
		var++ ;
	}


	if ( var == 4 ){
		printf("ERROR the option 'lead command' is not correct.\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}


int check_option_wait_time( char argv ){

	char letter_begin = 'A';
	char letter_end = 'K';
	if ( check_option( argv, letter_begin, letter_end ) != 0 ){
		printf("[!!]ERROR the option 'waiting time' is not correct.\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}

int check_option_lag_cmd( char argv ){

	char letter_begin = 'A';
	char letter_end = 'K';
	if ( check_option( argv, letter_begin, letter_end ) != 0 ){
		printf("[!!]ERROR the option 'lag command' is not correct.\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


int check_option( char argv, char letter_begin, char letter_end ){

	if ( is_letter( argv ) != 0 ){
	  printf("[!!]ERROR %c is not a letter.\n", argv );
	  return EXIT_FAILURE;
	}
	else{
		if ( is_letter_between( argv, letter_begin, letter_end ) != 0 ){
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}


/* Save an option if correct to be written in the framework. */
int save_option( char* argv1, char argv2){

	printf("The saved option is: \n");
	*argv1 = argv2;
	printf("*argv1 : %c\n", *argv1);
	return EXIT_SUCCESS;

}


int is_letter_between( char letter_tested, char letter_begin, char letter_end ){

	if ( ( letter_tested < letter_begin || letter_tested > letter_end ) )
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

/* Check option arguments are letters only */
int is_letter( char argv ){

  if ( isalpha( argv ) == 0 ){
    perror( "isalpha() false! Character is not a letter.\n" );
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS ;
}


/* Remove accents and special characters off the text. */
int remove_spec_char( char* text ){

  int j = 0;
  int length = strlen( text );

  /* char* table[2][11];
 
  table[0][0] = "é";
  table[0][1] = "è";
  table[0][2] = "ê"; 
  table[0][3] = "ç";
  table[0][4] = "î";
  table[0][5] = "ô";
  table[0][6] = "ù";
  table[0][7] = "â";
  table[0][8] = "ä";
  table[0][9] = "à";
  table[0][10] = "€";
  
  table[1][0] = "e";
  table[1][1] = "e";
  table[1][2] = "e";
  table[1][3] = "c";
  table[1][4] = "i";
  table[1][5] = "o";
  table[1][6] = "u";
  table[1][7] = "a";
  table[1][8] = "a";
  table[1][9] = "a";
  table[1][10] = "E"; */
  
  while ( j < length ){

    if ( ( ( isalnum( text[j] ) == 0 ) && ( ispunct( text[j] ) == 0 ) ) ||
    		( ( text[j] == '<' ) || ( text[j] == '>' ) ) ){
	   printf("Le carcatère %c n'est pas accepté.\n", text[j]);
	   return EXIT_FAILURE;
    }

   j++;
  }
  return EXIT_SUCCESS;
}
