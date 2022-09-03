/*
    Estructura de datos y organizacion de archivos

PRIMER EXAMEN PARCIAL
Sosa Hernandez Saul Waldemar
"Listas Simples y Dobles"

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSL.h"
#include "LDL.h"

int main(){

    int op = 3;

    do{

        system("cls");
        printf("\n\t **** L I S T A S ****\n\n");
        printf("1.- Lista Simplemente Ligada\n");
        printf("2.- Lista Doblemente Ligada\n");
        printf("0.- SALIR\n");
        fflush(stdin);
        scanf("%d", &op);

        while(op > 2 || op < 0){
            printf("ERROR: Elige una opcion valida:\n");
            fflush(stdin);
            scanf("%d", &op);
        }

        switch(op){

            case 1:

                menuLSL();
                break;

            case 2:

                menuLDL();
                break;

        }

    }while(op != 0);

    return 0;
}
