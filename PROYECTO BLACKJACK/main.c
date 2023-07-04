#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    menu ();
    scanf ("%d",&opcion);

    while (opcion !=0){
        if (opcion==1){
            printf ("Jugar nueva partida\n");
            jugarPartida ();
        } else if (opcion==2){
            cargarPartidas ();

        }
        fflush (stdin);
        menu ();
        scanf ("%d",&opcion);
    }
    printf ("GRACIAS POR JUGAR\n");

}