#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"
const char *tipo_carta[]={"Trebol", "Corazon","Diamante","Pica"};
const char *num_carta[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
int generarCarta ();
int puntosCarta (const char* carta);
char* obtenerfecha();
void guardarpartidas (int njugadores);
void menusecundario ();
void mostrarganador ();


void menu (){
    printf ("BIENVENIDO AL JUEGO DE BLACKJACK\n");
    printf ("------------------\n");
    printf("[1]Juego nuevo\n");
    printf("[2]Cargar Partidas\n");
    printf("[0]Salir\n");
    printf("==============\n");
    printf("Ingresa la opcion (digitar numero correspondiente)\n");

}


void jugarPartida () {

    int njugadores;
    fflush (stdin);
    printf ("Cuantos jugadores entre 2-4 van a jugar:\n");
    scanf ("%d",&njugadores);

    while (njugadores<= 1 || njugadores > 4 ){
        fflush (stdin);
        printf ("Ingrese un numero de jugadores valido\n");
        scanf ("%d",&njugadores);

        for (int i=1; i<=60; i++){
                struct jugador j;
                fflush (stdin);
                printf ("Introduce el nombre del jugador %d\n", i);
                gets (j.nombre);
                jugadores [i-1]=j;


        }
    }
    for (int i=0; i<njugadores; i++){
        printf ("Turno de %s\n", jugadores[i].nombre);
        int puntuacion=0;
        puntuacion= puntuacion+generarCarta();
        puntuacion= puntuacion+generarCarta ();
        printf ("Puntuacion es: %d\n");
        int op;
        fflush (stdin);
        menusecundario ();
        scanf ("%d", op);
        while (op != 2 &&  puntuacion!=0){
            if (op==1){
                puntuacion=puntuacion+ generarCarta ();
                if (puntuacion>21){
                    puntuacion=0;
                    printf ("TE HAS PASADO\n");

                }
                printf ("Puntos totales %d\n", puntuacion);
            }
            if (puntuacion !=0)
            {
                fflush (stdin);
                menusecundario();
                scanf ("%d",op);
            }
            
        }
        jugadores[i].puntos = puntuacion;
        mostrarganador (njugadores);
        guardarpartidas (njugadores);


    }




}
int generarCarta (){
    int n_tipo_carta = rand ()%4;
    int n_num_carta = rand ()%13;
    printf ("-------------------------\n");
    printf ("%s\n\n", num_carta[n_num_carta]);
    printf ("\t%s\n\n", tipo_carta[n_tipo_carta]);
    printf ("\t\t\t%s\n\n", num_carta[n_num_carta]);
    printf ("-------------------------\n");

    const char *carta=num_carta[n_num_carta];
    int valor = puntosCarta(carta);
    return valor;
}
int puntosCarta (const char* carta){

    int valor=0;
    if (strcmp (carta,"2")==0){
        valor=2;
    } else if(strcmp(carta, "3")==0)
    {
        valor=3;
    }else if(strcmp(carta, "4")==0)
    {
        valor=4;
    }else if(strcmp(carta, "5")==0)
    {
        valor=5;
    }else if(strcmp(carta, "6")==0)
    {
        valor=6;
    }else if(strcmp(carta, "7")==0)
    {
        valor=7;
    }else if(strcmp(carta, "8")==0)
    {
        valor=8;
    }else if(strcmp(carta, "9")==0)
    {
        valor=9;
    }else if(strcmp(carta, "10")==0)
    {
        valor=10;
    }else if(strcmp(carta, "Q")==0)
    {
        valor=10;
    }else if(strcmp(carta, "J")==0)
    {
        valor=10;
    }else if(strcmp(carta, "A")==0)
    {
        valor=11;
    }else if(strcmp(carta, "K")==0)
    {
        valor=10;
    }
    return valor;

}
void menusecundario (){
    printf ("Seleccione una opcion: DIGITE EL NUMERO\n");
    printf ("[1]Dame una carta\n");
    printf ("[2]Salir\n");

}
void mostrarganador (int njugadores){
    int punt_max=0;
    int index_max;
    for (int i=0; i<njugadores; i++){
        punt_max=jugadores[i].puntos;
        index_max=i;
    }
    printf ("El ganador es: %s con una puntuacion de %d\n", jugadores[index_max].nombre,jugadores[index_max].puntos);
    printf ("=================================\n\n");

}
void guardarpartidas (int njugadores){
    FILE *f;
    f = fopen ("partidas.txt", "a");
    char *fecha = obtenerfecha ();

    fprintf (f,"\nFecha:%s--",fecha);
    for (int i=0; i<njugadores; i++){
        fprintf (f, "Nombre: %s-Puntos: %d;", jugadores[i].nombre, jugadores[i].puntos);
    }
    fprintf (f,"Nombre: %s -Puntos: %d", jugadores[njugadores-1],jugadores[njugadores-1].puntos);
    fclose (f);


}
char* obtenerfecha (){
    time_t t;
    struct tm *tm;
    char formateada [100];
    t=time (NULL);
    tm = localtime (&t);
    strftime (formateada,100, "%d/%m/%Y %H:%M:%S",tm);
    char *fecha = malloc (sizeof (char)*100);
    strcpy (fecha, formateada);
    return fecha;

}
void cargarPartidas (){
    FILE *f;
    f=fopen("partidas.txt","r");
    char cadena [225];
    while (feof(f)==0){
        fgets (cadena,225,f);
        printf ("%s",cadena);

    }
    printf ("\n\n");
    fclose (f);
}