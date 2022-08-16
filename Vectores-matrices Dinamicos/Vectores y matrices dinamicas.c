#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int menuVector();
int menuMatriz();
int* creaVector();

int main(){

    int *vec, tam, op, op2;

    do{
        system("cls");
        printf("\t***ARREGLOS DINAMICOS***\n");
        printf("1.- Vector Dinamico");
        printf("2.- Matriz Dinamica");
        printf("0.- Salir");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                op2 = menuVector();
                switch(op2){
                    case 1:
                        if(!vec){
                            vec = creaVector();
                        }else{
                            printf("\tERROR: Ya hay un vector, limpialo para crear uno nuevo");
                        }
                        break;
                    case 2:

                        break;
                }
                break;

            case 2:
                op2 = menuMatriz();
                break;

            case 3:
                system("cls");
                printf("\n\n\t***FIN DEL PROGRAMA***");
                break;

        }
    }while(op != 0);

    return 0;
}

int menuVector(){

    int x;

    printf("cls");
    printf("\t****VECTOR DINAMICO***\n");
    printf("1.- Crear Vector");
    printf("2.- Insertar dato");
    printf("3.- Eliminar un dato");
    printf("4.- Buscar un dato (primera ocurrencia)");
    printf("5.- Imprimir vector");
    printf("6.- Liberar el vector");
    printf("0.- Regresar");

    if(x < 0 || x > 6){
        printf("\tERROR: Elige una opcion valida.")
        system("pause");
        x = menuVector();
    }

    return x;
}

int menuMatriz(){

    int x;

    printf("cls");
    printf("\t****MATRIZ DINAMICA***\n");
    printf("1.- Crear Matriz");
    printf("2.- Llenar por columna");
    printf("3.- Llenar como 'viborita'");
    printf("4.- Llenar en espiral");
    printf("5.- Crear cuadrado magico");
    printf("6.- Imprimir matriz");
    printf("7.- Liberar la matriz")
    printf("0.- Regresar");

    if(x < 0 || x > 7){
        printf("\tERROR: Elige una opcion valida.")
        system("pause");
        x = menuVector();
    }

    return x;
}

int* creaVector(){

    int tam;

    printf("\t¿De que tamaño sera el vector\n?");
    fflush(stdin);
    scanf("%d", &tam);

    while(tam < 1){

        printf("ERROR: Ingresa un tamaño de vector valido.");
        system("pause");
        printf("\t¿De que tamaño sera el vector\n?");
        fflush(stdin);
        scanf("%d", &tam);

    }

    return (int*)malloc(tam*sizeof(int));
}


