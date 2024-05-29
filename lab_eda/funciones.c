#include <stdio.h>
    #include "funciones.h"
    #include "Queue.h"
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
        "1. Healer -> Sube los puntos de HP al max",
        "2. Physical boost ->  Menos perdida de hp por ataque recibido",
        "3. Fireball -> Ataque de bola de fuego",
        "4. Zap ->  Descarga electrica",
        "5. Waterball -> Ataque de bola de agua"
    };

    static char *enemy_abilities[] = {
        "1. Fire Punch",
        "2. Direct Impact",
        "3. Bomb"
    };

    char welcome(){
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Bienvenido a este mundo llamado Vinland en el que tendras que superar diferentes enemigos para poder completar el juego\nMucha Suerte! ;)");
        printf("\n--------------------------------------------------------------------------------------------------------------------------------\n\n");
    }
    // Creamos la función para implementar las habilidades 
    Ability *init_abilities(){ // reservamos memória para las 5 habilidades 
        Ability *abilities = malloc(sizeof(Ability));
        if(abilities == NULL){ // Hacemos úso del if para asegurarnos que no hay ningún error con la memória
            printf("Hay un error de memória");
            exit(1); // Si devuelve 1 significa que se ha ejecutado con éxito este error
        } 
        char *types_abilities[] = {" Es directo", " Es temporal", " Es directo", " Es directo", " Es directo"};
        int modiffiers_att[] = {0,0,25,15,35}; // Asignmos que habilidades modifican el tipo (ataque)  y cuanto lo incrementan
        int modiffiers_def[] = {0,30,0,0,0}; // Asignmos que habilidades modifican el tipo (defensa) y cuanto lo incrementan
        int modiffiers_hp[] = {10,0,0,0,0}; // Asignmos que habilidades modifican el tipo (vida) y cuanto lo incrementan
        fgets(abilities->name,20,stdin); // Seleccion de la habilidades por terminal
        if (abilities->name == "Healer"){
            abilities->description[0] = *descriptions[0];
            abilities->type[0] = *types_abilities[0];
            abilities->mod_att = modiffiers_att[0];
            abilities->mod_def = modiffiers_def[0];
            abilities->mod_hp = modiffiers_hp[0];
            abilities->duration = 0;
        }
        if(abilities->name == "Physical Boost"){
            abilities->description[1] = *descriptions[1];
            abilities->type[1] = *types_abilities[1];
            abilities->mod_att = modiffiers_att[1];
            abilities->mod_def = modiffiers_def[1];
            abilities->mod_hp = modiffiers_hp[1];
            abilities->duration = 2;
        }
        if (abilities->name == "Firewall"){
            abilities->description[2] = *descriptions[2];
            abilities->type[2] = *types_abilities[2];
            abilities->mod_att = modiffiers_att[2];
            abilities->mod_def = modiffiers_def[2];
            abilities->mod_hp = modiffiers_hp[2];
            abilities->duration = 0;
        }    
        if (abilities->name == "Zap"){
            abilities->description[3] = *descriptions[3];
            abilities->type[3] = *types_abilities[3];
            abilities->mod_att = modiffiers_att[3];
            abilities->mod_def = modiffiers_def[3];
            abilities->mod_hp = modiffiers_hp[3];
            abilities->duration = 0;
        }
        if (abilities->name == "Waterball"){
            abilities->description[4] = *descriptions[4];
            abilities->type[4] = *types_abilities[4];
            abilities->mod_att = modiffiers_att[4];
            abilities->mod_def = modiffiers_def[4];
            abilities->mod_hp = modiffiers_hp[4];
            abilities->duration = 0;
        }
        


        /*for(int i = 0; i < 5; i++){// Asignamos todas las caraterísticas que tienen las habilidades 
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
        */
        
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
        printf("\nAbajo vera las stats %s iniciales de su personaje, que a medida que vaya avanzando podra mejorarlas:\n",character->name); // Indicaciones para ver las stats iniciales
        character->p_att = 10; // Inicializamos los puntos de ataque
        character->p_def = 5; // Inicializamos los puntos de defensa
        character->p_hp = 50; // Inicializamos los puntos de vida
        printf("Puntos de ataque: %i\nPuntos de defensa: %i\nPuntos de vida: %i\n", character->p_att, character->p_def, character->p_hp);
        //Ability *abilities = init_abilities();
        printf("Habilidades\n");
        for (int i = 0; i < 5; i++) {
            //printf("%s\n", abilities[i].description);
            printf("%s\n", descriptions[i]);
        }
        printf("\n");
        printf("Escoga 4 de las 5 habilidades que se le han expuesto anteriormente, pienselo bien y con estrategia");
        printf("\nBuena suerte!\n");
        //Ability *select_abilities;
        Ability *selected_abs[4];
        for (int i = 0; i < 4; i++) {
            //scanf("%s",&select_abilities[i]);
            character->abilities[i] = init_abilities();
        }
        printf("\nLas habilidades seleccionadas son:\n");
        for (int i = 0; i < 4; i++) {
            //scanf("%s",&select_abilities[i]);
            printf("[%i].%s", i+1, character->abilities[i]);
        }
        return character;
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


    /*Decision *select_decision(){
            Decision *decisions = malloc(sizeof(Decision)); // reservamos memoria para los 6 escenarios
        if (decisions == NULL){ // Aseguramos que no haya ningún error con la memória
            printf("Hay un error de memoria");
            exit(1);
        }
        printf("\n[DECISION] Como piensas avanzar y superar la neblina que rodea tu camino?\n");


        return decisions;

    
    }*/
    
    Option *select_option(){
            Option *options = malloc(6* sizeof(Scenario)); // reservamos memoria para los 6 escenarios
        if (options == NULL){ // Aseguramos que no haya ningún error con la memória
            printf("Hay un error de memoria");
            exit(1);
        }
        Decision *op;
        op->numOptions = 2;
        printf("\nNumero de opciones disponibles -> %i",op->numOptions);
        
        return options;
    }


    Scenario *init_scenario(){ // definimos la función del escenario
        Scenario *scenarios = malloc(sizeof(Scenario)); // reservamos memoria para los  escenarios
        if (scenarios == NULL){
            printf("Hay un error de memoria");
            exit(1);
        }
    // char name_scenarios_1 [] = {"Beggining", "Mithra", "Ruinas de Vandal", "River lake", "Yggdrasil"," Niflheim" };
        Enemy *enemies = init_enemies();
        char *name_scenarios_1 = "Beggining";
        char *name_scenarios_2 = "Mithra";
        char *name_scenarios_3 = "Ruinas de Vandal";
        char *name_scenarios_4 = "River lake";
        char *name_scenarios_5 = "Yggdrasil";
        char *name_scenarios_6 = "Niflheim";
    /* char *descript_scenario[] = {
        "Te encuentras en el Beggining, el escenario principal donde la aventura apenas comienza. Es un lugar misterioso lleno de promesas y peligros, rodeado de una densa niebla que oculta sus secretos.",
        "Mithra es un valle sagrado, donde los antiguos dioses dejaron su huella en forma de templos y estatuas. Las leyendas cuentan que aquí es donde el mundo de los dioses se encuentra con el de los mortales.",
        "Las Ruinas de Vandal son un lugar olvidado por el tiempo, donde antaño se alzaba una gran ciudad. Ahora, solo quedan ruinas cubiertas por la maleza y el misterio de un pasado perdido.",
        "En River lake, el agua cristalina refleja el cielo eterno de Asgard. Este lugar tranquilo esconde secretos bajo su superficie serena, donde los ríos fluyen hacia los reinos de los dioses.",
        "Yggdrasil, el Árbol del Mundo, se alza imponente ante ti, sus ramas se extienden hacia los cielos y las raíces se hunden en las profundidades de los nueve mundos. Es el eje que sostiene la existencia misma.",
        "Niflheim, el reino de la niebla eterna y el frío implacable. Aquí, las almas de los malvados son castigadas en un eterno invierno, mientras las sombras acechan entre la niebla espesa."
    };*/

        char *descript_scenario_1 =  "Te encuentras en el Beggining, el escenario principal donde la aventura apenas comienza. Es un lugar misterioso lleno depromesas y peligros, rodeado de una densa niebla que oculta sus secretos";
        char *descript_scenario_2 = "Mithra es un valle sagrado, donde los antiguos dioses dejaron su huella en forma de templos y estatuas. Las leyendas cuentan que aquí es donde el mundo de los dioses se encuentra con el de los mortales.";
        char *descript_scenario_3 = "Las Ruinas de Vandal son un lugar olvidado por el tiempo, donde antaño se alzaba una gran ciudad. Ahora, solo quedan ruinas cubiertas por la maleza y el misterio de un pasado perdido.";
        char *descript_scenario_4 = "En River lake, el agua cristalina refleja el cielo eterno de Asgard. Este lugar tranquilo esconde secretos bajo su superficie serena, donde los ríos fluyen hacia los reinos de los dioses.";
        char *descript_scenario_5 = "Yggdrasil, el Árbol del Mundo, se alza imponente ante ti, sus ramas se extienden hacia los cielos y las raíces se hunden en las profundidades de los nueve mundos. Es el eje que sostiene la existencia misma.";
        char *descript_scenario_6 =  "Niflheim, el reino de la niebla eterna y el frío implacable. Aquí, las almas de los malvados son castigadas en un eterno invierno, mientras las sombras acechan entre la niebla espesa.";



            strcpy(scenarios->name, name_scenarios_1);
            strcpy(scenarios->description, descript_scenario_1);
            scenarios->decisions.numOptions=2;
            char q[] = "Como piensas avanzar y superar la neblina que rodea tu camino?\n";
            strcpy(scenarios->decisions.question, q);
            

            printf("\n\n[ESCENARIO] -> %s\n",scenarios->name);
            printf("\nDescripcion -> %s", scenarios->description);
            printf("\n");
            printf("\n[DECISION] -> %s",scenarios->decisions.question);
            printf("\nNumero de opciones disponibles -> %i",scenarios->decisions.numOptions);
            char *response_1 = "Decides avanzar con valentia hacia el frente y te puede encontrar algun enemigo";
            char *response_2 = "Decides tomar un camino alternativo y por azares del destino llegas al fin de la neblina sin nigun problema";
            strcpy(scenarios->decisions.options[0].response, response_1);
            strcpy(scenarios->decisions.options[1].response, response_2);

            // Generar un número aleatorio de enemigos para la opción 1
            srand(time(NULL)); // Inicializar el generador de números aleatorios
            scenarios->decisions.options[0].numEnemies = rand() % 4; // Número aleatorio de 0 a 3

            // Asignar enemigos aleatorios a la opción 1
             for (int i = 0; i < scenarios->decisions.options[0].numEnemies; i++) {
                scenarios->decisions.options[0].enemies[i] = enemies[i];
            }
            printf("\n-------------------------------------------------------------------------------------------");
            printf("\n[OPCION 1] -> %s",scenarios->decisions.options[0].response);
            printf("\nNumero de enemigos en opcion 1 -> %d", scenarios->decisions.options[0].numEnemies);
            for (int i = 0; i < scenarios->decisions.options[0].numEnemies; i++) {
            printf("\n[Enemigo %d] -> %s", i + 1, scenarios->decisions.options[0].enemies[i].name);
            printf("\nPuntos de ataque -> %d", scenarios->decisions.options[0].enemies[i].p_att);
            printf("\nPuntos de defensa -> %d", scenarios->decisions.options[0].enemies[i].p_def);
            printf("\nPuntos de vida -> %d", scenarios->decisions.options[0].enemies[i].p_hp);
            }

            printf("\n[OPCION 2] -> %s",scenarios->decisions.options[1].response);
            printf("\n-------------------------------------------------------------------------------------------");

        return scenarios;
    
    }

    
int combat(Player* player, Enemy* enemy){//to let the user fight an enemy, return 0 if the user lost
    int totalTurns = 10; // Numero de turnos (se puede cambiar)
    Queue* turnsQueue = randomTurns(totalTurns);
    
    while (player->p_hp> 0 && enemy->p_hp > 0) { // mientras los dos tengan vida que vayan atacando
        int turn = dequeue(turnsQueue);
        if(turn == 1){ // turno de ataque player (falta como ataca)






        }
        else{// turno enemigo (falta como ataca)





        }
    }
    free(turnsQueue);

    if (player->p_hp > 0 && enemy->p_hp <= 0) {
        printf("El jugador ha ganado!\n");
        return 1; // El jugador ganó
    } else {
        printf("El enemigo ha ganado!\n");
        return 0; // El jugador perdió
    }


} 