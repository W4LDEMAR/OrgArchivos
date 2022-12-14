#ifndef LISTAPRINCIPAL_H_INCLUDED
#define LISTAPRINCIPAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Verifica si hay espacio disponible para los nodos y listas que desea agregar el usuario
Funciones para llenar los datos necesarios
*/

typedef struct{

    int n_jug;
    char nombre[20];
    int edad;

}Jugador;

typedef struct NodoS{

    Jugador jugador;
    struct NodoS *pre;
    struct NodoS *sig;

}NodoS;

typedef struct{

    NodoS *start;
    NodoS *end;
    char nombre_team[20];
    char ciudad[20];
    int total_j;

}Equipo;

typedef struct Nodo{

    struct Nodo *arriba;
    Equipo *team;
    struct Nodo *abajo;

}Nodo;

typedef struct{

    Nodo *start;
    Nodo *end;
    int total;

}ListaPrincipal;

Jugador nuevoJugador();
NodoS *nuevoNodoS();
Equipo *nEquipo();
Nodo *nuevoNodo();
ListaPrincipal *n_listaE();
int comp_op(int n);
int comp_num();

Jugador nuevoJugador(){

    Jugador nuevo;

    char nombre[20];
    int i;

    system("cls");
    printf("\t**** N U E V O   J U G A D O R ****\n");
    printf("Ingresa el numero del jugador:\n");
    fflush(stdin);
    nuevo.n_jug = comp_num();
    printf("ingresa el nombre del jugador:\n");
    fflush(stdin);
    gets(nombre);
    for(i = 0; nombre[i] != NULL; ++i){
        nombre[i] = toupper(nombre[i]);
    }
    strcpy(nuevo.nombre, nombre);
    printf("ingresa la edad del jugador:\n");
    fflush(stdin);
    nuevo.edad = comp_num();

    return nuevo;

}

NodoS *nuevoNodoS(){

    NodoS *nuevo;

    nuevo = (NodoS*)malloc(sizeof(NodoS));

    if(nuevo!= NULL){
        nuevo->jugador = nuevoJugador();
        nuevo->sig = NULL;
        nuevo->pre = NULL;
    }

    return nuevo;

}

Equipo *nEquipo(){

    Equipo *nuevo;
    char nombre[20], ciudad [20];
    int i;

    nuevo = (Equipo*)malloc(sizeof(Equipo));

    nuevo->start = NULL;
    nuevo->end = NULL;
    nuevo->total_j = 0;
    system("cls");
    printf("\t*** N U E V O   E Q U I P O ***\n");
    printf("Ingresa el nommbre del nuevo equipo:\n");
    fflush(stdin);
    gets(nombre);
    for(i = 0; nombre[i] != NULL; ++i){
        nombre[i] = toupper(nombre[i]);
    }
    strcpy(nuevo->nombre_team, nombre);
    printf("Ingresa la ciudad del nuevo equipo:\n");
    fflush(stdin);
    gets(ciudad);
    for(i = 0; ciudad[i] != NULL; ++i){
        ciudad[i] = toupper(ciudad[i]);
    }
    strcpy(nuevo->ciudad, ciudad);

    return nuevo;
}

Nodo *nuevoNodo(){

    Nodo *nuevo;

    nuevo= (Nodo*)malloc(sizeof(Nodo));

    if(nuevo != NULL){
        nuevo->arriba = NULL;
        nuevo->abajo = NULL;
        nuevo->team = nEquipo();
    }
}

ListaPrincipal *n_listaE(){

    ListaPrincipal *nueva;

    nueva = (ListaPrincipal*)malloc(sizeof(ListaPrincipal));
    nueva->start = NULL;
    nueva->end;
    nueva->total = 0;

    return nueva;
}

int comp_op(int n){

    int op;

    printf("\n Ingrese la opcion deseada:\n");
    scanf("%d", &op);

    if(op < 0 || op > n){
        printf("ERROR: Elige una opcion dentro del menu.\n");
        system("pause");
        scanf("%*[^\n]%*c");
        op = comp_op(n);
    }

    return op;
}

int comp_num(){ //Comprueba si el usuario introdujo un numero

    int n, comp;

    if(scanf("%d", &n)){
        return n;
    }else{
        do{
            printf("ERROR: Introduce un numero.\n");
            scanf("%*[^\n]%*c"); //Sacar el flujo para no caer en un bucle
            comp = scanf("%d", &n);
        }while(comp != 1);
    }

    return n;

}

#endif // LISTAPRINCIPAL_H_INCLUDED
