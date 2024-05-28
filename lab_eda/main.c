#include <stdio.h>
#include "funciones.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int main() {
    welcome();
    Player *player = init_character(); // Inicializamos al personaje
    printf("\n¡Bienvenido, %s!\n", player->name);

    printf("\n\nPrimer Nivel");
    Scenario *scenario = init_scenario();
    printf("\nTodo joya ");

}