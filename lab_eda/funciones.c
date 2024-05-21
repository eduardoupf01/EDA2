#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>
#include <string.h>

// Hacemos que el array que esta enforma global sea local del archivo, no acceso desde otro archivo
/*
char nombre_enemigos(){
    char enemigos={yu}
    int x=sizeof(enemigos);
    int numeroAleatorio=0+rand()%(x-0+1);
    return enemigos[numeroAleatorio];
 
    }
*/
static char *descriptions[] = {
    "1. Healer (max HP)",
    "2. Physical boost",
    "3. Firewall",
    "4. Zap (electric)",
    "5. Waterball"
};

static char *enemy_abilities[] = {
    "1. Fire Punch",
    "2. Direct Impact",
    "3. Bomb"
};

// Creamos la función para implementar las habilidades 
Ability *init_abilities(){ // reservamos memória para las 5 habilidades 
    Ability *abilities = malloc(5 * sizeof(Ability));
    if(abilities == NULL){ // Hacemos úso del if para asegurarnos que no hay ningún error con la memória
        printf("Hay un error de memória");
        exit(1); // Si devuelve 1 significa que se ha ejecutado con éxito este error
    } 
    char *abilities_names[] =  {"Skill_1", "Skill_2", "Skill_3", "Skill_4", "Skill_5"};
    char *types_abilities[] = {" Es directo", " Es temporal", " Es directo", " Es directo", " Es directo"};
    int modiffiers_att[] = {0,0,25,15,35}; // Asignmos que habilidades modifican el tipo (ataque)  y cuanto lo incrementan
    int modiffiers_def[] = {0,30,0,0,0}; // Asignmos que habilidades modifican el tipo (defensa) y cuanto lo incrementan
    int modiffiers_hp[] = {10,0,0,0,0}; // Asignmos que habilidades modifican el tipo (vida) y cuanto lo incrementan
    int temp_hability_duration = 2;
    for(int i = 0; i < 5; i++){// Asignamos todas las caraterísticas que tienen las habilidades 
        strcpy(abilities[i].name,abilities_names[i]);
        strcpy(abilities[i].description, descriptions[i]);
        strcpy(abilities[i].type, types_abilities[i]);
        abilities[i].mod_att = modiffiers_att[i];
        abilities[i].mod_def = modiffiers_def[i];
        abilities[i].mod_hp = modiffiers_hp[i];
        if(i == 1){ // Señalizamos que la segunda habilidad es temporal
            abilities[i].duration = 2; // La segunda habilidad dura 2 turnos 
        }else 
            abilities[i].duration = 0; // Si la habilidad es directa su duración es igual a 0   
    }
    
    return abilities;

}

// Creamos el personaje 
Player *init_character(){ // Reservamos memória para el personaje
    Player *character = malloc(sizeof(Player));
    if(character == NULL){// Aseguramos que no haya ningún error en la implementación de la memória
        printf("Hay un error de memória");
        exit(1); // inicializamos con el número 1 si este línea sea ha ejecutado
    }
    printf("Introduzca aqui el ID de su nuevo usuario:\n"); // Pedimos al usuario que ingrese el nombre deseado del personaje
    fgets(character->name,20,stdin); // fgets para aseguranos que no hay problemas con la asignación de strings y copiamos el nombre
    strtok(character->name, "\n"); // Elimina el carácter de nueva línea de fgets
    printf("Abajo vera las stats iniciales de su personaje, que a medida que vaya avanzando podra mejorarlas:\n"); // Indicaciones para ver las stats iniciales
    character->p_att = 10; // Inicializamos los puntos de ataque
    character->p_def = 5; // Inicializamos los puntos de defensa
    character->p_hp = 50; // Inicializamos los puntos de vida
    printf("Puntos de ataque: %i\nPuntos de defensa: %i\nPuntos de vida: %i\n", character->p_att, character->p_def, character->p_hp);
    Ability *abilities = init_abilities();
    for (int i = 0; i < 5; i++) {
        printf("%s\n", abilities[i].description);
    }
    printf("\n");
    printf("Escoga 4 de las 5 habilidades que se le han expuesto anteriormente, pienselo bien y con estrategia");
    printf("\nBuena suerte!\n");
    Ability *select_abilities;
    for (int i = 0; i < 5; i++) {
        scanf("%s",&select_abilities[i]);
    }
}

Enemy *init_enemies(){ // Definimos la función de los enemeigos
    Enemy *enemies = malloc(3 * sizeof(Enemy));
    if (enemies == NULL) {
        printf("Hay un error de memoria");
        exit(1);
    }
    char *enemy_names[] = {"Goblin", "Orc", "Dragon"};
    int p_atts[] = {5, 10, 20};
    int p_defs[] = {2, 5, 10};
    int p_hps[] = {25, 50, 100};
    for (int i = 0; i < 3; i++) {
        strcpy(enemies[i].name, enemy_names[i]);
        enemies[i].p_att = p_atts[i];
        enemies[i].p_def = p_defs[i];
        enemies[i].p_hp = p_hps[i];
    }
    printf("Habilidades del enemigo: %s\n", enemy_abilities[0]);
    printf("Las stats del enemigo: \n");
    printf("Puntos de ataque: %i\nPuntos de defensa: %i\nPuntos de vida: %i\n", enemies[0].p_att, enemies[0].p_def, enemies[0].p_hp);
    return enemies;

}


Decision *select_decision(){
        Decision *decisions = malloc(sizeof(Decision)); // reservamos memoria para los 6 escenarios
    if (decisions == NULL){ // Aseguramos que no haya ningún error con la memória
        printf("Hay un error de memoria");
        exit(1);
    char question1 = {"\nComo piensas avanzar y salir de esta cueva ?\n "};
    strcpy(decisions->question,question1);

    return decisions;

}
}

Option *select_option(){
        Option *options = malloc(6* sizeof(Scenario)); // reservamos memoria para los 6 escenarios
    if (options == NULL){ // Aseguramos que no haya ningún error con la memória
        printf("Hay un error de memoria");
        exit(1);
    }
    char responses = {"\nSigues todo recto y te encuentras una luz al final\n"};
    char responses1 = { "\nPrefieres ir por el camino más oscuro con la esperanza de poder encontrar una salida"};

    strcpy(options->response,responses );
    strcpy(options->response,responses1 );
    
    return options;
}


Scenario *init_scenario(){ // definimos la función del escenario
    Scenario *scenarios = malloc(6* sizeof(Scenario)); // reservamos memoria para los 6 escenarios
    if (scenarios == NULL){
        printf("Hay un error de memoria");
        exit(1);
    }
  char *name_scenarios [] = {"Beggining", "Mithra", "Ruinas de Vandal", "River lake", "Yggdrasil"," Niflheim" };
    char *descript_scenario[] = {
    "Te encuentras en el Beggining, el escenario principal donde la aventura apenas comienza. Es un lugar misterioso lleno de promesas y peligros, rodeado de una densa niebla que oculta sus secretos.",
    "Mithra es un valle sagrado, donde los antiguos dioses dejaron su huella en forma de templos y estatuas. Las leyendas cuentan que aquí es donde el mundo de los dioses se encuentra con el de los mortales.",
    "Las Ruinas de Vandal son un lugar olvidado por el tiempo, donde antaño se alzaba una gran ciudad. Ahora, solo quedan ruinas cubiertas por la maleza y el misterio de un pasado perdido.",
    "En River lake, el agua cristalina refleja el cielo eterno de Asgard. Este lugar tranquilo esconde secretos bajo su superficie serena, donde los ríos fluyen hacia los reinos de los dioses.",
    "Yggdrasil, el Árbol del Mundo, se alza imponente ante ti, sus ramas se extienden hacia los cielos y las raíces se hunden en las profundidades de los nueve mundos. Es el eje que sostiene la existencia misma.",
    "Niflheim, el reino de la niebla eterna y el frío implacable. Aquí, las almas de los malvados son castigadas en un eterno invierno, mientras las sombras acechan entre la niebla espesa."
};

    for (int i = 0; i < 6; i++) {
        strcpy(scenarios[i].name, name_scenarios[i]);
        strcpy(scenarios[i].description, descript_scenario[i]);
    }

    return scenarios;
  
    
}


