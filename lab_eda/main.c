#include <stdio.h>
#include "funciones.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int main() {
    Player *player = init_character(); // Inicializamos al personaje
    printf("\n¡Bienvenido, %s!\n", player->name);

    // Mostramos las habilidades disponibles para que el jugador seleccione
    Ability *abilities = init_abilities();
    //printf("Habilidades disponibles:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", abilities[i].description);
    }     
    // El jugador selecciona sus habilidades
    //printf("\nSeleccione 4 de las 5 habilidades anteriores:\n");
    Ability *selected_abilities = malloc(4 * sizeof(Ability)); // Creamos un array dinámico para almacenar las habilidades seleccionadas
    if (selected_abilities == NULL) {
        printf("Error de asignación de memoria.\n");
        exit(1);
    }

    for (int i = 0; i < 4; i++) {
        int choice;
        printf("Habilidad %d: ", i );
        scanf("%d", &choice);
        selected_abilities[i] = abilities[choice - 1]; // Se resta 1 porque el índice comienza desde 0
    }

    // Mostramos las habilidades seleccionadas por el jugador
   //printf("\nHabilidades seleccionadas:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\n", selected_abilities[i].description);
    }

    // Liberamos la memoria asignada
    free(player);
    free(abilities);
    free(selected_abilities);
}

