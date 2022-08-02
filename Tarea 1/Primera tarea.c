#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int valor;
    char primo[15];
    int invertido;
} Num;

Num* llenar(Num [], Num *);
int voltear(int);
void imp(Num *, Num *);


int main()
{
    Num datos[5], *start, *end;
    start = end = &datos[0];

    while(&datos[5] != end){
        end = llenar(datos, end);
    }

    printf("\t *** PRIMERA TAREA ***");
    imp(start, end);


    return 0;
}

Num* llenar(Num datos[], Num *end){

    int x = 0;
    x = (rand() % 85000) + 15000;

    end -> valor = x;

    if(x % 2 == 0){
        strcpy(end -> primo, "NO ES PRIMO");
    }else{
        strcpy(end -> primo, "SI ES PRIMO");
    }

    end -> invertido = voltear(x);

    end ++;

    return end;
}

int voltear(int n){

    int f = 0, res = 0;

    while(n != 0){
        f = n % 10;
        n = n / 10;
        res = res * 10 + f;
    }

    return res;
}

void imp(Num *start, Num *end){

    Num *aux;
    int n = 1;
    printf("\n");

    for(aux = start; aux < end; aux++){
        printf("\n %d.- [%d] --> [%d] \t %s", n, aux -> valor, aux -> invertido, aux -> primo);
        n++;
    }
}
