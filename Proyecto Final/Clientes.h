#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"

void altaCliente(Cliente*[]);
int compBusqueda(int, int);
short int buscar(Cliente *[], char *);
short int modCliente(Cliente *[], char *);
void imprimir(Cliente *[]);

void altaCliente(Cliente *tabla[]){ // Se agregara un cliente al archivo

    system("cls");
    printf("\t*** A L T A   C L I E N T E ***\n");

    Cliente *nuevo;
    nuevo = nuevoCliente();
    int lugar = hash(nuevo->datos.nombre);

    nuevo->sig = tabla[lugar];
    tabla[lugar] = nuevo;


}

int compBusqueda(int num_clientes, int clave){ // Verifica si una clave ya esta en uso. 0 no y 1 si

    Cliente clientes[num_clientes]; // Hace un arreglo del total de clientes
    int i;
    FILE *ptf;
    ptf = fopen("Datos.bin", "rb");

    if(ptf == NULL){
        printf("ERROR: No se pudo abrir correctamente el archivo"); // Hubo error en la apertura del archivo
    }else{
        fread(clientes, sizeof(Cliente), num_clientes, ptf);
        for(i = 0; i < num_clientes; i++){
            if(clave == clientes[i].n_cliente){
                fclose(ptf);
                return i;
            }
        }
    }

    fclose(ptf);

    return -1;

}

short int buscar(Cliente *tabla[], char *nombre){ // Busca al cliente dentro el archivo

    int lugar = hash(nombre);
    int opc;
    Cliente *tmp = tabla[lugar];
    while(tmp != NULL && strcmp(tmp->datos.nombre, nombre) != 0){
        tmp = tmp->sig;
    }
    if (tmp != NULL){
        printf("    Cliente --> %d\n", tmp->n_cliente);
        printf("Nombre: %s\n", tmp->datos.nombre);
        printf("Numero de cuentas: %d\n", tmp->cant_cuentas);
        printf("Saldo a favor: %f\n", tmp->saldo_p);
        printf("Saldo deudor: %f\n\n", tmp->saldo_n);
        printf("\n    Contacto -->\n");
        printf("Telefono: %d\n", tmp->datos.telefono);
        printf("E-mail: %s\n", tmp->datos.correo);
        printf("Domicilio: %s\n", tmp->datos.direccion);
        printf("\n ** Deseas desplegar la informacion de las cuentas del cliente?\n");
        printf("0.- No\n1.- Si, desplegar informacion.\n");
        opc = comp_op(1);
        if(opc == 1){
            int x;
            system("cls");
            printf("    Cuentas -->\n");
            for(x = 0; x < tmp->cant_cuentas; x++){
                printf("%d.- Tipo de cuenta: %s\n",tmp->C[x].n_cuenta, tmp->C[x].t_cuenta);
                printf("Saldo: %f\n", tmp->C[x].saldo);
            }
        }
        return 0;
    }else{
        return 1;
    }
}

short int modCliente(Cliente *tabla[], char *nombre){

    int lugar = hash(nombre);
    int opc;
    Cliente *tmp = tabla[lugar];
    while(tmp != NULL && strcmp(tmp->datos.nombre, nombre) != 0){
        tmp = tmp->sig;
    }
    if (tmp != NULL){
        printf("    Cliente --> %d\n", tmp->n_cliente);
        printf("Nombre: %s\n", tmp->datos.nombre);
        printf("Numero de cuentas: %d\n", tmp->cant_cuentas);
        printf("Saldo a favor: %f\n", tmp->saldo_p);
        printf("Saldo deudor: %f\n\n", tmp->saldo_n);
        printf("\n    Contacto -->\n");
        printf("Telefono: %d\n", tmp->datos.telefono);
        printf("E-mail: %s\n", tmp->datos.correo);
        printf("Domicilio: %s\n", tmp->datos.direccion);
        printf("\n\n Que dato deseas modificar?\n");
        printf("1.- Telefono\n");
        printf("2.- E-mail\n");
        printf("3.- Domicilio\n");
        printf("0.- REGRESAR");
        opc = comp_op(3);
        if(opc == 1){
            printf("Ingresa el nuevo telefono:\n");
            scanf("%d", &tmp->datos.telefono);
        }else if(opc == 2){
            printf("Ingresa el nuevo E-mail:\n");
            gets(tmp->datos.correo);
        }else if(opc == 3){
            printf("Ingresa la nueva direccion:\n");
            gets(tmp->datos.direccion);
        }else{
            return 0;
        }
        return 0;

    }else{
        return 1;
    }

}

short int borrCliente(Cliente *tabla[], char *nombre){

    int lugar = hash(nombre);
    int opc;
    Cliente *tmp = tabla[lugar];
    Cliente *pre = NULL;
    while(tmp != NULL && strcmp(tmp->datos.nombre, nombre) != 0){
        pre = tmp;
        tmp = tmp->sig;
    }
    if (tmp == NULL){
        return 1;
    }else if(pre == NULL){
        tabla[lugar] = tmp->sig;
    }else{
        pre->sig = tmp->sig;
    }
    return 0;

}

void imprimir(Cliente *TablaClientes[]){

    int i;

    system("cls");
    printf("\t*** B A S E   D E   D A T O S ***\n");
    for(i = 0; i < TamHashing; i++){
        if(TablaClientes[i] != NULL){
            Cliente *tmp = TablaClientes[i];
            printf("\n");
            while (tmp != NULL){
                printf("    Cliente --> %d\n", TablaClientes[i]->n_cliente);
                printf("Nombre: %s\n", TablaClientes[i]->datos.nombre);
                printf("Numero de cuentas: %d\n", TablaClientes[i]->cant_cuentas);
                printf("Saldo a favor: %f\n", TablaClientes[i]->saldo_p);
                printf("Saldo deudor: %f\n\n", TablaClientes[i]->saldo_n);
                printf("\n    Contacto -->\n");
                printf("Telefono: %d\n", TablaClientes[i]->datos.telefono);
                printf("E-mail: %s\n", TablaClientes[i]->datos.correo);
                printf("Domicilio: %s\n", TablaClientes[i]->datos.direccion);
                printf("\n-------------------------------------------------------------------\n");
                tmp = tmp->sig;
            }
            printf("\n");
        }
    }
}

short int depositar(Cliente *tabla[], char *nombre){

    int lugar = hash(nombre);
    int opc;
    float dinero;
    Cliente *tmp = tabla[lugar];
    Cliente *pre = NULL;
    while(tmp != NULL && strcmp(tmp->datos.nombre, nombre) != 0){
        pre = tmp;
        tmp = tmp->sig;
    }
    if(tmp == NULL){
        return 1;
    }else{
        printf("Ingresa el monto de lo que deseas depositar:");
        scanf("%f", &dinero);
        tmp->saldo_p = tmp->saldo_p + dinero;
        return 0;
    }

}

short int retirar(Cliente *tabla[], char*nombre){

    int lugar = hash(nombre);
    int opc;
    float dinero;
    Cliente *tmp = tabla[lugar];
    Cliente *pre = NULL;
    while(tmp != NULL && strcmp(tmp->datos.nombre, nombre) != 0){
        pre = tmp;
        tmp = tmp->sig;
    }
    if(tmp == NULL){
        return 1;
    }else{
        printf("Quieres usar tu credito?");
        printf("1. SI\n2,- NO");
        opc = comp_op(1);
        printf("Ingresa el monto que deseas retirar:");
        scanf("f", &dinero);
        if(dinero > tmp->saldo_p){
            if(opc == 1){
                tmp->saldo_n = tmp->saldo_n - dinero;
                return 0;
            }else{
                return 1;
            }
        }else{
            tmp->saldo_p = tmp->saldo_p-dinero;
        }
        return 0;
    }

}

#endif // MENU_H_INCLUDED
