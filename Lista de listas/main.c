#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"
#include "Equipo.h"
#include "Jugador.h"

int main(){

    int op;
    ListaPrincipal *lista;
    lista = n_listaE();

    do{

        system("cls");
        printf("\n\t**** T O R N E O   P O R   E Q U I P O S ****\n");
        printf("\n 1.- Opciones con equipos.\n");
        printf("\n 2.- Opciones con jugadores.\n");
        printf("\n 3.- Imprimir toda la lista.\n");
        printf("\n 0.- SALIR.\n");
        op = comp_op(2);

        switch(op){

        case 0:
            return 0;
            break;

        case 1:
        //Entra al menu para los movimientos con equipos
            lista = menuEquipo(lista);
            break;

        case 2:
        //Entra al menu para los movimientos con jugadores
            lista = menuJugador(lista);
            break;

        case 3:
            imp_lista(lista);
            break;

    }

    }while(op != 0);

    return 0;

}

void imp_lista(ListaPrincipal *lista){
    /*
    Recorre la lista con un auxiliar hasta llegar al ultimo (el que es nulo)
    imprimiendo todos sus datos.
    */

    Nodo *aux;
    NodoS *aux2;
    int x;

    system("cls");

    if(lista->total == 0){//Si la lista esta vacia no entra a la seleccion de orden de impresion
        printf("\n\n\tERROR: La lista se encuentra vacia ingresa primero algunos datos\n");
        system("pause");
        return;
    }

    printf("1.- Mostrar en orden ascendente\n");
    printf("2.- Mostrar en orden descendente\n");
    printf("0.- REGRESAR\n");

    x = comp_op(2);

    switch(x){
        case 1://Imprimira del inicio de la lista hasta el final

            aux = lista->start;
            aux2 = aux->team->start;

            printf("\n\t\t**** D A T O S ****\n");
            while(aux != NULL){

                printf("%s ---- [%s] con %d jugadores.\n", aux->team->nombre_team, aux->team->ciudad, aux->team->total_j);
                imp_jugadores(aux2);
                aux = aux->abajo;
                aux2 = aux->team->start;

            }
            break;

        case 2://Imprimira del final de la lista hasta el inicio

            aux = lista->end;
            aux2 = aux->team->end;

            printf("\n\t\t**** D A T O S ****\n");
            while(aux != NULL){

                printf("%s ---- [%s] con %d jugadores.\n", aux->team->nombre_team, aux->team->ciudad, aux->team->total_j);
                imp_jugadores(aux2);
                aux = aux->arriba;
                aux2 = aux->team->end;

            }
            break;

    }

    system("pause");
}
