#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#define MAXCuentas 5  //Numero maximo de cuentas

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

typedef struct{

    int n_cliente;
    Persona datos;
    float saldo_p;  // Salod positivo - a favor (suma cuentas de debito)
    float saldo_n;  // Saldo negativo - deudor (suma cuentas de credito)
    int cant_cuentas;
    Cuenta C[MAXCuentas];

} Cliente;

int comp_num();
Persona nuevaPersona();
Cuenta nuevaCuenta(int);
int comp_op(int);
float comp_float();

Persona nuevaPersona(){  // Pide los datos necesarios para la estructura persona

    Persona nuevo;
    int i;

    printf("Ingresa el nombre del cliente:\n");
    fflush(stdin);
    gets(nuevo.nombre)
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

    return nuevo;

}

Cuenta nuevaCuenta(int n_cuenta){  //Llena la estructura de cuenta

    Cuenta nuevo;
    int i;

    system("cls");
    printf("\n\t*** N U E V A   C U E N T A ***\n");
    printf("Cuenta %d -->\n", n_cuenta);
    nuevo.n_cuenta = n_cuenta;
    printf("Ingresa el tipo de cuenta (credito/debito):\n");
    fflush(stdin);
    gets(nuevo.t_cuenta);
    for(i = 0; nuevo.t_cuenta[i] != NULL; ++i){
        nuevo.t_cuenta[i] = toupper(nuevo.t_cuenta[i]);
    }
    printf("Ingrese el saldo de la cuenta:\n");
    fflush(stdin);
    nuevo.saldo = comp_float();

    return nuevo;
}

Cliente nuevoCliente(int n_cliente){  // Llena la estructura de cliente

    Cliente nuevo;
    int op, op2;

    system("cls");
    printf("\n\t*** N U E V O   C L I E N T E ***\n");
    nuevo.n_cliente = n_cliente;
    printf("Cliente %d -->\n", nuevo.n_cliente);
    nuevo.datos = nuevaPersona();
    nuevo.saldo_p = 0;
    nuevo.saldo_n = 0;
    nuevo.cant_cuentas = 0;

    printf("Deseas agregarle una cuenta al nuevo cliente?\n");
    printf("1.- SI, agrega una cuenta.\n");
    printf("0.- NO, agrega la cuenta mas tarde.\n");
    op = comp_op(1);

    if(op == 1){
        do{

            if(nuevo.cant_cuentas < 5){

                nuevo.C[nuevo.cant_cuentas] = nuevaCuenta(nuevo.cant_cuentas + 1); //FALTA CAMBIAR EL SALDO CON LOS DATOS DE LA NUEVA CUENTA
                nuevo.cant_cuentas++;
                printf("Se agrego la cuenta con exito!\n\n");
                printf("Deseas agregar otra cuenta al nuevo cliente?\n");
                printf("0.- NO, regresar al menu principal.\n");
                printf("1.- SI, ingresar otra cuenta al cliente.\n");
                op2 = comp_op(1);

            }else{

                printf("ERROR: Has alcanzado el limite de cuentas por cliente.\n");
                system("pause");
                op2 = 0;

            }

        }while(op2 != 0);
    }

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
