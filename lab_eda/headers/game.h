#ifndef GAME_H
#define GAME_H

typedef struct Skill {
    char name[50];
    int damage;
    int heal;
    int duration; // For temporal skills
} Skill;

typedef struct Enemy {
    char name[50];
    int hp;
    int attack;
    int defense;
    Skill skills[5]; // Assume each enemy can have up to 5 skills
} Enemy;

typedef struct Option {
    char description[255];
    Enemy enemies[3]; // Each option can have 0 to 3 enemies
    int num_enemies;
} Option;

typedef struct Decision {
    char question[255];
    Option options[3]; // Assume each decision can have up to 3 options
    int num_options;
} Decision;

typedef struct Scene {
    char name[50];
    char description[255];
    Decision decision;
} Scene;

typedef struct Character {
    char name[50];
    int hp;
    int attack;
    int defense;
    Skill skills[4]; // Assume each character can select up to 4 skills
} Character;

void initSkills(Skill skills[]);
void initEnemies(Enemy enemies[]);
void initScenes(Scene scenes[]);
void configureCharacter(Character *player);

int playScene(Scene* scene, Character* player);
int combat(Character* player, Enemy* enemy);

void playHumanTurn(Character* player, Enemy* enemy);
void playMachineTurn(Character* player, Enemy* enemy);

#endif
