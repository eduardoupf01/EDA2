// Definimos un tipo de tipo Ability con sus características
typedef struct {
    char name[30]; // nombre de la habilidad
    char description[40]; // descripción de la habilidad
    char type[15]; // el tipo de la habilidad (temporal o directo)
    int duration; // la duración por turnos de la habilidad temporal
    int mod_att; // aumenta o disminuye su capacidad de ataque en combate
    int mod_def; // aumenta o disminuye su capacidad de defensa en combate
    int mod_hp; // aumenta o disminuye su capacidad de vida en combate
}Ability;

// Definimos lo que el usuario podrá implementar en el jugador 
typedef struct{
    char name[20]; // nombre del jugador
    int p_att; // puntos de ataque
    int p_def; // puntos de defensa 
    int p_hp; // puntos de vida
    Ability *abilities[4]; // array de 5 habilidades del personaje
}Player;


// Definimos las características de los enemigos 
typedef struct{
    char name[20]; // Nombre del enemigo
    int p_att; // puntos de ataque
    int p_def; // puntos de defensa
    int p_hp; // puntos de vida
}Enemy;


typedef struct {
    char response[100];     // Texto de respuesta
    char preBattleNarrative[200];  // Texto de narración antes de enfrentarse a los enemigos
    Enemy *enemies[3];       // Array de hasta 3 enemigos
    int numEnemies;         // Número de enemigos
    char postBattleNarrative[200]; // Texto de narración después de enfrentarse a los enemigos
} Option;

// Definimos la opcion de decisión
typedef struct{
    char question[200];     // Texto de la pregunta que presenta la decisión
    Option *options[3];      // Array para almacenar hasta 3 opciones posibles
    int numOptions;         // número de opciones disponibles
}Decision;

// Definimos las características que debe de tener un escenario en el juego
typedef struct{
    char name[20]; // Nombre del lugar
    char description[200]; // Descripción del lugar
    Decision *decisions; // Decisiones presentadas
}Scenario;

Enemy *init_enemies(); // Creción de los enemigos
Ability *init_abilities(); // Escoger las habilidades   
Option *select_option(); // Crear las opciones
Decision *select_decision(); // Crear decisiones en base a la opción
Scenario *init_scenario(); // creación del escenario 
Player *init_character(); // Creación del personaje
char welcome();