/**
 * @file send_daemon.h
 * @brief Programme qui envoie au panneau les trames stockees dans des fichiers
 * 
 * @author Jacquot V.
 * @version 0.1
 * @date 11/05/11
 **/

#ifndef SEND_DAEMON_H
#define SEND_DAEMON_H

/**
 * @fn char send_frame(FILE* list, int port)
 * @brief Envoie une trame au panneau
 *
 * @param list Fichier de liste de trames a parcourir
 * @param port Descripteur du port sur lequel on envoie la trame
 * @param line Numero de la ligne du dernier affichage (pour le temps d'affichage)
 * @return 0 si reussite, 1 si échec
 **/
char send_frame(FILE* list, int port, unsigned char *line);

#endif
