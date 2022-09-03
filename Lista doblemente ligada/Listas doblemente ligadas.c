/*
    Estructura de Datos y Organizacion de archivos
Sosa Hernandez Saul Waldemar
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{

    int clave;
    char nombre[50];
    int tel;

} Alumno;

typedef struct Nodo{

    struct Nodo *pre;
    Alumno datos;
    struct Nodo *sig;

} Nodo;

typedef struct{

    Nodo *start;
    Nodo *end;
    int total;

} Lista;

int ver_op();
Lista *nuevaLista();
short int push(Lista *);
short int borrar(Lista *);

void main(){

    Lista *lista;
    lista = nuevaLista(); // Inicializando la lista
    int op;
    short int v;

    do{

        system("cls");
        printf("\t*** Lista Doblemente ligada ***\n");
        printf("1.- Agregar un alumno.\n");
        printf("2.- Borrar un alumno.\n");
        printf("3.- Buscar un alumno.\n");
        printf("4.- Desplegar la lista.\n");
        printf("0.- REGRESAR \n");
        op = ver_op(4);

        switch(op){
            case 1:
                v = push(lista);
                if(v != 0){
                    printf("Error: No se pudo completar la accion.\n");
                    system("pause");
                }else{
                    printf("Alumno agregado con exito!!");
                }
                break;
            case 2:
                v = borrar(lista);
                if(v != 0){
                    system("pause");
                }else{
                    printf("Alumno eliminado con exito!!");
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

}

int ver_op(int n){//Verifica si la opcion elegida esta dentro de los parametros

    int op;

    printf("\nIngrese la opcion deseada:\n");
    scanf("%d", &op);

    if(op < 0 || op > n){
        printf("ERROR: Elige una opcion dentro del menu.");
        system("pause");
        op = ver_op(n);
    }

    return op;
}

Lista *nuevaLista(){

    Lista *nueva;
    nueva = (Lista*)malloc(sizeof(Lista));
    nueva->start = NULL;
    nueva->end = NULL;
    nueva->total = 0;

    return nueva;
}

short int is_empty(Lista *lista){// Verifica si la lista esta vacia

    //0 si esta vacia y 1 si tiene datos

    if(lista->total == 0){
        return 0;
    }else{
        return 1;
    }
}

Alumno nuevaPersona(){ //Llenar los datos de la persona

    /*
    Pregunta al usuario por los datos de la persona que quiere ingresar al sistema
    Regresa un estructura de tipo Info
    */

    Alumno nuevo;
    char nombre[50];
    int i;

    system("cls");
    printf("\t\t**** L L E N A D O   D E   D A T O S ****\n\n");
    printf("Ingresa la clave del alumno:\n");
    fflush(stdin);
    scanf("%d", &nuevo.clave);
    printf("Ingresa el nombre del alumno:\n");
    fflush(stdin);
    gets(nombre);
    for(i = 0; nombre[i] != NULL; ++i){
        nombre[i] = toupper(nombre[i]);
    }
    strcpy(nuevo.nombre, nombre);
    printf("Ingresa el telefono del alumno:\n");
    fflush(stdin);
    scanf("%d", &nuevo.tel);

    return nuevo;

}

Nodo *nuevoNodo(){ //Crea un nodo para llenarlo con los datos solicitados

    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));

    if(nuevo != NULL){
        nuevo->pre = NULL;
        nuevo->datos = nuevaPersona();
        nuevo->sig = NULL;
    }

    return nuevo;
}

short int push(Lista *lista){
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

void push_end(Lista *lista, Nodo *n){//Inserta al final de la lista

    n->pre = lista->end;
    lista->end->sig = n;
    lista->end=n;
    lista->total++;

}

void push_start(Lista *lista, Nodo *n){

    n->sig = lista->start;
    lista->start->pre = n;
    lista->start = n;
    lista->total++;

}

void push_mid(Lista *lista, Nodo *n, int lugar){

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

    n->pre = pre;
    pre->sig = n;
    aux->pre = n;
    n->sig = aux;
    lista->total++;

}

void imp_search(Lista *lista){

    char nombre[50];
    int lugar, i, x, r, z;
    Nodo *aux;
    aux = lista->start;

    system("cls");
    printf("\n\t **** B U S Q U E D A ****\n");
    printf("1.- Buscar por nombre\n");
    printf("2.- Buscar por telefono\n");
    printf("3.- Buscar por clave\n");
    printf("0.- REGRESAR\n");
    r = ver_op(3);

    switch(r){

        case 0:
            return;
            break;

        case 1:
            printf("Ingresa el nombre la persona que deseas buscar:\n");
            fflush(stdin);
            gets(nombre);
            for(x = 0; nombre[x] != NULL; ++x){
                nombre[x] = toupper(nombre[x]);
            }
            lugar = search_nombre(lista, nombre);
            break;

        case 2:
            printf("Ingresa el telefono de la persona que deseas buscar:\n");
            fflush(stdin);
            scanf("%d", &z);
            lugar = search_tel(lista, z);
            break;

        case 3:
            printf("Ingresa la clave de la persona que deseas buscar:\n");
            fflush(stdin);
            scanf("%d", &z);
            lugar = search_clave(lista, z);
            break;

    }

    if(lugar < 0){
        printf("ERROR: No se encontro ningun alumno con ese nombre\n");
        printf("Veriica el ingreso de datos\n");
        system("pause");
        return;
    }

    for(i = 0; i < lugar; i++){
        aux = aux->sig;
    }

    printf("%d ---> %s ---> Tel. %d\n", aux->datos.clave, aux->datos.nombre, aux->datos.tel);
    system("pause");
}

int search_nombre(Lista *lista, char n[]){ //Busca por nombre en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    Nodo *aux;
    int x;
    aux = lista->start;

    while(aux != NULL && strcmp(n, aux->datos.nombre)){
        x++;
        aux = aux->sig;
    }

    if(aux == NULL){
        return -1;
    }else{
        return x;
    }

}

int search_tel(Lista *lista, int tel){//Busca por numero de tel. en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    Nodo *aux;
    int x;
    aux = lista->start;

    while(aux != NULL && tel != aux->datos.tel){
        x++;
        aux = aux->sig;
    }

    if(aux == NULL){
        return -1;
    }else{
        return x;
    }

}

int search_clave(Lista *lista, int clave){//Busca por numero de tel. en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    Nodo *aux;
    int x;
    aux = lista->start;

    while(aux != NULL && clave != aux->datos.clave){
        x++;
        aux = aux->sig;
    }

    if(aux == NULL){
        return -1;
    }else{
        return x;
    }

}

int orden(Lista *lista, char n[]){ //Comprobara enue lugar insertara el nodo

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

short int borrar(Lista *lista){

    char nombre[50];
    int lugar, i, x, r, z;
    Nodo *aux;
    aux = lista->start;

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

            system("cls");
            printf("\n\t **** B U S Q U E D A ****\n");
            printf("1.- Buscar por nombre\n");
            printf("2.- Buscar por telefono\n");
            printf("3.- Buscar por clave\n");
            printf("0.- REGRESAR\n");
            r = ver_op(3);

            switch(r){

                case 0:
                    return;
                    break;

                case 1:
                    printf("Ingresa el nombre la persona que deseas buscar:\n");
                    fflush(stdin);
                    gets(nombre);
                    for(x = 0; nombre[x] != NULL; ++x){
                        nombre[x] = toupper(nombre[x]);
                    }
                    lugar = search_nombre(lista, nombre);
                    break;

                case 2:
                    printf("Ingresa el telefono de la persona que deseas buscar:\n");
                    fflush(stdin);
                    scanf("%d", z);
                    lugar = search_tel(lista, z);
                    break;

                case 3:
                    printf("Ingresa la clave de la persona que deseas buscar:\n");
                    fflush(stdin);
                    scanf("%d", z);
                    lugar = search_clave(lista, z);
                    break;

            }

            if(lugar < 0){
                printf("ERROR: No se encontro ninguna persona con esos datos.\n");
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

void borrar_start(Lista *lista){//Se borrara el primer elemento de la lista

    Nodo *aux;
    aux = lista->start;

    lista->start->pre = NULL;
    lista->start = lista->start->sig;
    free(aux);
    lista->total--;

}

void borrar_end(Lista *lista){

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

void borrar_mid(Lista *lista, int lugar){

    int i;
    Nodo *aux, *pre;
    aux = lista->start;

    for(i = 0; i < lugar; i++){ //Recorrera la lista guardando un lugar anterioal alcutal
        pre = aux;
        aux = aux->sig;
    }

    pre->sig = aux->sig;
    aux->sig->pre = pre;
    free(aux);
    lista->total--;

}

void imp_lista(Lista *lista){
    /*
    Recorre la lista con un auxiliar hasta llegar al ultimo (el que es nulo)
    imprimiendo todos sus datos.
    */

    Nodo *aux;
    int x;

    system("cls");
    printf("1.- Mostrar en orden ascendente\n");
    printf("2.- Mostrar en orden descendente\n");
    printf("0.- REGRESAR\n");

    x = ver_op(2);

    switch(x){
        case 1:

            aux = lista->start;

            printf("\n\t\t**** D A T O S ****\n");
            while(aux != NULL){

                printf("%d ---> %s ---> Tel. %d\n", aux->datos.clave, aux->datos.nombre, aux->datos.tel);
                aux = aux->sig;

            }
            system("pause");
            break;

        case 2:

            aux = lista->end;
            printf("\n\t\t**** D A T O S ****\n");
            while(aux != NULL){

                printf("%d ---> %s ---> Tel. %d\n", aux->datos.clave, aux->datos.nombre, aux->datos.tel);
                aux = aux->pre;

            }
            system("pause");
            break;

    }
}



