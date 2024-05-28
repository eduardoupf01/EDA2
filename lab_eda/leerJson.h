#include <stdio.h>
#include "funciones.h"
#include "Queue.h"
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h> 

Ability* load_abilities(const char* filename, int* count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    char buffer[4096];
    size_t len = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);
    buffer[len] = '\0';

    cJSON *json = cJSON_Parse(buffer);
    if (!json) {
        printf("Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        return NULL;
    }

    cJSON *abilities_json = cJSON_GetObjectItemCaseSensitive(json, "abilities");
    if (!cJSON_IsArray(abilities_json)) {
        printf("Error: Expected an array of abilities.\n");
        cJSON_Delete(json);
        return NULL;
    }

    *count = cJSON_GetArraySize(abilities_json);
    Ability* abilities = malloc(*count * sizeof(Ability));
    if (!abilities) {
        printf("Error allocating memory for abilities.\n");
        cJSON_Delete(json);
        return NULL;
    }

    int index = 0;
    cJSON *ability_json = NULL;
    cJSON_ArrayForEach(ability_json, abilities_json) {
        cJSON *name = cJSON_GetObjectItemCaseSensitive(ability_json, "name");
        cJSON *description = cJSON_GetObjectItemCaseSensitive(ability_json, "description");
        cJSON *type = cJSON_GetObjectItemCaseSensitive(ability_json, "type");
        cJSON *duration = cJSON_GetObjectItemCaseSensitive(ability_json, "duration");
        cJSON *mod_att = cJSON_GetObjectItemCaseSensitive(ability_json, "mod_att");
        cJSON *mod_def = cJSON_GetObjectItemCaseSensitive(ability_json, "mod_def");
        cJSON *mod_hp = cJSON_GetObjectItemCaseSensitive(ability_json, "mod_hp");

        if (cJSON_IsString(name) && (name->valuestring != NULL)) {
            strncpy(abilities[index].name, name->valuestring, sizeof(abilities[index].name) - 1);
        }
        if (cJSON_IsString(description) && (description->valuestring != NULL)) {
            strncpy(abilities[index].description, description->valuestring, sizeof(abilities[index].description) - 1);
        }
        if (cJSON_IsString(type) && (type->valuestring != NULL)) {
            strncpy(abilities[index].type, type->valuestring, sizeof(abilities[index].type) - 1);
        }
        if (cJSON_IsNumber(duration)) {
            abilities[index].duration = duration->valueint;
        }
        if (cJSON_IsNumber(mod_att)) {
            abilities[index].mod_att = mod_att->valueint;
        }
        if (cJSON_IsNumber(mod_def)) {
            abilities[index].mod_def = mod_def->valueint;
        }
        if (cJSON_IsNumber(mod_hp)) {
            abilities[index].mod_hp = mod_hp->valueint;
        }
        index++;
    }

    cJSON_Delete(json);
    return abilities;
}

// Función para cargar enemigos desde un archivo JSON
Enemy* load_enemies(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    char buffer[4096];
    size_t len = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);
    buffer[len] = '\0';

    cJSON *json = cJSON_Parse(buffer);
    if (!json) {
        printf("Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        return NULL;
    }

    cJSON *enemies_json = cJSON_GetObjectItemCaseSensitive(json, "enemies");
    if (!cJSON_IsArray(enemies_json)) {
        printf("Error: Expected an array of enemies.\n");
        cJSON_Delete(json);
        return NULL;
    }

    Enemy* enemies = malloc(cJSON_GetArraySize(enemies_json) * sizeof(Enemy));
    if (!enemies) {
        printf("Error allocating memory for enemies.\n");
        cJSON_Delete(json);
        return NULL;
    }

    int index = 0;
    cJSON *enemy_json = NULL;
    cJSON_ArrayForEach(enemy_json, enemies_json) {
        cJSON *name = cJSON_GetObjectItemCaseSensitive(enemy_json, "name");
        cJSON *p_att = cJSON_GetObjectItemCaseSensitive(enemy_json, "p_att");
        cJSON *p_def = cJSON_GetObjectItemCaseSensitive(enemy_json, "p_def");
        cJSON *p_hp = cJSON_GetObjectItemCaseSensitive(enemy_json, "p_hp");
        cJSON *abilities = cJSON_GetObjectItemCaseSensitive(enemy_json, "abilities");

        if (cJSON_IsString(name) && (name->valuestring != NULL)) {
            strncpy(enemies[index].name, name->valuestring, sizeof(enemies[index].name) - 1);
        }
        if (cJSON_IsNumber(p_att)) {
            enemies[index].p_att = p_att->valueint;
        }
        if (cJSON_IsNumber(p_def)) {
            enemies[index].p_def = p_def->valueint;
        }
        if (cJSON_IsNumber(p_hp)) {
            enemies[index].p_hp = p_hp->valueint;
        }

        int ability_index = 0;
        cJSON *ability_json = NULL;
        cJSON_ArrayForEach(ability_json, abilities) {
            if (cJSON_IsString(ability_json) && (ability_json->valuestring != NULL)) {
                strncpy(enemies[index].abilities[ability_index].name, ability_json->valuestring, sizeof(enemies[index].abilities[ability_index].name) - 1);
                ability_index++;
            }
        }
        index++;
    }

    cJSON_Delete(json);
    return enemies;
}




char* nombre_enemigos() {
    char* enemigos[] = { "Draugr",
        "Revenant",
        "Trolls",
        "Wulvers",
        "Valkyries",
        "Ancients",
        "Dark Elves",
        "Cerberus",
        "Minotaurs"};
    int x = sizeof(enemigos) / sizeof(enemigos[0]); // Obtener el número de elementos en el array
    int numeroAleatorio = rand() % x; // Generamos un número aleatorio dentro del rango de índices del array
    return enemigos[numeroAleatorio]; // Devolvemos el nombre aleatorio
}



void imprimir_personaje(Player pj){
    printf("Ahora vamos a mostrarte un resumen del personaje!\n");
    printf("Nombre:%s\n",pj.name);
    printf("Hp:%d\n",pj.p_hp);
    printf("Atk:%d\n",pj.p_att);
    printf("Def:%d\n",pj.p_def);
}

Player crear_character(){ // Reservamos memória para el personaje
    
    Player pj;
    int points=300;
    int used_points;
    printf("Creación del personaje: Dispones de 300 puntos de poder que podrás otorgar a las diferentes características del personaje.\n");
    printf("Estas irán aumnentado a medida que avances en la história.\n");
    printf("Introduzca el nombre del personaje:");
    scanf("%s",pj.name);
    printf("Bienvenido %s a esta aventura!\n",pj.name);
    printf("Ahora debes otorgar como mínimo 50 puntos de pode en cada apartado y un máximo de 200 en una característica.\n");
    printf("Introduce los puntos de vida (mínimo 50 y máximo 200): ");
    scanf("%d",&used_points);
    while (used_points<50||used_points>200){
        printf("Cantidad no válida. Debes asignar entre 50 y 200 puntos.\n");
        printf("Introduce los puntos de vida (mínimo 50 y máximo 200):");
        scanf("%d",&used_points);
    }
    points=points-used_points;
    pj.p_hp=used_points;
    
    printf("Dispones de %d puntos.\n",points);
    printf("Introduce los puntos de ataque (mínimo 50 y máximo %d):",points-50);
    scanf("%d",&used_points);
    while (used_points<50 || used_points>points-50){
        printf("Cantidad no válida. Debes asignar entre 50 y %d puntos.\n",points-50);
        printf("Introduce los puntos de ataque (mínimo 50 y máximo %d):",points-50 );
        scanf("%d",&used_points);   
    }
    points=points-used_points;
    pj.p_att=used_points;
    

    printf("Dispones de %d puntos.\n",points);
    printf("Introduce los puntos de defensa (mínimo 50 y máximo %d):",points);
    scanf("%d",&used_points);
    while (used_points<50 || used_points>points){
        printf("Cantidad no válida. Debes asignar entre 50 y %d puntos.\n",points);
        printf("Introduce los puntos de defensa (mínimo 50 y máximo %d):",points);
        scanf("%d",&used_points);   
    }
    points=points-used_points;
    pj.p_def=used_points;
    imprimir_personaje(pj);
   
    
    while (points > 0) {
        printf("Dispones de %d puntos\n",points);
        char respuesta;
        printf("¿Desea gastar los puntos restantes? (S/N): ");
        scanf(" %c", &respuesta);
        if (respuesta == 'S' || respuesta == 's') {
            int opcion;
            printf("Seleccione el atributo en el que desea gastar los puntos restantes:\n");
            printf("1. Puntos de Vida\n");
            printf("2. Puntos de Ataque\n");
            printf("3. Puntos de Defensa\n");
            printf("Opción: ");
            scanf("%d", &opcion);
           
            switch (opcion) {
                case 1:
                    printf("Introduce los puntos adicionales de vida (máximo %d): ", points);
                    scanf("%d", &used_points);
                    while (used_points>points)
                    {
                    printf("Introduce los puntos adicionales de vida (máximo %d): ", points);
                    scanf("%d", &used_points);  
                    }
                    
                    pj.p_hp += used_points;
                    points-=used_points;
                    
                    imprimir_personaje(pj);
                         
                    break;
                case 2:
                    printf("Introduce los puntos adicionales de ataque (máximo %d): ", points);
                    scanf("%d", &used_points);
                    while (used_points>points)
                    {
                    printf("Introduce los puntos adicionales de ataque (máximo %d): ", points);
                    scanf("%d", &used_points);  
                    }
                    
                    
                    pj.p_att += used_points;
                    points-=used_points;
                    
                    imprimir_personaje(pj);

                    break;
                case 3:
                    printf("Introduce los puntos adicionales de defensa (máximo %d): ", points);
                    scanf("%d", &used_points);
                    while (used_points>points)
                    {
                    printf("Introduce los puntos adicionales de defensa (máximo %d): ", points);
                    scanf("%d", &used_points);  
                    }
                    
                    pj.p_def += used_points;
                    points-=used_points;
                    
                    imprimir_personaje(pj);
                     
                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
            
            }
        } 
        else if (respuesta == 'N' || respuesta == 'n'){ 
             imprimir_personaje(pj);                                                                                                                                              
            
        } 
    }
    return pj;
 }