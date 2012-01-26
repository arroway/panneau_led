/**
 * @file sender_daemon.c
 * @brief Daemon gérant l'envoi des messages sur le port
 *
 * @author Vincent Jacquot
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "write_to_port.h"
#include "sender_daemon.h"

int main()
{
    FILE* list_1 = fopen("frames_1.txt", "r");
    FILE* list_0 = fopen("frames_0.txt", "r");
    
    int port = open_port();
    
    unsigned char line_1 = 0;
    unsigned char line_0 = 0;
    
    if (list_1 == NULL) {
        perror("Unable to open frames_1.txt: ");
        return 1;
    }
    
    if (list_0 == NULL ) {
        perror("Unable to open frames_0.txt: ");
        return 1;
    }
    
    if (port == EXIT_FAILURE) {
        perror("Unable to open port: ");
        return 1;
    }
    
    nice(10);
    
    while(1) {
        // Sequence d'affichage
        send_frame(list_1, port, &line_1);
        sleep(10 + line_1);
        send_frame(list_0, port, &line_0);
        sleep(10 + line_0);
        send_frame(list_1, port, &line_1);
        sleep(10 + line_1);
    }
    
    return 0;
}

char send_frame(FILE* list, int port, unsigned char *line)
{
    char buffer[256];

    while (fgets(buffer, 256, list) == NULL) {
        rewind(list);
        *line = 0;
    }
    
    // Supression du retour chariot
    buffer[strlen(buffer)-1] = '\0';
    
    write_to_port(port, buffer);
    (*line)++;
    
    return 0;
}
