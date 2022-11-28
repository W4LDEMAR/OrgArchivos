/*
    Proyecto final
"Sistema bancario"
Estructura de datos y organizacion de archivos

Sosa Hernandez Saul Waldemar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"
#include "Clientes.h"

int main()
{
    int op, num_clientes = 0, n, x;
    short int v;
    char nombre[20];
    Cliente *TablaClientes[TamHashing];

    for ( x = 0; x < TamHashing; x++ ){
        TablaClientes[x] = (Cliente*)malloc(sizeof (Cliente));
    }

    int i;

    for(i = 0; i < TamHashing; i++){
        TablaClientes[i] = NULL;
    }

    FILE *ptf;
    ptf = fopen("datos.bin", "ab+");
    fclose(ptf);
    ptf = fopen("datos.bin", "rb+");
    if(!ptf){
        printf("No existe el archivo.");
        system("pause");
        return 0;
    }else{
        for ( x = 0; x < TamHashing; x++ ){
            fread(TablaClientes[x], sizeof(Cliente), 1, ptf);
        }
        fclose(ptf);
    }


    do{
        system("cls");
        printf("\n\t*** S I S T E M A   B A N C A R I O ***\n\n");
        printf("1.- Dar un cliente de alta.\n");
        printf("2.- Buscar a un cliente.\n");  // Adentro de esta funcion podras elegir si imprimir las cuentas tambien o no
        printf("3.- Modificar informacion de un cliente.\n");
        printf("4.- Borrar a un cliente.\n");
        printf("5.- Reporte de clientes completo.\n");
        printf("\n Movimientos con cuentas -->\n");
        printf("6.- Deposito a una cuenta.\n");
        printf("7.- Retiro a una cuenta.\n");
        printf("8.- Mostrar hashing");
        printf("\n 0.- SALIR.\n");

        op = comp_op(8);

        switch(op){

            case 1:
                altaCliente(TablaClientes);
                num_clientes += 1;
                printf("Se agrego persona con exito!!\n");
                system("pause");
                break;
            case 2:
                system("cls");
                printf("\t*** B U S Q U E D A ***\n");
                printf("Ingresa el nombre de la persona que deseas buscar:\n");
                gets(nombre);

                v = buscar(TablaClientes, nombre);
                if(v == 1){
                    printf("ERROR: No se encontro ninguna cuenta con ese nombre.");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                printf("\t*** E D I T A R ***\n");
                printf("Ingresa el nombre de la persona que deseas modificar:\n");
                gets(nombre);
                v = modCliente(TablaClientes, nombre);
                if(v == 1){
                    printf("ERROR: No se encontro ninguna cuenta con ese nombre.");
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                printf("\t*** B O R R A D O ***\n");
                printf("Ingresa el nombre de la persona que deseas borrar:\n");
                gets(nombre);
                v = borrCliente(TablaClientes, nombre);
                if(v == 1){
                    printf("ERROR: No se encontro ninguna cuenta con ese nombre.");
                    system("pause");
                }else{
                    num_clientes--;
                }
                break;
            case 5:
                imprimir(TablaClientes);
                break;
            case 6:
                system("cls");
                printf("\t*** D E P O S I T O ***\n");
                printf("Ingresa el nombre de la persona que deseas depositar:\n");
                gets(nombre);
                v = depositar(TablaClientes, nombre);
                if(v == 1){
                    printf("ERROR: No se ha podido completar la accion");
                    system("pause");
                }
                break;
            case 7:
                system("cls");
                printf("\t*** R E T I R O ***\n");
                printf("Ingresa el nombre de la persona que deseas depositar:\n");
                gets(nombre);
                v = retirar(TablaClientes, nombre);
                if(v == 1){
                    printf("ERROR: No hay fondos suficientes.");
                    system("pause");
                }
                break;
            case 8:
                system("cls");
                printf("\t*** H A S H I N G ***\n");
                for(i = 0; i < TamHashing; i++){
                    if(TablaClientes[i] == NULL){
                        printf("%d\t------------\n", i);
                    }else{
                        Cliente *tmp = TablaClientes[i];
                        printf("%d\t", i);
                        while (tmp != NULL){
                            printf("%s --->", TablaClientes[i]->datos.nombre);
                            tmp = tmp->sig;
                        }
                        printf("\n");
                    }
                }
                system("pause");
                break;
        }


    }while(op != 0);

    ptf = fopen("datos.bin", "wb");
    if(!ptf){
        printf("Error en crear el archivo.");
        system("pause");
        return 0;
    }else{
        fclose(ptf);
        ptf = fopen("datos.bin", "rb+");
        for ( x = 0; x < TamHashing; x++ ){
            fwrite(TablaClientes[x], sizeof(Cliente), 1, ptf);
        }
        fclose(ptf);


    }

    return 0;
}
