/**
 * @file message_manager.c
 * @brief Gestion des messages à envoyer
 *
 * @author Vincent Jacquot
 */

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "write_to_port.h"

#include "message_manager.h"


char build_message(struct struct_option opt, const char* text, char* target)
{
    // Verifions s'il y a assez de place pour le minimum
    if (LENGTH_T < 36) {
        perror("Transmission buffer is too short!\n");
        return 1;
    }

    // Initialisation du debut de la trame a transmettre
    strcpy(target, "<ID01><L1><PA><FE><MA><WC><FE>");

    /**** Modification des options ****/

    // Changement de la page
    target[12] = (opt.page)[0];
    printf("%c\n", target[12]);
    // Changement de l'effet d'apparition
    target[16] = (opt.lead_cmd)[0];
    printf("%c\n", target[16]);
    // Changement de la methode d'affichage
    target[20] = (opt.display_meth)[0];
    printf("%c\n", target[20]);
    // Changement du temps d'attente
    target[24] = (opt.wait_time)[0];
    printf("%c\n", target[24]);
    // Changement de l'effet de disparition
    target[28] = (opt.lag_cmd)[0];
    printf("%c\n", target[28]);

    /**********************************/
    
    // Longueur max reservee au texte
    size_t max_length = LENGTH_T - 36;

    // Ajout du texte
    // Le texte est tronqué s'il est trop grand
    strncat(target, text, max_length);
    
    // Ajout du checksum
    unsigned char i;
    unsigned char checksum = 0;
    
    for (i = 6; target[i] != '\0'; i++)
        checksum ^= target[i];
        
    // On ecrit le checksum en hexa
    sprintf(&(target[i]), "%02X", checksum);
    
    // Ajout de la fin de la trame
    strcat(target, "<E>");
    
    return 0;
}

char add_to_list(const char* line, const char* filename, unsigned char max)
{
    printf("Adding a line to an exchange file...\n");
    
    int c;
    FILE* file = NULL;
    
    file = fopen(filename, "r+");
    
    // Si le fichier n'existe pas on en cree un nouveau
    if (file == NULL) {
        printf("Creating a new exhange file...\n");
        file = fopen(filename, "w");
    }
    // Le fichier existe deja, il faut traiter l'ancien contenu
    else {
        // On verifie si le fichier a atteint la taille maximum
        if (lines(file) >= max) {
            
            unsigned int i = 0;
            char buffer[max*LENGTH_T];
        
            // On se place apres la premiere ligne
            rewind(file);
            while(1) {
                c = getc(file);
                if (c == EOF || c == '\n')
                    break;
            }
            // On sauve tout ce qui est apres la premiere ligne
            while(1) {
                c = getc(file);
                
                if (c == EOF)
                    break;
                else {
                    buffer[i++] = c;
                }
            }
            buffer[i] = '\0';
            // On reecrit le buffer en debut de fichier supprimant ainsi la premiere ligne
            fclose(file);
            fopen(filename, "w");
            fputs(buffer, file);
        }
        else {
            // On se place en fin de fichier
            rewind(file);
            while(1) {
                c = getc(file);
                if (c == EOF)
                    break;
            }
        }
    }

    // Erreur lors de la creation de fichier
    if (file == NULL) {
        perror("add_to_list unable to create file: ");
        return 1;
    }
    
    fputs(line, file);
    fputc('\n', file);
    
    fclose(file);
    
    return 0;
}

char add_frame(struct struct_option opt, const char* text, char priority)
{
    char buffer_frame[LENGTH_T];
    
    priority -= 48;
    
    if (build_message(opt, text, buffer_frame) != 0) {
        perror("Error while building frame!");
        return 1;
    }
    
    if (priority == 0) {
        if (add_to_list(text, "messages_0.txt", MAX_LIST) != 0) {
            perror("Error while adding a message to messages_0.txt!");
            return 1;
        }
        if (add_to_list(buffer_frame, "frames_0.txt", MAX_LIST) != 0) {
            perror("Error while adding a frame to frames_0.txt!");
            return 1;
        }
    }
    else if (priority == 1) {
        if (add_to_list(text, "messages_1.txt", MAX_LIST) != 0) {
            perror("Error while adding a message to messages_1.txt!");
            return 1;
        }
        if (add_to_list(buffer_frame, "frames_1.txt", MAX_LIST) != 0) {
            perror("Error while adding a frame to frames_1.txt!");
            return 1;
        }
    }
    else {
        printf("Warning : priority : %c\n", priority);
        perror("Abnormal priority!");
        return 1;
    }
    
    return 0;
}

unsigned int lines(FILE* file)
{
    char c;
    unsigned int l = 0;
    
    while(1) {
        c = getc(file);
        if (c == EOF)
            break;
        else if (c == '\n')
            l++;
    }
    
    return l;
}
