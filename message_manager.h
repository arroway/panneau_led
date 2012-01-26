/**
 * @file message_manager.h
 * @brief Fonctions pour mettre en forme des trames
 * 
 * @author Jacquot V.
 * @version 0.2
 * @date 10/04/11
 **/


#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

/**
 * @def MAX_LIST
 * @brief Nombre maximum de messages dans une liste, ne doit pas exceder 256
 **/
#define MAX_LIST 10

/**
 * @fn char build_message(struct_option options, char* text, char* target)
 * @brief Met en forme une trame à partir du texte et des options
 *
 * @param options Options a envoyer au panneau
 * @param message Texte a envoyer au panneau
 * @param target Tableau destine a contenir la trame
 * @return 0 si reussite, 1 si échec
 **/
char build_message(struct struct_option opt, const char* text, char* target);

/**
 * @fn char add_to_list(const char* line, const char* filename, unsigned char max)
 * @brief Ajoute une ligne a la fin d'un fichier en respectant un nombre max de lignes
 *
 * @param line Ligne a ajouter
 * @param file Chemin du fichier dans lequel ajouter la ligne
 * @param max Nombre maximum de lignes dans le fichier
 * @return 0 si reussite, 1 si échec
 **/
char add_to_list(const char* line, const char* filename, unsigned char max);

/**
 * @fn char add_frame(struct struct_option opt, const char* text, char priority)
 * @brief Ajoute un message dans les fichiers de stockage et de logs
 *
 * @param options Options d'affichage
 * @param message Texte a afficher
 * @param priority Priorite d'affichage du message
 * @return 0 si reussite, 1 si échec
 **/
char add_frame(struct struct_option opt, const char* text, char priority);

/**
 * @fn unsigned int lines(FILE* file)
 * @brief Retourne le nombre de lignes d'un fichier
 * 
 * @param file Fichier dont on compte les lignes
 * @return Le nombre de lignes
 **/
unsigned int lines(FILE* file);

#endif
