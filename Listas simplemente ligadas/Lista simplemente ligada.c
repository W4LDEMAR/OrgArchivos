/*
    Listas simplemente ligadas
Estructura de datos y organizacion de archivos
Sosa Hernandez Saul Waldemar
Compilador: GNU GCC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct{ //Estructura para datos de una persona

    int id;
    char nombre[50];
    int edad;

} Info;

typedef struct Nodo{ // Nodo simple

    Info datos;
    struct Nodo *sig;

} Nodo;

typedef struct{ //Control de Lista Simplemente Ligada

    int total;
    Nodo *start;
    Nodo *end;

} ListaSimple;

void imp_lista(ListaSimple *);
int ver_op();
ListaSimple *nuevaLista();
short int is_empty(ListaSimple *);
Info nuevaPersona();
Nodo *nuevoNodo();
int orden(ListaSimple *, char []);
int search(ListaSimple *, char []);
short int push(ListaSimple *);
void push_mid(ListaSimple *, Nodo *, int);
void push_start(ListaSimple *, Nodo *);
void push_end(ListaSimple *, Nodo *);
short int borrar(ListaSimple *);

int main(){

    ListaSimple *lista;
    lista = nuevaLista(); // Inicializando la lista
    int op;
    short int v;

    do{

        system("cls");
        printf("\t*** Lista simplemente ligada ***\n");
        printf("1.- Agregar una persona.\n");
        printf("2.- Borrar una persona.\n");
        printf("3.- Buscar una persona.\n");
        printf("4.- Desplegar la lista.\n");
        printf("0.-  SALIR \n");
        op = ver_op();

        switch(op){
            case 1:
                v = push(lista);
                if(v != 0){
                    printf("Error: No se pudo completar la accion.\n");
                    system("pause");
                }else{
                    printf("Persona agregada con exito!!");
                }
                break;
            case 2:
                v = borrar(lista);
                if(v != 0){
                    system("pause");
                }else{
                    printf("Persona eliminada con exito!!");
                    system("pause");
                }
                break;
            case 3:
                imp_search(lista);
                break;
            case 4:
                imp_lista(lista);
                break;
        }

    }while(op != 0);

    return 0;
}

int ver_op(){//Verifica si la opcion del menu es correcta

    int op;

    printf("\nIngrese la opcion deseada:\n");
    scanf("%d", &op);

    if(op < 0 || op > 4){
        printf("ERROR: Elige una opcion dentro del menu.");
        op = ver_op();
    }

    return op;
}

ListaSimple *nuevaLista(){

    ListaSimple *nueva;
    nueva = (ListaSimple*)malloc(sizeof(ListaSimple));
    nueva->start = NULL;
    nueva->end = NULL;
    nueva->total = 0;

    return nueva;
}

short int is_empty(ListaSimple *lista){// Verifica si la lista esta vacia

    //0 si esta vacia y 1 si tiene datos

    if(lista->total == 0){
        return 0;
    }else{
        return 1;
    }
}

Info nuevaPersona(){ //Llenar los datos de la persona

    /*
    Pregunta al usuario por los datos de la persona que quiere ingresar al sistema
    Regresa un estructura de tipo Info
    */

    Info nuevo;
    char nombre[50];
    int i;

    system("cls");
    printf("\t\t**** L L E N A D O   D E   D A T O S ****\n\n");
    printf("Ingresa el id de la persona:\n");
    fflush(stdin);
    scanf("%d", &nuevo.id);
    printf("Ingresa el nombre de la persona:\n");
    fflush(stdin);
    gets(nombre);
    for(i = 0; nombre[i] != NULL; ++i){
        nombre[i] = toupper(nombre[i]);
    }
    strcpy(nuevo.nombre, nombre);
    printf("Ingresa la edad de la persona:\n");
    fflush(stdin);
    scanf("%d", &nuevo.edad);

    return nuevo;

}

Nodo *nuevoNodo(){ //Crea un nodo para llenarlo con los datos solicitados

    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));

    if(nuevo != NULL){
        nuevo->datos = nuevaPersona();
        nuevo->sig = NULL;
    }

    return nuevo;
}

short int push(ListaSimple *lista){
    //Se decidira si se insertara al inicio, en medio o al final.

    Nodo *nuevo;
    char nombre[50];
    int lugar;

    nuevo = nuevoNodo();
    strcpy(nombre, nuevo->datos.nombre);

    if(is_empty(lista) == 0){ //verifica si esta vacia
        //Si la lista esta vacia entonces hara un push inicial

        lista->start = nuevo;
        lista->end = nuevo;
        lista->total++;

        return 0;
    }else{
        lugar = orden(lista, nuevo->datos.nombre);
        if(lugar < 0){
            //Se insertara al final
            push_end(lista, nuevo);
            return 0;
        }else if(lugar == 0){
            //Se insertara al incio
            push_start(lista, nuevo);
            return 0;
        }else{
            //Se insertara al en la posicion de "lugar"
            push_mid(lista, nuevo, lugar);
            return 0;
        }
    }
    return 1;
}

void push_end(ListaSimple *lista, Nodo *n){//Inserta al final de la lista

    lista->end->sig = n;
    lista->end=n;
    lista->total++;

}

void push_start(ListaSimple *lista, Nodo *n){

    n->sig = lista->start;
    lista->start = n;
    lista->total++;

}

void push_mid(ListaSimple *lista, Nodo *n, int lugar){

    Nodo *aux, *pre;
    int i;
    aux = lista->start;

    for(i = 0; i < lugar; i++){
        /*
        Recorrera la lista hasta el lugar deseado
        Pre sera un lugar antes del deseado y aux sera el deseado
        De esa forma se insertara entre estos dos
        */
        pre = aux;
        aux = aux->sig;
    }

    pre->sig = n;
    n->sig = aux;
    lista->total++;

}

void imp_search(ListaSimple *lista){

    char nombre[50];
    int lugar, i, x;
    Nodo *aux;
    aux = lista->start;

    printf("Ingresa el nombre la persona que deseas buscar:\n");
    fflush(stdin);
    gets(nombre);
    for(x = 0; nombre[x] != NULL; ++x){
        nombre[x] = toupper(nombre[x]);
    }

    lugar = search(lista, nombre);

    if(lugar < 0){
        printf("ERROR: No se encontro ninguna persona con ese nombre\n");
        printf("Veriica el ingreso de datos\n");
        system("pause");
        return;
    }

    for(i = 0; i < lugar; i++){
        aux = aux->sig;
    }

    printf("%d ---> %s tiene %d anos\n", aux->datos.id, aux->datos.nombre, aux->datos.edad);
}

int search(ListaSimple *lista, char n[]){ //Busca por nombre en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    Nodo *aux;
    int x;
    aux = lista->start;

    while(aux != NULL && n != aux->datos.nombre){
        x++;
        aux = aux->sig;
    }

    if(aux == NULL){
        return -1;
    }else{
        return x;
    }

}

int orden(ListaSimple *lista, char n[]){ //Comprobara enue lugar insertara el nodo

    //Devuelve la posicion en la que se insertara el nodo.

    Nodo *aux;
    int x = 0;
    aux = lista->start;

    while(aux != NULL && aux->datos.nombre[0] < n[0]){
        x++;
        aux = aux->sig;
    }

    if(aux == NULL){
        return -1;
    }else{
        return x;
    }

}

short int borrar(ListaSimple *lista){

    char nombre[50];
    Nodo *aux;
    int lugar, i;

    if(is_empty(lista) == 0){//La lista esta vacia y se devuelve 1
        printf("ERROR: La lista esta vacia, no hay nada que borrar");
        return 1;
    }else{//Si no esta vacia entonces...

        if(lista->total == 1){
            //Se borrara el unico nodo de la lista
            aux = lista->start;
            lista->start = NULL;
            lista->end = NULL;
            free(aux);

        }else{

            printf("Introduce el nombre completo de la persona que deseas borrar:\n");
            fflush(stdin);
            gets(nombre);
            for(i = 0; nombre[i] != NULL; ++i){
            nombre[i] = toupper(nombre[i]);
            }
            lugar = search(lista, nombre);

            if(lugar < 0){
                printf("ERROR: No se encontro ninguna persona con ese nombre.\n");
                return 1;
            }else if(lugar == lista->total){
                //Se borrara el final
                borrar_end(lista);
                return 0;
            }else if(lugar == 0){
                //Se borrara el inicio
                borrar_start(lista);
                return 0;
            }else{
                //Se borrara el nodo en la posicion "lugar"
                borrar_mid(lista, lugar);
                return 0;
            }
        }
    }
}

void borrar_start(ListaSimple *lista){//Se borrara el primer elemento de la lista

    Nodo *aux;
    aux = lista->start;

    lista->start = lista->start->sig;
    free(aux);
    lista->total--;

}

void borrar_end(ListaSimple *lista){

    Nodo *aux, *pre;
    aux = lista->end;
    pre = lista->start;

    while(pre->sig != aux){//Recorre la lista hasta llegar al penultimo nodo
        pre = pre->sig;
    }

    lista->end = pre;
    lista->end->sig = NULL;
    free(aux);
    lista->total--;

}

void borrar_mid(ListaSimple *lista, int lugar){

    int i;
    Nodo *aux, *pre;
    aux = lista->start;

    for(i = 0; i < lugar; i++){ //Recorrera la lista guardando un lugar anterioal alcutal
        pre = aux;
        aux = aux->sig;
    }

    pre->sig = aux->sig;
    free(aux);
    lista->total--;

}

void imp_lista(ListaSimple *lista){
    /*
    Recorre la lista con un auxiliar hasta llegar al ultimo (el que es nulo)
    imprimiendo todos sus datos.
    */

    Nodo *aux;
    aux = lista->start;

    system("cls");
    printf("\n\t\t**** D A T O S ****\n");
    while(aux != NULL){

        printf("%d ---> %s tiene %d anos\n", aux->datos.id, aux->datos.nombre, aux->datos.edad);
        aux = aux->sig;

    }

    system("pause");

}
