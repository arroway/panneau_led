/**
 * @file write_to_port.h
 * @brief Fonctions pour envoyer des trame au panneau
 * 
 * @author Jacquot V.
 * @version 0.3
 * @date 24/0/11
 */


#ifndef WRITE_TO_PORT_H
#define WRITE_TO_PORT_H

#include "board_control.h"


/**
 * @def LENGTH_T
 * @brief Taille max de la trame transmise, doit etre superieure a 34
 */
#define LENGTH_T 255


/**
 * @def LENGTH_R
 * @brief Taille du buffer de reception, doit etre superieure a 5
 */
#define RBUFFER_LENGTH 5


/**
 * @fn char write_to_port(int port, const char *frame)
 * @brief Fonction pour envoyer une trame au panneau et tester le retour
 *
 * @param port Descripteur du port serie
 * @param frame Trame à envoyer au panneau
 * @return Code d'erreur : 0 si reussite, 1 si echec
 */
char write_to_port(int port, const char *frame);


/**
 * @fn char send_to_port(int port, const char* frame)
 * @brief Envoie une trame au panneau
 *
 * @param port Descripteur du port serie
 * @param frame Trame a envoyer sur la serie
 * @return Code d'erreur : 0 si reussite, 1 si echec
 */
char send_to_port(int port, const char* frame);


/**
 * @fn char acknowledgement(int port)
 * @brief Lit la reponse du panneau
 *
 * @param port Descripteur du port serie
 * @return Code d'erreur : 0 si reussite, 1 si probleme de checksum, -1 si pas de reponse
 */
char acknowledgement(int port);


#endif
