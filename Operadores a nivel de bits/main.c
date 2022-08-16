//5/08/2022. Díaz Buzo Omar Rodrigo,Sosa Hernández Saúl Waldemar. Manejo bits con operadores. Compilador: GNU GCC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxban 8
#define menu 0

//encienda un bit. Recibe el char, el número de bandera a encender y la cantidad máxima de banderas. Regresa 1 de exito o 0 de error
short int enciende_bandera(unsigned char*,short int, short int);
//apaga un bit. Recibe el char, el número de bandera a apagar y la cantidad máxima de banderas. Regresa 1 de exito o 0 de error
short int apaga_bandera(unsigned char*,short int, short int);
//imprime todas las banderas. Recibe el char y el máximo de banderas. Regresa un 1 de exito
short int despliega(unsigned char*,short int);
//verifica el estado de una bandera. Recibe el char, el número de la bandera a verificar y el máximo de banderas. Regresa un 1 si está encendida y un 0 si está apagada
short int comprueba(unsigned char*, short int, short int);

int main()
{
    unsigned char banderas=0;
    short int numban,maxband=maxban,opc,exito,i;
    do
    {
        printf("\nSeleccione una opcion\n1.Enciende bandera\n2.Apaga bandera\n3.Comprueba estado de bandera\n4.Despliega banderas\n0.Salir\n");
        scanf("%hu",&opc);
        printf("\n");
        switch(opc)
        {
            case 1: printf("Que bandera desea encender (1-%d): ",maxband);
            scanf("%hu",&numban);
            exito=enciende_bandera(&banderas,numban,maxband);
            if(exito==1)
                printf("Bandera encendida\n");
            else
                printf("Error en el proceso\n");
            break;

          case 2: printf("Que bandera desea apagar (1-%d): ",maxband);
          scanf("%hu",&numban);
          exito=apaga_bandera(&banderas,numban,maxband);
          if(exito==1)
                printf("Bandera apagada\n");
            else
                printf("Error en el proceso\n");
            break;

          case 3: printf("Que bandera desea comprobar (1-%d): ",maxband);
          scanf("%hu",&numban);
          exito=comprueba(&banderas,numban,maxband);
          if(exito==1)
            printf("La bandera esta encendida\n");
            else
          {
            if(exito==0)
            printf("La bandera esta apagada\n");
          else
            printf("Error en el proceso\n");
          }
          break;
          case 4:
        for(i=8;i>0;i--)
            printf("%d-",i);
        printf("\n");
          exito=despliega(&banderas,maxband);
            if(exito==1)
              printf("\nImpresion exitosa\n");
          break;
        }
    }while(opc!=menu);
}

short int enciende_bandera(unsigned char *banderas, short int numban, short int maxband)
{
    if(numban<1 || numban>maxband)
        return 0;
    else
    {
        unsigned char valorban;
        if(numban<=2)
            valorban=numban;
        else
            valorban=pow(2,numban-1);
        *banderas=*banderas|valorban;
        return 1;
    }
}

short int apaga_bandera(unsigned char *banderas, short int numban, short int maxband)
{
  if(numban<1 || numban>maxband)
        return 0;
    else
    {
        short int valorban,aux=0;
        if(numban<=2)
            valorban=numban;
        else
            valorban=pow(2,numban-1);
        aux=~(*banderas&valorban);
        *banderas=*banderas&aux;
        return 1;
    }
}

short int comprueba(unsigned char *banderas, short int numban, short int maxband)
{
  if(numban<1 || numban>maxband)
        return 2;
    else
    {
        unsigned char valorban,aux;
        if(numban<=2)
            valorban=numban;
        else
            valorban=pow(2,numban-1);
      aux=*banderas&valorban;
      if(valorban==aux)
        return 1;
      else
        return 0;
    }
}

short int despliega(unsigned char *banderas,short int maxband)
{
  short int i, x;
  unsigned char aux;
  for(i=maxband;i>0;i--)
    {
        if(i<=2)
            x=i;
        else
          x=pow(2,i-1);
      aux=*banderas&x;
      if(aux==x)
        printf("1 ");
      else
        printf("0 ");
    }
  printf("\n");
  return 1;
}

