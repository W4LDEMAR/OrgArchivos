#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"
#include "Equipo.h"

int main(){

    int op;
    ListaPrincipal *lista;
    lista = n_listaE();

    do{

        system("cls");
        printf("\n\t**** T O R N E O   P O R   E Q U I P O S ****\n");
        printf("\n 1.- Opciones con equipos.\n");
        printf("\n 2.- Opciones con jugadores.\n");
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
            break;

    }

    }while(op != 0);

    return 0;

}
