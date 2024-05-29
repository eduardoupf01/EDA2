#include <stdio.h>
#include "headers/game.h"

int main() {
    Character player;
    configureCharacter(&player);

    // Initialize scenes
    Scene scenes[4];
    initScenes(scenes);

    // Game loop
    int currentScene = 0;
    int result = 0;
    printf("You are a wizard in search of the legendary wand.\n");
    while (currentScene >= 0 && currentScene < 4) {
        result = playScene(&scenes[currentScene++], &player);
    }

    if (player.hp > 0) {
        printf("Congratulations, you have now the legendary magic wand and completed the game!\n");
        printf("SCENARIOS: NILFHEIM THE LAND OF HIGH ELFS, THE BRIDGE, THE CAVE, THE VILLAGE\n");
        printf("THE GAME: SEARCH OF LEGENDARY WAND");
    } else {
        printf("Game over!\n");
    }

    return 0;
}
