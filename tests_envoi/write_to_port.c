#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "write_to_port.h"


/********* Chaines constantes *********/

// Cette trame debute toute communication avec le panneau
char start[] = "<ID00><BE>05<E>";
// Cette trame conclut toute communication avec le panneau
char stop[] = "<ID00><BF>06<E>";

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
    size_t length = strlen(frame);
    
    if (length > 255) {
        perror("The frame to send is too long!\n");
        return 1;
    }
    
    int n = write(port, frame, length);
    
    if (n != length) {
        perror("Error while writing on serial port  : ");
        return 1;
    }
    
    return 0;
}
