#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>
#include <string.h>

// Hacemos que el array que esta enforma global sea local del archivo, no acceso desde otro archivo

static char *descriptions[] = {
    "1. Healer (max HP)",
    "2. Physical boost",
    "3. Firewall",
    "4. Zap (electric)",
    "5. Waterball"
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



