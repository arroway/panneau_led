/**
 * @file open_port.c
 * @brief Ouverture et configuration du port série
 *
 * @author Stéphanie Ouillon
 */

#include <stdio.h>   /* Standard input/output definitions */
#include <stdlib.h>
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

#define PORT "/dev/ttyUSB0"

/**
 * @fn int open_port ( void )
 * @brief Ouverture et configuration du port série
 * @return fd, le file descriptor du port ouvert si aucune erreur, EXIT_FAILURE si
 *  l'ouverture du port à échoué.
 */

int open_port() {

  int fd;
  struct termios options;

  /*Open the port*/

  fd = open( PORT, O_RDWR| O_NOCTTY | O_NDELAY );
  
  if ( fd == -1 ){
    perror(" open_port() : couldn't open the port ");
    exit(1);
  }
  else {
    if ( fcntl( fd, F_SETFL, 0 ) < 0 ){; /* Set flags at 0. */
      perror( "fcntl() failed !\n" );
      exit(1);
    }
  }

  if ( tcgetattr( fd, &options ) < 0 ){
    perror("tcgetattr() failed !\n");
    exit(1);
  }

  /* Configuration of the port
   *
   * baud rate - no parity - raw input 
   */

  /* Set the baud rate : 9600 */
  cfsetispeed( &options, B9600 );
  cfsetospeed ( &options, B9600 );

  /* Enable the receiver and set local mode */
  options.c_cflag |= ( CLOCAL | CREAD );
  
  /* No parity (8,N,1) */
  options.c_cflag &= ~PARENB;  /* Disable parity bit */
  options.c_cflag &= ~CSTOPB;  /* 1 stop bit */
  options.c_cflag &= ~CSIZE;   /* No bit mask for data bits */ 
  options.c_cflag |= CS8;      /* Set 8 data bits */

  /* Choose raw input */
  options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Disable canonical input */
                                                       /* Disable echoing of input and erasing characters */
						       	   	   	   	   	   	   /* Disable SIGINTR, SIGSUP, SIGDSUP, SIGQUIT signals */
  
  /* Set hardware flow control */
  //  options.c_cflag |= CNEW_RTSCTS;
  //  to be corrected if it is necessary.

  if ( fcntl(fd, F_SETFL, FNDELAY) < 0 ){
    perror( "fcntl() failed !\n" );
  }

  /* Set the new options for the port immediately */
  if ( tcsetattr( fd, TCSANOW, &options ) < 0){
    perror( "tcsetattr() failed ! \n" );
    exit(1);   
  }

  return fd; 
}
