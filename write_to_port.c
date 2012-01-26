/**
 * @file write_to_port.c
 * @brief Envoi des messages au port
 *
 * @author Vincent Jacquot
 */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "board_control.h"

#include "write_to_port.h"


/********* Chaines constantes *********/

// Cette trame debute toute communication avec le panneau
const char start[] = "<ID01><BE>05<E>";
// Cette trame conclut toute communication avec le panneau
const char stop[] = "<ID01><BF>06<E>";

/**************************************/


char write_to_port(int port, const char *frame)
{   
    // Envoi de la trame de depart
    send_to_port(port, start);
        
    // Envoi de la trame de configuration
    send_to_port(port, frame);
            
    // Envoi de la trame de fin
    send_to_port(port, stop);
    
    return 0;
}

char send_to_port(int port, const char *frame)
{
    printf("Sending frame: %s\n", frame);
    
    size_t length = strlen(frame);
    
    if (length > 255) {
        perror("The frame to send is too long!\n");
        return 1;
    }
    
    int n = write(port, frame, length);
    
    if (n != length) {
        perror("Error while writing on serial port: ");
        return 1;
    }
   
    return 0;
}

char acknowledgement(int port)
{
    char buffer[5];
    unsigned char waiting = 0;

    // On essaye 8 fois
    while ((read(port, buffer, 5) == 0) || waiting < 8)
        waiting ++;

    if (waiting >= 8) {
        perror("The board does not respond!");
        return -1;
    }
    else {
        if (!(strcmp(buffer, "ACK")))
            return 0;
        else {
            perror("The board returned NACK!");
            return 1;
        }
    }
}
