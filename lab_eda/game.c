#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "headers/game.h"
#include "headers/queue.h"

void initSkills(Skill skills[]) {
    // Skill 1: Fireball
    strcpy(skills[0].name, "Fireball");
    skills[0].damage = 30;
    skills[0].heal = 0;
    skills[0].duration = 0;

    // Skill 2: Heal
    strcpy(skills[1].name, "Heal");
    skills[1].damage = 0;
    skills[1].heal = 200;
    skills[1].duration = 0;

    // Skill 3: Poison
    strcpy(skills[2].name, "Poison");
    skills[2].damage = 5;
    skills[2].heal = 0;
    skills[2].duration = 3; // Deals 5 damage for 3 turns

    // Skill 4: Ice Blast
    strcpy(skills[3].name, "Ice Blast");
    skills[3].damage = 25;
    skills[3].heal = 0;
    skills[3].duration = 0;

    // Skill 5: Lightning Strike
    strcpy(skills[4].name, "Lightning Strike");
    skills[4].damage = 400;
    skills[4].heal = 0;
    skills[4].duration = 0;
}

void initEnemies(Enemy enemies[]) {
    // Enemy 1: Goblin
    strcpy(enemies[0].name, "Goblin");
    enemies[0].hp = 100;
    enemies[0].attack = 15;
    enemies[0].defense = 5;
    initSkills(enemies[0].skills);

    // Enemy 2: Troll
    strcpy(enemies[1].name, "Troll");
    enemies[1].hp = 200;
    enemies[1].attack = 30;
    enemies[1].defense = 10;
    initSkills(enemies[1].skills);

    // Enemy 3: Orc
    strcpy(enemies[2].name, "Orc");
    enemies[2].hp = 150;
    enemies[2].attack = 20;
    enemies[2].defense = 8;
    initSkills(enemies[2].skills);

    // Enemy 4: Dragon
    strcpy(enemies[3].name, "Dragon");
    enemies[3].hp = 300;
    enemies[3].attack = 50;
    enemies[3].defense = 25;
    initSkills(enemies[3].skills);

    // Enemy 5: Vampire
    strcpy(enemies[4].name, "Vampire");
    enemies[4].hp = 180;
    enemies[4].attack = 25;
    enemies[4].defense = 12;
    initSkills(enemies[4].skills);
}

void initScenes(Scene scenes[]) {
    // Initialize enemies array
    Enemy allEnemies[5];
    initEnemies(allEnemies);

    // Scenario 1
    strcpy(scenes[0].name, "THE FOREST");
    strcpy(scenes[0].description, "You are in a dark forest. There are three paths ahead.");
    strcpy(scenes[0].decision.question, "Which path do you choose?");
    strcpy(scenes[0].decision.options[0].description, "Take the left path.");
    scenes[0].decision.options[0].num_enemies = 1;
    scenes[0].decision.options[0].enemies[0] = allEnemies[0]; // Goblin

    strcpy(scenes[0].decision.options[1].description, "Take the middle path.");
    scenes[0].decision.options[1].num_enemies = 2;
    scenes[0].decision.options[1].enemies[0] = allEnemies[1]; // Troll
    scenes[0].decision.options[1].enemies[1] = allEnemies[2]; // Orc

    strcpy(scenes[0].decision.options[2].description, "Take the right path.");
    scenes[0].decision.options[2].num_enemies = 0;

    scenes[0].decision.num_options = 3;

    // Scenario 2
    strcpy(scenes[1].name, "THE BRIDGE");
    strcpy(scenes[1].description, "You arrive at a mountain pass with a narrow bridge.");
    strcpy(scenes[1].decision.question, "Do you cross the bridge or go around?");
    strcpy(scenes[1].decision.options[0].description, "Cross the bridge.");
    scenes[1].decision.options[0].num_enemies = 3;
    scenes[1].decision.options[0].enemies[0] = allEnemies[3]; // Dragon
    scenes[1].decision.options[0].enemies[1] = allEnemies[1]; // Troll
    scenes[1].decision.options[0].enemies[2] = allEnemies[0]; // Goblin

    strcpy(scenes[1].decision.options[1].description, "Go around the mountain.");
    scenes[1].decision.options[1].num_enemies = 1;
    scenes[1].decision.options[1].enemies[0] = allEnemies[4]; // Vampire

    scenes[1].decision.num_options = 2;

    // Scenario 3
    strcpy(scenes[2].name, "THE CAVE");
    strcpy(scenes[2].description, "You find a hidden cave.");
    strcpy(scenes[2].decision.question, "Do you enter the cave or continue on the path?");
    strcpy(scenes[2].decision.options[0].description, "Enter the cave.");
    scenes[2].decision.options[0].num_enemies = 2;
    scenes[2].decision.options[0].enemies[0] = allEnemies[2]; // Orc
    scenes[2].decision.options[0].enemies[1] = allEnemies[3]; // Dragon

    strcpy(scenes[2].decision.options[1].description, "Continue on the path.");
    scenes[2].decision.options[1].num_enemies = 0;

    scenes[2].decision.num_options = 2;

    // Scenario 4
    strcpy(scenes[3].name, "THE VILLAGE");
    strcpy(scenes[3].description, "You reach a peaceful village.");
    strcpy(scenes[3].decision.question, "Do you explore the village or rest at the inn?");
    strcpy(scenes[3].decision.options[0].description, "Explore the village.");
    scenes[3].decision.options[0].num_enemies = 0;

    strcpy(scenes[3].decision.options[1].description, "Rest at the inn.");
    scenes[3].decision.options[1].num_enemies = 0;

    scenes[3].decision.num_options = 2;
}

void configureCharacter(Character *player) {
    printf("Enter character name: ");
    scanf("%s", player->name);
    player->hp = 100;
    player->attack = 20;
    player->defense = 10;
    // Assume skills are pre-initialized in an array
    Skill allSkills[5];
    initSkills(allSkills);
    
    printf("Select up to 4 skills:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, allSkills[i].name);
    }

    int skill_choice;
    for (int i = 0; i < 4; i++) {
        printf("Select skill %d: ", i + 1);
        scanf("%d", &skill_choice);
        if (skill_choice >= 1 && skill_choice <= 5) {
            player->skills[i] = allSkills[skill_choice - 1];
        } else {
            printf("Invalid choice, try again.\n");
            i--;
        }
    }
    printf("\n");
}

int playScene(Scene* scene, Character* player) {
    printf("%s\n", scene->name);
    printf("%s\n", scene->description);
    printf("%s\n", scene->decision.question);
    for (int i = 0; i < scene->decision.num_options; i++) {
        printf("%d. %s\n", i + 1, scene->decision.options[i].description);
    }

    int choice;
    scanf("%d", &choice);
    choice--; // To match array indexing

    if (choice < 0 || choice >= scene->decision.num_options) {
        printf("Invalid choice!\n");
        return -1; // Invalid choice, end game
    }

    Option* selectedOption = &scene->decision.options[choice];
    for (int i = 0; i < selectedOption->num_enemies; i++) {
        int result = combat(player, &selectedOption->enemies[i]);
        if (result == 0) {
            return -1; // Player lost the combat
        }
    }

    // Return the index of the next scene to move to (can be modified as needed)
    printf("You have explored the enviroment, now you have more clues to find the legendary wand.\n\n");
    return choice; // Simplified, you may need a better way to choose next scene
}

void playHumanTurn(Character* player, Enemy* enemy) {
    printf("It is your turn. Choose a skill.\n");
    for (int i = 0; i < 4; i++) {
        printf("[%d] %s (Deals %d damage, Heals %d, Duration %d)\n", i, player->skills[i].name, player->skills[i].damage, player->skills[i].heal, player->skills[i].duration);
    }
    printf("\n");

    int choice;
    scanf("%d", &choice);
    if (choice >= 0 && choice < 4) {
        Skill skill = player->skills[choice];
        int actual_damage = skill.damage > enemy->defense ? skill.damage - enemy->defense : 0;
        enemy->hp -= actual_damage;
        player->hp += skill.heal; // Apply healing if any
        printf("You chose %s\n", skill.name);
        printf("    You attacked with %s: %d\n", skill.name, skill.damage);
        printf("    Enemy defended with: %d\n", enemy->defense);
        printf("    Enemy damage taken: %d\n", actual_damage);
        printf("Now the enemy has %dHP remaining.\n\n", enemy->hp);
    } else {
        printf("Invalid choice!\n");
    }
}

void playMachineTurn(Character* player, Enemy* enemy) {
    printf("Enemy's turn!\n");
    // int skill_index = rand() % 5; // Assume each enemy has 5 skills
    // Skill skill = enemy->skills[skill_index];
    int actual_damage = enemy->attack > player->defense ? enemy->attack - player->defense : 0;
    player->hp -= actual_damage;
    // enemy->hp += skill.heal; // Apply healing if any
    printf("Enemy attacked");
    printf("    Enemy attacked with: %d\n", enemy->attack);
    printf("    You defended with: %d\n", player->defense);
    printf("    Your damage taken: %d\n", actual_damage);
    printf("Now you have %dHP remaining.\n\n", player->hp);
}


// Alternar turnos
int combat(Character* player, Enemy* enemy) {
    printf("\nYou encounter an enemy: %s\n", enemy->name);
    printf("    ATK -> %d\n", enemy->attack);
    printf("    DEF -> %d\n", enemy->defense);
    printf("    HP -> %d\n", enemy->hp);

    Queue *turnQueue = createQueue();

    // Alternating turns: 0 for player, 1 for enemy
    for (int i = 0; i < 10; i++) {
        enqueue(turnQueue, i % 2); // Alternating turns
    }

    while (player->hp > 0 && enemy->hp > 0) {
        int turn = dequeue(turnQueue);
        if (turn == 0) {
            playHumanTurn(player, enemy);
        } else {
            playMachineTurn(player, enemy);
        }
    }

    freeQueue(turnQueue);
    return player->hp > 0 ? 1 : 0;
}
