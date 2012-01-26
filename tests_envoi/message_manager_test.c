#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "message_manager_test.h"
#include "message_manager.h"
#include "write_to_port.h"


int main ()
{
    //char input[LENGTH_MAX_TEXT];
    char output[255];
    struct struct_option options;
    
    // Saisie des donnees
    printf("Entrez l'ID du panneau: ");
    scanf("%s", options.id);
    printf("Entrez la page du message: ");
    scanf("%s", options.page);
    printf("Entrez l'effet d'apparition: ");
    scanf("%s", options.lead_cmd);
    printf("Entrez la methode d'affichage: ");
    scanf("%s", options.display_meth);
    printf("Entrez le temps d'attente: ");
    scanf("%s", options.wait_time);
    printf("Entrez l'effet de disparition: ");
    scanf("%s", options.lag_cmd);
    //printf("Entrez le texte a afficher: ");
    //scanf("%s", input);
    
    // Construction de la trame courte
    if (build_message(options, "Shortcat is shrt!", output) == 0)
        // Affichage du resultat
        printf("\nMessage court: %s\n", output);
    else
        printf("Erreur lors de la construction de la trame");
        
    // Construction de la trame trop longue    
    if (build_message(options, "Longcat is loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong!", output) == 0) {
        // Affichage du resultat
        printf("\nMessage trop long: %s\n", output);
        printf("Longueur %d", strlen(output));
    }
    else
        printf("Erreur lors de la construction de la trame");
    
        
    return 0;
    
}
