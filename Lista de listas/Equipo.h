#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED

#include "Listas.h"

ListaPrincipal *menuEquipo(ListaPrincipal *lista){

    int op;

    do{

        system("cls");
        printf("\n\t**** E Q U I P O S ****\n");
        printf("\n 1.- Agregar equipo.\n");
        printf("\n 2.- Eliminar equipo.\n");
        printf("\n 3.- Buscar equipo.\n");
        printf("\n 0.- REGRESAR\n");
        op = comp_op(3);

        switch(op){

        case 0:
            return lista;
            break;

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;
        }

    }while(op != 0);

}



#endif // EQUIPO_H_INCLUDED
