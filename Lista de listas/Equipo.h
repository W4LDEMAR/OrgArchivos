#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED

#include "Listas.h"

ListaPrincipal *menuEquipo(ListaPrincipal *lista);
short int push(ListaPrincipal *lista);

ListaPrincipal *menuEquipo(ListaPrincipal *lista){

    int op;
    short int v;

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
            v = push(lista);
                if(v != 0){
                    printf("Error: No se pudo completar la accion.\n");
                    system("pause");
                }else{
                    printf("Alumno agregado con exito!!");
                    system("pause");
                }
            break;

        case 2:
            break;

        case 3:
            break;
        }

    }while(op != 0);

}

short int push(ListaPrincipal *lista){
    //Se decidira si se insertara al inicio, en medio o al final.

    Nodo *nuevo;
    int lugar;

    nuevo = nuevoNodo();

    //Hacer validacion por si hay un equipo con el mismo nombre
    while(search_nombre(lista, nuevo->team->nombre_team) != -1){
        printf("ERROR: Ya existe un equipo con ese nombre. Intenta con otro.\n");
        system("pause");
        nuevo = nuevoNodo();
    }

    while(search_ciudad(lista, nuevo->team->ciudad != 1)){
        printf("ERROR: Ya existe un equipo con esa ciudad. Intenta con otra.\n");
        system("pause");
        nuevo = nuevoNodo();
    }

    if(lista->total == 0){ //verifica si esta vacia
        //Si la lista esta vacia entonces hara un push inicial

        lista->start = nuevo;
        lista->end = nuevo;
        lista->total++;

        return 0;
    }else{
        lugar = orden(lista, nuevo->team->nombre_team);
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

int search_nombre(ListaPrincipal *lista, char n[]){ //Busca por nombre en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    Nodo *aux;
    int x;
    aux = lista->start;

    while(aux != NULL && strcmp(n, aux->team->nombre_team)){
        x++;
        aux = aux->abajo;
    }

    if(aux == NULL){
        return -1;
    }else{
        return x;
    }

}

int search_ciudad(ListaPrincipal *lista, char n[]){ //Busca por ciudad en la lista y reresa la posicion del nodo en el que esta.
    //Si no se encontro el nombre regresa -1

    Nodo *aux;
    int x;
    aux = lista->start;

    while(aux != NULL && strcmp(n, aux->team->ciudad)){
        x++;
        aux = aux->abajo;
    }

    if(aux == NULL){
        return -1;
    }else{
        return x;
    }

}

int orden(ListaPrincipal *lista, char n[]){ //Comprobara enue lugar insertara el nodo

    //Devuelve la posicion en la que se insertara el nodo.

    Nodo *aux;
    int x = 0;
    aux = lista->start;

    while(aux != NULL && aux->team->nombre_team[0] < n[0]){
        x++;
        aux = aux->abajo;
    }

    if(aux == NULL){
        return -1;
    }else{
        return x;
    }

}

void push_end(ListaPrincipal *lista, Nodo *n){//Inserta al final de la lista

    n->arriba = lista->end;
    lista->end->abajo = n;
    lista->end=n;
    lista->total++;

}

void push_start(ListaPrincipal *lista, Nodo *n){

    n->abajo = lista->start;
    lista->start->arriba = n;
    lista->start = n;
    lista->total++;

}

void push_mid(ListaPrincipal *lista, Nodo *n, int lugar){

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
        aux = aux->abajo;
    }

    n->arriba = pre;
    pre->abajo = n;
    aux->arriba = n;
    n-> abajo= aux;
    lista->total++;

}

short int borrar(ListaPrincipal *lista){

    char nombre[50];
    int lugar, i, x, r, z;
    Nodo *aux;
    aux = lista->start;

    if(lista->total == 0){//La lista esta vacia y se devuelve 1
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
            printf("\n\t **** B O R R A D O ****\n");
            printf("1.- Borrar por nombre de quipo\n");
            printf("2.- Borrar por ciudad\n");
            printf("0.- REGRESAR\n");
            r = comp_op(3);

            switch(r){

                case 0:
                    return;
                    break;

                case 1:
                    printf("Ingresa el nombre del equipo que deseas borrar:\n");
                    fflush(stdin);
                    gets(nombre);
                    for(x = 0; nombre[x] != NULL; ++x){
                        nombre[x] = toupper(nombre[x]);
                    }
                    lugar = search_nombre(lista, nombre);
                    break;

                case 2:
                    printf("Ingresa la ciudad del equipo que deseas borrar:\n");
                    fflush(stdin);
                    gets(nombre);
                    for(x = 0; nombre[x] != NULL; ++x){
                        nombre[x] = toupper(nombre[x]);
                    }
                    lugar = search_ciudad(lista, nombre);
                    break;

            }

            if(lugar < 0){
                printf("ERROR: No se encontro ningun equipo con esos datos.\n");
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

void borrar_start(ListaPrincipal *lista){//Se borrara el primer elemento de la lista

    Nodo *aux;
    aux = lista->start;

    lista->start->arriba = NULL;
    lista->start = lista->start->abajo;
    free(aux);
    lista->total--;

}

void borrar_end(ListaPrincipal *lista){

    Nodo *aux, *pre;
    aux = lista->end;
    pre = lista->start;

    while(pre->abajo != aux){//Recorre la lista hasta llegar al penultimo nodo
        pre = pre->abajo;
    }

    lista->end = pre;
    lista->end->abajo = NULL;
    free(aux);
    lista->total--;


}

void borrar_mid(ListaPrincipal *lista, int lugar){

    int i;
    Nodo *aux, *pre;
    aux = lista->start;

    for(i = 0; i < lugar; i++){ //Recorrera la lista guardando un lugar anterioal alcutal
        pre = aux;
        aux = aux->abajo;
    }

    pre->abajo = aux->abajo;
    aux->abajo->arriba = pre;
    free(aux);
    lista->total--;

}

void imp_lista(ListaPrincipal *lista){
    /*
    Recorre la lista con un auxiliar hasta llegar al ultimo (el que es nulo)
    imprimiendo todos sus datos.
    */

    Nodo *aux;
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

    x = comp_op(2);

    switch(x){
        case 1://Imprimira del inicio de la lista hasta el final

            aux = lista->start;

            printf("\n\t\t**** D A T O S ****\n");
            while(aux != NULL){

                printf("%s ---- [%s] con %d jugadores.\n", aux->team->nombre_team, aux->team->ciudad, aux->team->total_j);
                aux = aux->abajo;

            }
            break;

        case 2://Imprimira del final de la lista hasta el inicio

            aux = lista->end;
            printf("\n\t\t**** D A T O S ****\n");
            while(aux != NULL){

                printf("%s ---- [%s] con %d jugadores.\n", aux->team->nombre_team, aux->team->ciudad, aux->team->total_j);
                aux = aux->arriba;

            }
            break;

    }

    system("pause");
}

#endif // EQUIPO_H_INCLUDED
