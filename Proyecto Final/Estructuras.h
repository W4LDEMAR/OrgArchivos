#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCuentas 5  //Numero maximo de cuentas
#define TamHashing 20

typedef struct{

    char nombre[20];
    char direccion[100];
    int telefono;
    char correo[50];

} Persona;

typedef struct{

    int n_cuenta;
    float saldo;
    char t_cuenta[20];

} Cuenta;

typedef struct Cliente{

    int n_cliente;
    Persona datos;
    float saldo_p;  // Salod positivo - a favor (suma cuentas de debito)
    float saldo_n;  // Saldo negativo - deudor (suma cuentas de credito)
    int cant_cuentas;
    Cuenta C[MAXCuentas];
    struct Cliente *sig;

} Cliente;

int comp_num();
Persona nuevaPersona();
Cuenta nuevaCuenta(int);
int comp_op(int);
float comp_float();

unsigned int hash(char *nombre){ // Generar el numero de posicion en la tabla de hashing

    int i;
    unsigned int n_hash;

    int length = strlen(nombre);
    for(i = 0; i < length; i++){
        n_hash += nombre[i];
        n_hash = (n_hash * nombre[i]) % TamHashing;
    }

    return n_hash;

}

Persona nuevaPersona(){  // Pide los datos necesarios para la estructura persona

    Persona nuevo;
    int i;

    printf("Ingresa el nombre del cliente:\n");
    fflush(stdin);
    gets(nuevo.nombre);
    for(i = 0; nuevo.nombre[i] != NULL; ++i){
        nuevo.nombre[i] = toupper(nuevo.nombre[i]);
    }
    printf("Ingresa la direccion del cliente:\n");
    fflush(stdin);
    gets(nuevo.direccion);
    for(i = 0; nuevo.direccion[i] != NULL; ++i){
        nuevo.direccion[i] = toupper(nuevo.direccion[i]);
    }
    printf("Ingresa el telefono del cliente:\n");
    fflush(stdin);
    nuevo.telefono = comp_num();
    printf("Ingresa el correo del cliente:\n");
    fflush(stdin);
    gets(nuevo.correo);
    fflush(stdin);

    return nuevo;

}

Cuenta nuevaCuenta(int n_cuenta){  //Llena la estructura de cuenta

    Cuenta nuevo;
    int i, x;

    system("cls");
    printf("\n\t*** N U E V A   C U E N T A ***\n");
    printf("Cuenta numero %d -->\n", n_cuenta);
    nuevo.n_cuenta = n_cuenta;
    printf("Elige el tipo de cuenta:\n0.- Debito\n1.- Credito");
    x = comp_op(1);
    if(x == 0){
        strcpy(nuevo.t_cuenta, "DEBITO");
        printf("Ingrese el saldo de apertura:\n");
        fflush(stdin);
        nuevo.saldo = comp_float();
    }else{
        strcpy(nuevo.t_cuenta, "CREDITO");
        nuevo.saldo = 0;
        printf("Se aprobo el credito correctamente.\n");
    }

    return nuevo;
}


Cliente *nuevoCliente(){  // Llena la estructura de cliente

    Cliente *nuevo;
    nuevo = (Cliente*)malloc(sizeof (Cliente));
    int op, op2, n_cliente, cuentas_de_cliente;
    float dinero;

    n_cliente = rand() % 4000 + 1000; // Genera numero aleatorio entre 1000 y 5000

    system("cls");
    printf("\n\t*** N U E V O   C L I E N T E ***\n");
    nuevo->n_cliente = n_cliente;
    printf("Cliente %d -->\n", nuevo->n_cliente);
    nuevo->datos = nuevaPersona();
    nuevo->saldo_p = 0;
    nuevo->saldo_n = 0;
    nuevo->cant_cuentas = 1;
    nuevo->sig = NULL;

    return nuevo;

}

int comp_op(int n){  // Verifica si el usuario ingreso una opcion dentro del menu

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

float comp_float(){ //Comprueba si el usuario introdujo un numero

    int comp;
    float n;

    if(scanf("%f", &n)){
        return n;
    }else{
        do{
            printf("ERROR: Introduce un saldo valido.\n");
            scanf("%*[^\n]%*c"); //Sacar el flujo para no caer en un bucle
            comp = scanf("%f", &n);
        }while(comp != 1);
    }

    return n;

}

#endif // ESTRUCTURAS_H_INCLUDED
