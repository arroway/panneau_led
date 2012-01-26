#ifndef _PARSE_H
#define _PARSE_H

#include <stdio.h>
#include <errno.h>
#include <getopt.h>
#include "board_control.h"

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
