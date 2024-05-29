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
    while (currentScene >= 0 && currentScene < 4) {
        result = playScene(&scenes[currentScene++], &player);
    }

    if (player.hp > 0) {
        printf("Congratulations, you have completed the game!\n");
    } else {
        printf("Game over!\n");
    }

    return 0;
}
