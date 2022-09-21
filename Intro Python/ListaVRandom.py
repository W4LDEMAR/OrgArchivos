# Lista con valores random del primer parametro al segundo

import os
import random
import Comprobar


class Lista:
    def __init__(self, tam, par1, par2):
        self.tam = tam  # Tamano de la lista
        self.data = []  # Inicializa la lista
        # Los parametros nos indican desde que numero a que numero seran los rand
        self.par1 = par1  # Primer parametro
        self.par2 = par2  # Segundo parametro

    def llenar(self):  # Llena la lista aleatoriamente del parametro 1 al 2
        for i in range(self.tam):
            self.data.append(random.randint(self.par1, self.par2))

    def buscar(self):  # Comprueba que la opcion deseada este dentro de los parametros

        os.system("cls")
        print("\n\t*** B U S Q U E D A ***\n")
        print(f"Ingresa el numero que deseas buscar ({self.par1} - {self.par2}):")
        num = Comprobar.comp_n()

        if num < self.par1 or num > self.par2:
            print("ERROR: Elige una opcion dentro de los numeros que pueden haber en la lista.")
            print(f"Del {self.par1} al {self.par2}\n")
            os.system("pause")
            self.buscar()
            return

        if num in self.data:
            print(f"El numero {num} se encuentra dentro de la lista.")
        else:
            print(f"El numero {num} no esta dentro de la lista.")
        os.system("pause")

    def imp(self):  # To string de la lista
        print("\nLista de numeros aleatorios:")
        print(self.data)
        os.system("pause")


def menuListaVRandom(tam, par1, par2):  #Recibe los parametros
    op = None
    lista = Lista(tam, par1, par2)  # Lista de 6 valores con numeros random del 1 al 15
    lista.llenar()

    while op != 0:
        os.system("cls")
        print("\n\t*** L I S T A   C O N   V A L O R E S   R A N D O M***\n")
        print("1.- Buscar un numero en la lista.")
        print("2.- Mostrar la lista")
        print("3.- Hacer una lista diferente")
        print("0.- REGRESAR")

        op = Comprobar.comp_op(0, 3)

        if op == 1:
            lista.buscar()
        elif op == 2:
            lista.imp()
        elif op == 3:
            del lista
            lista = Lista(6, 1, 15)
            lista.llenar()
            print("Lista nueva creada con exito")

