#include <stdio.h>`
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "board_control.h"
#include "parse_command_line.h"
#include "check_arguments.h"

#define LENGTH_MAX 1000

void macro_test( int test, int num ){


	if ( !test ){
		compt++;
		printf("Test n° %d : OK.\n\n", num);
	}
	else{
		printf("[!!TEST ERROR!!]Test n°%d : FAIL.\n\n ", num );
	}

}

int check_arguments_tests(){


	arg_options.page = 0;
	arg_options.lead_cmd = 0;
	arg_options.display_meth = 0;
	arg_options.wait_time = 0;
	arg_options.lag_cmd = 0;
	arg_options.priority = 0;

	char* text;
	text = malloc( LENGTH_MAX * sizeof( char ) );


	/* Tests 1 à 9 : check_test */

	strcpy( text, "test1");
	macro_test( check_text( text ), 1 );

	strcpy( text, "TEST12" );
	macro_test( check_text( text ), 2 );


	/* Les caractères accentués ne sont pas acceptés.*/
	strcpy( text, "é");
	macro_test( !check_text( text ), 3);

	strcpy( text, "è");
	macro_test( !check_text( text ), 4 );

	strcpy( text, "à");
	macro_test( !check_text( text ), 5 );

	/* Les caractères de ponctuation sont acceptés. */
	strcpy( text, "!");
	macro_test( check_text( text ), 6 );

	strcpy( text, "@");
	macro_test( check_text( text ), 7 );

	/* Les caractères délimiteurs de trames ne sont pas acceptés
	 * car ils peuvent être mal interpétés. */
	strcpy( text, "<");
	macro_test( !check_text( text ), 8 );

	strcpy( text, ">");
	macro_test( !check_text( text ), 9 );


	/* Tests 10 à 13 : check_option_page */

	arg_options.page = 'A';
	macro_test( check_option_page( arg_options.page ), 10 );

	arg_options.page = 'a';
	macro_test( !check_option_page( arg_options.page ), 11 );

	arg_options.page = '1';
	macro_test( !check_option_page( arg_options.page ), 12 );

	arg_options.page = '!';
	macro_test( !check_option_page( arg_options.page ), 13 );


	/* Tests 14 à 19 : check_option_lead_cmd */

	arg_options.lead_cmd = 'A';
	macro_test( check_option_lead_cmd( arg_options.lead_cmd ), 14 );

	arg_options.lead_cmd = 'a';
	macro_test( !check_option_lead_cmd( arg_options.lead_cmd ), 15 );

	arg_options.lead_cmd = 'T';
	macro_test( !check_option_lead_cmd( arg_options.lead_cmd ), 16 );

	arg_options.lead_cmd = 't';
	macro_test( !check_option_lead_cmd( arg_options.lead_cmd ), 17 );

	arg_options.lead_cmd = '1';
	macro_test( !check_option_lead_cmd( arg_options.lead_cmd ), 18 );

	arg_options.lead_cmd = '!';
	macro_test( !check_option_lead_cmd( arg_options.lead_cmd ), 19 );


	/* Tests 20 à 33 : check_option_display_meth */

	arg_options.display_meth = 'A';
	macro_test( check_option_display_meth( arg_options.display_meth ), 20 );

	arg_options.display_meth = 'a';
	macro_test( check_option_display_meth( arg_options.display_meth ), 21 );

	arg_options.display_meth = 'B';
	macro_test( check_option_display_meth( arg_options.display_meth ), 22 );

	arg_options.display_meth = 'b';
	macro_test( check_option_display_meth( arg_options.display_meth ), 23 );

	arg_options.display_meth = 'Q';
	macro_test( check_option_display_meth( arg_options.display_meth ), 24 );

	arg_options.display_meth = 'q';
	macro_test( check_option_display_meth( arg_options.display_meth ), 25 );

	arg_options.display_meth = 'R';
	macro_test( check_option_display_meth( arg_options.display_meth ), 26 );

	arg_options.display_meth = 'r';
	macro_test( check_option_display_meth( arg_options.display_meth ), 27 );

	arg_options.display_meth = 'C';
	macro_test( !check_option_display_meth( arg_options.display_meth ), 28 );

	arg_options.display_meth = 'c';
	macro_test( !check_option_display_meth( arg_options.display_meth ), 29 );

	arg_options.display_meth = 'S';
	macro_test( !check_option_display_meth( arg_options.display_meth ), 30 );

	arg_options.display_meth = 's';
	macro_test( !check_option_display_meth( arg_options.display_meth ), 31 );

	arg_options.display_meth = '1';
	macro_test( !check_option_display_meth( arg_options.display_meth ), 32 );

	arg_options.display_meth = '!';
	macro_test( !check_option_display_meth( arg_options.display_meth ), 33 );


	/* Tests 34 à 39 : check_option_wait_time */

	arg_options.wait_time = 'A';
	macro_test( check_option_wait_time( arg_options.wait_time ), 34 );

	arg_options.wait_time = 'K';
	macro_test( check_option_wait_time( arg_options.wait_time ), 35 );

	arg_options.wait_time = 'L';
	macro_test( !check_option_wait_time( arg_options.wait_time ), 36 );

	arg_options.wait_time = 'a';
	macro_test( !check_option_wait_time( arg_options.wait_time ), 37 );

	arg_options.wait_time = '1';
	macro_test( !check_option_wait_time( arg_options.wait_time ), 38 );

	arg_options.wait_time = '!';
	macro_test( !check_option_wait_time( arg_options.wait_time ), 39 );


	/* Tests 41 à 46: check_option_lag_cmd */

	arg_options.lag_cmd = 'A';
	macro_test( check_option_lag_cmd( arg_options.lag_cmd ), 40 );

	arg_options.lag_cmd = 'L';
	macro_test( !check_option_lag_cmd( arg_options.lag_cmd ), 41 );

	arg_options.lag_cmd = 'a';
	macro_test( !check_option_lag_cmd( arg_options.lag_cmd ), 42 );

	arg_options.lag_cmd = 'l';
	macro_test( !check_option_lag_cmd( arg_options.lag_cmd ), 43 );

	arg_options.lag_cmd = '1';
	macro_test( !check_option_lag_cmd( arg_options.lag_cmd ), 44 );

	arg_options.lag_cmd = '!';
	macro_test( !check_option_lag_cmd( arg_options.lag_cmd ), 45 );



	/* Tests 46 à 55 : check_option
	 * Ces lignes testent en même temps la fonction is_letter_between() */

	macro_test( check_option( 'A', 'A', 'A' ), 46 );
	macro_test( !check_option( 'A', 'B', 'Z' ), 47 );
	macro_test( check_option( 'a', 'a', 'a' ), 48 );
	macro_test( !check_option( 'a', 'b', 'z' ), 49 );
	macro_test( !check_option( '1', 'A', 'Z' ), 50 );
	macro_test( !check_option( '1', 'a', 'z' ), 51 );
	macro_test( !check_option( 'a', '1', '9' ), 52 );
	macro_test( !check_option( '!', 'A', 'Z' ), 53 );
	macro_test( !check_option( '!', 'a', 'z' ), 54 );

	/* Tests 55 à 58 : is_letter */

	macro_test( is_letter( 'a' ), 55 );
	macro_test( is_letter('A'), 56 );
	macro_test( !is_letter( '1' ), 57 );
	macro_test( !is_letter('!'), 58 );


	/* Tests 59 à 60 : check_arguments */

	arg_options.page = 0;
	arg_options.lead_cmd = 0;
	arg_options.display_meth = 0;
	arg_options.wait_time = 0;
	arg_options.lag_cmd = 0;
	arg_options.priority = 0;
	strcpy(text, "Message de test" );
	macro_test( !check_arguments( arg_options, text ), 59 );

	arg_options.page = 'A';
	arg_options.lead_cmd = 'A';
	arg_options.display_meth = 'A';
	arg_options.wait_time = 'A';
	arg_options.lag_cmd = 'A';
	arg_options.priority = '1';
	strcpy(text, "Hello" );
	macro_test( check_arguments( arg_options, text ), 60 );

	return EXIT_SUCCESS;

}


int main(){

	compt = 0;
	check_arguments_tests();
	printf(" %d tests sur 60 réussis.\n", compt );
	return EXIT_SUCCESS;

}
