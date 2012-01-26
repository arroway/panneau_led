/**
 * @file parse_command_line.c
 * @brief Fonctions pour parser la ligne de commande
 *
 * @author Stéphanie Ouillon
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>
#include "parse_command_line.h"
#include "board_control.h"


//BUG : s'il manque une option, ça bug


/**
 * @fn void help( void );
 * @brief Fonction d'aide
 *
 * Fonction d'aide affichant la syntaxe à utiliser pou rlancer le programme et
 * indiquer les différentes options d'affichage du message sur le panneau.
 *
 */

void help( void ){

	//printf( "%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR,Tutorial_VERSION_MINOR );

    printf("Usage: Board_Control -p [param] -l [param] -t [param] -g [param] <message>\n");
    printf("WARNING: The text message can't contain special charcaters such as 'é', 'è', 'â', etc,\n");
    printf("but characters of punctuation are allowed.\n");
    printf("Parameters are :\n");
    printf("\t -h Display this help text and exit.\n" );
    printf("\t -p Choose the page where the message will be stored.\n");
    printf("\t\t Choose a capital letter [A-Z].\n\n");

    printf("\t -l Denotes the leading command of this page.\n");
    printf("\t\t A = Immediate  (Image will be immediately appeared)\n");
    printf("\t\t B = Xopen (Image will be shown from center and extend to 4 side) \n");
    printf("\t\t C = Curtain UP (Image will be shown one line by one line from bottom to top)\n");
    printf("\t\t D = Curtain Down(Image will be shown one line by one line from  Top to Bottom \n");
    printf("\t\t E = Scroll Left (Image will be scrolled from Right to Left) \n");
    printf("\t\t F = Scroll Right (Image will be scrolled from Right to Left) \n");
    printf("\t\t G = Vopen (Image will be shown from center to top and Bottom one line by one line) \n");
    printf("\t\t H = Vclose(Image will be shown from Top and Bottom  to Center one line by one line.) \n");
    printf("\t\t I = Scroll Up(Image will be scroll from Bottom to Top)\n");
    printf("\t\t J =  Scroll Down ((Image will be scrolled from Bottom to Top) \n");
    printf("\t\t K = Hold (Previous Screen will be kept) \n");
    printf("\t\t L = Snow ( Pixels will be dropped down from top and stack up to build the image)\n");
    printf("\t\t M = Twinkle (a blank diagonal line will be scrolling on the image)\n");
    printf("\t\t N = Block Move (8 pixel width display block will be moved from right to left one by one)\n");
    printf("\t\t P = Random (Random Pixel will be appeared to build the image)\n");
    printf("\t\t Q = Pen writing \"Hello World\" \n");
    printf("\t\t R =  Pen writing \"Welcome\" \n");
    printf("\t\t S = Pen writing \"A plus\" \n");

    printf("\t -d Denotes the Display method while waiting & effect speed.\n");
    printf("\t\t A = FAST - Normal (Display stay steady while waiting).\n");
    printf("\t\t B = FAST - Blinking (Display Blinking while waiting) .\n");
    printf("\t\t Q = MIDDLE-FAST - Normal (Display stay steady while waiting) .\n");
    printf("\t\t R = MIDLLE-FAST - Blinking (Display Blinking while waiting).\n");
    printf("\t\t a = MIDDLE-SLOW - Normal (Display stay steady while waiting).\n");
    printf("\t\t b = MIDDLE-SLOW - Blinking (Display Blinking while waiting).\n");
    printf("\t\t q = SLOWEST - Normal (Display stay steady while waiting).\n");
    printf("\t\t r = SLOWEST - Blinking (Display Blinking while waiting).\n\n");


    printf("\t -t Denotes the waiting time.\n");
    printf("\t\t A = 0.5 sec.\n");
    printf("\t\t B = 1 sec.\n");
    printf("\t\t C = 2 sec.\n");
    printf("\t\t D = 3 sec.\n");
    printf("\t\t ..\n");
    printf("\t\t K = 10 sec.\n\n");

    printf("\t -g Denotes the lagging command of this page.\n");
    printf("\t\t A = Immediate  (Image will be immediately appeared)\n");
    printf("\t\t B = Xopen (Image will be shown from center and extend to 4 side) \n");
    printf("\t\t C = Curtain UP (Image will be shown one line by one line from bottom to top)\n");
    printf("\t\t D = Curtain Down(Image will be shown one line by one line from  Top to Bottom \n");
    printf("\t\t E = Scroll Left (Image will be scrolled from Right to Left) \n");
    printf("\t\t F = Scroll Right (Image will be scrolled from Right to Left) \n");
    printf("\t\t G = Vopen (Image will be shown from center to top and Bottom one line by one line) \n");
    printf("\t\t H = Vclose(Image will be shown from Top and Bottom  to Center one line by one line.) \n");
    printf("\t\t I = Scroll Up(Image will be scroll from Bottom to Top)\n");
    printf("\t\t J =  Scroll Down ((Image will be scrolled from Bottom to Top) \n");
    printf("\t\t K = Hold (Previous Screen will be kept) \n");

}


/**
 * @fn int parse_command_line( int argc, char** argv );
 * @brief Fonction pour parser la ligne de commande
 *
 * @param argc nombre d'arguments sur la ligne de commande
 * @param argv chaînes de texte sur la ligne de commande
 *
 *
 * Fonction pour parser la ligne de commande.
 * On utilise la librairy C standard getopt.h pour parser la ligne de commande.
 */

int parse_command_line(int argc, char **argv){

	if ( argc < 2 ){
		help();
		return EXIT_FAILURE;
	}

	/* We store the result of the getop_long() call there. */

	int opt = -2;
	int *longIndex = 0;
	int compt = 1;

	/* Initialisation des éléments de la structure arg_options*/

	arg_options.page = 0;
	arg_options.lead_cmd = 0;
	arg_options.display_meth = 0;
	arg_options.wait_time = 0;
	arg_options.lag_cmd = 0;
    arg_options.priority = 0;

    static const char *option_string = "vhp:l:d:t:g:P:";
	static const struct option long_options[]={

			{"help",		   no_argument,       NULL, 'h'},
			{"page",           required_argument, NULL, 'p'},
			{"lead_cmd",       required_argument, NULL, 'l'},
			{"display_method", required_argument, NULL, 'd'},
			{"wait_time",      required_argument, NULL, 't'},
			{"lag_cmd",        required_argument, NULL, 'g'},
			{"priority",       required_argument, NULL,  'P'},
			{NULL,             no_argument,       NULL,  0 }
	};

		/* getopt_long stores the option index here. */

		while ( optind < 13 ){
			if (
					( arg_options.page == 0 ) ||
					( arg_options.lead_cmd == 0 ) ||
					( arg_options.display_meth == 0 ) ||
					( arg_options.wait_time == 0 ) ||
					( arg_options.lag_cmd == 0 ) ||
					( arg_options.priority == 0 )
				)
			{
		opt = getopt_long( argc, argv, option_string, long_options, longIndex);

		 if ( opt != -1 ){

			 switch( opt ){

				 case 'h':
					help();
					return EXIT_FAILURE;
					break;

				 case 'p' :
					 if ( strlen(optarg) > 1 ){
						 printf("ERROR: l'argument en option de -p est trop long.\n");
						 return EXIT_FAILURE;
					 }
					 strcpy( &arg_options.page, optarg );
					 //printf("arg_options.page : %c\n", arg_options.page);
					 break;

				 case 'l' :
					 if ( strlen(optarg) > 1 ){
						 printf("ERROR: l'argument en option de -l est trop long.\n");
						 return EXIT_FAILURE;
					 }
					 strcpy( &arg_options.lead_cmd, optarg );
					 //printf("arg_options.lead_cmd : %c\n", arg_options.lead_cmd);
					 break;

				 case 'd' :
					 if ( strlen(optarg) > 1 ){
					 	 printf("ERROR: l'argument en option de -d est trop long.\n");
						 return EXIT_FAILURE;
					 }
					 strcpy( &arg_options.display_meth, optarg );
					 //printf("arg_options.display_meth : %c\n", arg_options.display_meth);
					 break;

				 case 't' :
					 if ( strlen(optarg) > 1 ){
					 	 printf("ERROR: l'argument en option de -t est trop long.\n");
						 return EXIT_FAILURE;
					 }
					 strcpy( &arg_options.wait_time, optarg );
					 //printf("arg_options.wait_time : %c\n", arg_options.wait_time);
					 break;

				 case 'g' :
					 if ( strlen(optarg) > 1 ){
					 	 printf("ERROR: l'argument en option de -g est trop long.\n");
					 	return EXIT_FAILURE;
					 }
					 strcpy( &arg_options.lag_cmd, optarg );
					 //printf("arg_options.lag_cmd : %c\n", arg_options.lag_cmd);
					 break;

				 case 'P' :
					 if ( strlen(optarg) > 1 ){
					 	 printf("ERROR: l'argument en option de -P est trop long.\n");
					 	 return EXIT_FAILURE;
					  }
					 strcpy( &arg_options.priority, optarg );
					 //printf("arg_options.priority : %c\n", arg_options.priority);
					 break;

				 default:
					 return EXIT_FAILURE;
					 break;
			}
			 compt += 2;
		 }
		}
		 else { optind = 13 ;
		  }
		}

		 /* IMPORTANT: Pour que le programme enregistre des symboles
		  * tapés sur la ligne de commande tels que ", \, ?, !
		  * il faut que le messge soit mis entre simple quote '' pour
		  * ne pas être interprété par le shell */

		 /* Enregistrer le message s'il y en a un.
		  * On accepte les messages vides. */

		 /* On accepte des messages de longueur inférieur à 140.*/

		 while ( compt < argc ){

			   /* On rajoute des espaces entre les mots enregistrés.
			    * On ne met pas d'espace devant le premier mot du message */

			   if ( ( compt > 13 ) && ( strlen (text) < LENGTH_MAX_TEXT ))

			   strcat( text, " " );
			   strcat( text, argv[optind] );
        	   printf( "Following message is saved :%s .\n", text );
                   optind ++;
   		       compt++ ;
        }

    return EXIT_SUCCESS;

}


