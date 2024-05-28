#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include <time.h>


Ability* randomSkill(Enemy* enemy) {
    srand(time(NULL)); // Inicializamos la semilla para la generación de números aleatorios
    int index = rand() % 4; // Generamos un índice aleatorio entre 0 y 3 (4 habilidades en total)
    return &(enemy->abilities[index]);
}

void playMachineTurn(Player* player, Enemy* enemy) {
    Ability* abilities = randomSkill(enemy);
    
    int totalAtk = enemy->p_att + abilities->mod_att;
    int damage = totalAtk - player->p_def;


    if (damage < 0) {
        damage = 0; // El daño no puede ser negativo
    }

    player->p_hp -= damage;

    if (player->p_hp < 0) {
        player->p_hp = 0; // La HP del jugador no puede ser negativa
    }

    printf("El enemigo ha usado %s. Te causó %d puntos de daño. HP del jugador restante: %d\n",
           abilities->name, damage, player->p_hp);
}   

void playHumanTurn(Player* player, Enemy* enemy) {
    int choice = 0;
    while (choice < 1 || choice > 4) {
        printf("Selecciona tu habilidad de ataque:\n");
        for (int i = 0; i < 4; i++) {
            printf("%d. %s: %s\n", i + 1, player->abilities[i]->name, player->abilities[i]->description);
        }

        scanf("%d", &choice);

        if (choice < 1 || choice > 4) {
            printf("Selección inválida. Por favor elige una habilidad válida.\n");
        }
    }

    // Ajustar el índice de la elección del usuario
    Ability* selectedAbility = player->abilities[choice - 1];

    // Calcular el daño infligido
    int totalAtk = player->p_att + selectedAbility->mod_att;
    int damage = totalAtk - enemy->p_def;

    if (damage < 0) {
        damage = 0; // El daño no puede ser negativo
    }

    enemy->p_hp -= damage;

    if (enemy->p_hp < 0) {
        enemy->p_hp = 0; // La HP del enemigo no puede ser negativa
    }

    printf("Has usado %s. Causaste %d puntos de daño. HP del enemigo restante: %d\n",
           selectedAbility->name, damage, enemy->p_hp);
}