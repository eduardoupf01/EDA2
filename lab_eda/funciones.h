#include <stdio.h>
#include <stdbool.h>
#define MAX_CHAR 100
typedef char Name[MAX_CHAR];
Name New_Name;
typedef struct{

    char  hola; 
}hola;

typedef struct{
    char name[50];
    int attack;
    int health;
    int reinforcment;
}Character; // definimos la estructura de personajes




/*char Id(char *x){
    char afi,neg;
    printf("Introduzca su nombre de usuario porfavor");
    fgets(New_Name,100,stdin);
    printf("Hola %c preparado para tu aventura en este vertiginoso y trepidante mundo ?",New_Name);
    printf("Espero que si %c",New_Name);
}
*/

void Intro(){
    printf("Comencemos ahora si con el contexto de este nuevo mundo\n\n");
    printf("En un remoto e idílico lugar hace más de 600 años, donde la paz y la diversidad reinaba entre humanos y semihumanos, al que todos llamaban Serenis, la armonía entre seres vivos era ya considerada mundana, la simpatía se respiraba a raudales y la fuente motora era la magnanimidad y la vitalidad.\n\n");
    printf("Pero un día nació un niño noble en los estratos más altos de la nobleza, pero con una horripilante condición física que deformaba su rostro, sus ojos estaban siempre de un color rojo carmesí, en su mirada se veía reflejada el tormento y la perdición, además su piel escamosa como los secretos más oscuros sepultados. Pero a pesar de todo, el rey Vitaly conocido por su nobleza y su integridad, decidió seguir adelante con este infortunio, pero con la única condición que no viera la luz del día y lo encerró en una mazmorra. Hasta que un día el infante logró salir y cuando el rey se enteró de lo sucedido, la bautizó con el nombre de Hefest, conocido como el dios de la grotesca, poco después de desterrarlo.\n\n");
    printf("Lo que no sabía es que había creado un monstruo, que con el paso del tiempo se haría fuerte y uniría fuerzas con los demás monstruos exiliados, de lugares colindantes de los lugares más remotos e inhóspitos donde reina la maldad y el caos. No fue hasta años posteriores que sembraron la destrucción y devastaron Serenis y sus pueblos fronterizos.\n\n");
}

 void menu(){
    printf("1.Empezar aventura
            2. Elegir un personje ")
    
    if()
   
    
}

