#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Estructuras.h"

void menuPrincipal{

    int op;

    do{

        system("cls");
        printf("\n\t*** S I S T E M A   B A N C A R I O ***\n\n");
        printf("1.- Dar un cliente de alta.\n");
        printf("2.- Buscar a un cliente.\n");
        printf("3.- Modificar informacion de un cliente.\n");
        printf("4.- Borrar a un cliente.\n");
        printf("5.- Reporte de clientes completo.\n");
        printf("\n Movimientos con cuentas -->\n");
        printf("6.- Buscar una cuenta de cliente.\n");
        printf("7.- Deposito a una cuenta.\n");
        printf("8.- Retiro a una cuenta.\n");
        printf("\n 0.- SALIR.\n");

        op = comp_op(8);
        switch(op){

            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                return;

        }

    }while(op != 0);

}

#endif // MENU_H_INCLUDED
