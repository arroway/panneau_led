#ifndef _CHECK_ARGUMENTS_H
#define _CHECK_ARGUMENTS_H

#include "parse_command_line.h"

/* Check and save display options and text. */
int check_arguments( struct_arg_options , char* );

/* Check validity of text */
int check_text( char* );

/* Check display options. */

int check_option_page( char );

int check_option_lead_cmd( char );

int check_option_display_meth( char );

int check_option_wait_time( char );

int check_option_lag_cmd( char );

int check_option( char, char, char );


/* Save an option if correct to be written in the framework. */
int save_option( char*, char );

/* Check option arguments are letters only */
int is_letter( char );

int is_letter_between( char, char, char );

/* Remove accents and special characters off the text. */
int remove_spec_char( char* );


#endif
