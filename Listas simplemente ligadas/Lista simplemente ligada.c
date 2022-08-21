/*
    Listas simplemente ligadas
Estructura de datos y organizacion de archivos
Sosa Hernandez Saul Waldemar
Compilador: GNU GCC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ //Estructura para datos de una persona

    int id;
    char nombre[30];
    int edad;

} Info;

typedef struct{ // Nodo simple

    struct Info datos;
    struct Nodo *sig;

} Nodo;

void imp_lista(Nodo *);
Info n_persona();
short int push_prim(Nodo *, Nodo *, int *);

int main(){

    Nodo *start, *end; // Inicializando
    int tam;
    start = end = NULL;

    return 0;
}

Info n_persona(){ //Llenar los datos de la persona

    /*
    Pregunta al usuario por los datos de la persona que quiere ingresar al sistema
    Regresa un estructura de tipo Info
    */

    Info nuevo;

    system("cls");
    printf("\t\t**** L L E N A D O   D E   D A T O S ****\n");
    printf("Ingresa el id de la persona:\n");
    fflush(stdin);
    scanf("%d", &nuevo.id);
    printf("Ingresa el nombre de la persona:\n");
    fflush(stdin);
    gets(nuevo.nombre);
    printf("Ingresa la edad de la persona:\n");
    fflush(stdin);
    gets(nuevo.edad);

    return nuevo;

}

short int push_prim(Nodo *start, Nodo *end, int *tam){ //Push cuando la lista esta vacia

    /*
    Recibe los apuntadores del nodo inicio, fin y el tamano de la lista
    Regresa 1 si no se pudieron llenar
    Regresa 0 si se hizo el push con exito
    */

    Nodo *nuevo;

    nuevo->datos = n_persona();
    nuevo->sig = NULL;
    start = end = nuevo;

    if(!start || !end){
        return 1;
    }else{
        printf("\n\tPersona agregada con exito!!");
        *tam++;
        system("pause");
        return 0;
    }
}

short int push_ini(Nodo *start){

    Nodo *nuevo, *aux;

    if(!start){
        nuevo->datos =
    }
    alaverga

}

void imp_lista(Nodo *start){

    /*
    Recorre la lista con un auxiliar hasta llegar al ultimo (el que es nulo)
    imprimiendo todos sus datos.
    Recibe el apuntador al inicio de la lista.
    */

    Nodo *aux;
    aux = start;

    system("cls");
    printf("\n\t\t**** D A T O S ****\n\n");
    while(aux){

        printf("%d.- %s -> %d anos\n", aux->datos->id, aux->datos->nombre, aux->datos->edad);
        aux = aux->sig;

    }

}
