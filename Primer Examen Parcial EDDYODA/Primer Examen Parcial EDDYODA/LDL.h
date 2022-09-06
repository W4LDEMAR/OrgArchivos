#ifndef LDL_H_INCLUDED
#define LDL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{

    int clave;
    char nombre[50];
    int tel;

} AlumnoD;

typedef struct NodoD{

    struct NodoD *pre;
    Alumno datos;
    struct NodoD *sig;

} NodoD;

typedef struct{

    NodoD *start;
    NodoD *end;
    int total;

} ListaD;

int ver_opD();
ListaD *nuevaListaD();
short int pushD(ListaD *);
short int borrarD(ListaD *);

ListaD menuLDL(ListaD *lista){

    if(!lista){
        lista = nuevaListaD(); // Inicializando la lista si est no existe
    }

    //Si ya existe entonces trabaara con la lista ya creada

    int op;
    short int v;

    do{

        system("cls");
        printf("\t*** Lista Doblemente ligada ***\n");
        printf("1.- Agregar un alumno.\n");
        printf("2.- Borrar un alumno.\n");
        printf("3.- Buscar un alumno.\n");
        printf("4.- Desplegar la lista.\n");
        printf("0.- SALIR \n");
        op = ver_opD(4);

        switch(op){
            case 1:
                v = pushD(lista);
                if(v != 0){
                    printf("Error: No se pudo completar la accion.\n");
                    system("pause");
                }else{
                    printf("Alumno agregado con exito!!");
                }
                break;
            case 2:
                v = borrarD(lista);
                if(v != 0){
                    system("pause");
                }else{
                    printf("Alumno eliminado con exito!!");
                    system("pause");
                }
                break;
            case 3:
                imp_searchD(lista);
                break;
            case 4:
                imp_listaD(lista);
                break;
        }

    }while(op != 0);

    return lista;
}

int ver_opD(int n){//Verifica si la opcion elegida esta dentro de los parametros

    int op;

    printf("\nIngrese la opcion deseada:\n");
    scanf("%d", &op);

    if(op < 0 || op > n){
        printf("ERROR: Elige una opcion dentro del menu.");
        system("pause");
        op = ver_opD(n);
    }

    return op;
}

ListaD *nuevaListaD(){

    ListaD *nueva;
    nueva = (ListaD*)malloc(sizeof(ListaD));
    nueva->start = NULL;
    nueva->end = NULL;
    nueva->total = 0;

    return nueva;
}

short int is_emptyD(ListaD *lista){// Verifica si la lista esta vacia

    //0 si esta vacia y 1 si tiene datos

    if(lista->total == 0){
        return 0;
    }else{
        return 1;
    }
}

AlumnoD nuevaPersonaD(){ //Llenar los datos de la persona

    /*
    Pregunta al usuario por los datos de la persona que quiere ingresar al sistema
    Regresa un estructura de tipo Info
    */

    AlumnoD nuevo;
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

NodoD *nuevoNodoD(){ //Crea un nodo para llenarlo con los datos solicitados

    NodoD *nuevo;
    nuevo = (NodoD*)malloc(sizeof(NodoD));

    if(nuevo != NULL){
        nuevo->pre = NULL;
        nuevo->datos = nuevaPersona();
        nuevo->sig = NULL;
    }

    return nuevo;
}

short int pushD(ListaD *lista){
    //Se decidira si se insertara al inicio, en medio o al final.

    NodoD *nuevo;
    char nombre[50];
    int lugar;

    nuevo = nuevoNodoD();
    strcpy(nombre, nuevo->datos.nombre);

    if(is_emptyD(lista) == 0){ //verifica si esta vacia
        //Si la lista esta vacia entonces hara un push inicial

        lista->start = nuevo;
        lista->end = nuevo;
        lista->total++;

        return 0;
    }else{
        lugar = ordenD(lista, nuevo->datos.nombre);
        if(lugar < 0){
            //Se insertara al final
            push_endD(lista, nuevo);
            return 0;
        }else if(lugar == 0){
            //Se insertara al incio
            push_startD(lista, nuevo);
            return 0;
        }else{
            //Se insertara al en la posicion de "lugar"
            push_midD(lista, nuevo, lugar);
            return 0;
        }
    }
    return 1;
}

void push_endD(ListaD *lista, NodoD *n){//Inserta al final de la lista

    n->pre = lista->end;
    lista->end->sig = n;
    lista->end=n;
    lista->total++;

}

void push_startD(ListaD *lista, NodoD *n){

    n->sig = lista->start;
    lista->start->pre = n;
    lista->start = n;
    lista->total++;

}

void push_midD(ListaD *lista, NodoD *n, int lugar){

    NodoD *aux, *pre;
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

void imp_searchD(ListaD *lista){//Imprime unicamente el nodo que el usuario indica

    char nombre[50];
    int lugar, i, x, r, z;
    NodoD *aux;
    aux = lista->start;

    system("cls");
    printf("\n\t **** B U S Q U E D A ****\n");
    printf("1.- Buscar por nombre\n");
    printf("2.- Buscar por telefono\n");
    printf("3.- Buscar por clave\n");
    printf("0.- REGRESAR\n");
    r = ver_opD(3);

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
            lugar = search_nombreD(lista, nombre);
            break;

        case 2:
            printf("Ingresa el telefono de la persona que deseas buscar:\n");
            fflush(stdin);
            scanf("%d", &z);
            lugar = search_telD(lista, z);
            break;

        case 3:
            printf("Ingresa la clave de la persona que deseas buscar:\n");
            fflush(stdin);
            scanf("%d", &z);
            lugar = search_claveD(lista, z);
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

int search_nombreD(ListaD *lista, char n[]){ //Busca por nombre en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    NodoD *aux;
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

int search_telD(ListaD *lista, int tel){//Busca por numero de tel. en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    NodoD *aux;
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

int search_claveD(ListaD *lista, int clave){//Busca por numero de tel. en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    NodoD *aux;
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

int ordenD(ListaD *lista, char n[]){ //Comprobara enue lugar insertara el nodo

    //Devuelve la posicion en la que se insertara el nodo.

    NodoD *aux;
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

short int borrarD(ListaD *lista){

    char nombre[50];
    int lugar, i, x, r, z;
    NodoD *aux;
    aux = lista->start;

    if(is_emptyD(lista) == 0){//La lista esta vacia y se devuelve 1
        printf("ERROR: La lista esta vacia, no hay nada que borrar");
        return 1;
    }else{

        if(lista->total == 1){
            //Se borrara el unico nodo de la lista
            printf("El unico alumno de la lista sera borrado...");
            system("pause");
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
            r = ver_opD(3);

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
                    lugar = search_nombreD(lista, nombre);
                    break;

                case 2:
                    printf("Ingresa el telefono de la persona que deseas buscar:\n");
                    fflush(stdin);
                    scanf("%d", z);
                    lugar = search_telD(lista, z);
                    break;

                case 3:
                    printf("Ingresa la clave de la persona que deseas buscar:\n");
                    fflush(stdin);
                    scanf("%d", z);
                    lugar = search_claveD(lista, z);
                    break;

            }

            if(lugar < 0){
                printf("ERROR: No se encontro ninguna persona con esos datos.\n");
                return 1;
            }else if(lugar == lista->total){
                //Se borrara el final
                borrar_endD(lista);
                return 0;
            }else if(lugar == 0){
                //Se borrara el inicio
                borrar_startD(lista);
                return 0;
            }else{
                //Se borrara el nodo en la posicion "lugar"
                borrar_midD(lista, lugar);
                return 0;
            }

        }
    }
}

void borrar_startD(ListaD *lista){//Se borrara el primer elemento de la lista

    NodoD *aux;
    aux = lista->start;

    lista->start->pre = NULL;
    lista->start = lista->start->sig;
    free(aux);
    lista->total--;

}

void borrar_endD(ListaD *lista){

    NodoD *aux, *pre;
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

void borrar_midD(ListaD *lista, int lugar){

    int i;
    NodoD *aux, *pre;
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

void imp_listaD(ListaD *lista){
    /*
    Recorre la lista con un auxiliar hasta llegar al ultimo (el que es nulo)
    imprimiendo todos sus datos.
    */

    NodoD *aux;
    int x;

    system("cls");

    if(lista->total == 0){//Si la lista esta vacia no entra a la seleccion de orden de impresion
        printf("\n\n\tERROR: La lista se encuentra vacia ingresa primero algunos datos\n");
        system("pause");
        return;
    }

    printf("1.- Mostrar en orden ascendente\n");
    printf("2.- Mostrar en orden descendente\n");
    printf("0.- REGRESAR\n");

    x = ver_opD(2);

    switch(x){
        case 1://Imprimira del inicio de la lista hasta el final

            aux = lista->start;

            printf("\n\t\t**** D A T O S ****\n");
            while(aux != NULL){

                printf("%d ---> %s ---> Tel. %d\n", aux->datos.clave, aux->datos.nombre, aux->datos.tel);
                aux = aux->sig;

            }
            break;

        case 2://Imprimira del final de la lista hasta el inicio

            aux = lista->end;
            printf("\n\t\t**** D A T O S ****\n");
            while(aux != NULL){

                printf("%d ---> %s ---> Tel. %d\n", aux->datos.clave, aux->datos.nombre, aux->datos.tel);
                aux = aux->pre;

            }
            break;

    }

    system("pause");
}

#endif // LDL_H_INCLUDED
