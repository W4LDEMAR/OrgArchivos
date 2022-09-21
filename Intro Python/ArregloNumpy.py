# Arreglos utilizando Numpy (biblioteca)

import os
import Comprobar
import numpy as np


class Arreglo:
    def __init__(self, tam, par1, par2):
        self.data = np.random.randint(par1, par2, tam)  # Llena el arreglo de tamano n con numeros aletorios del 1 al 10

    def buscar(self):  # usca si el numero esta dentro del arreglo
        print("Ingresa el numero que deseas busar en el arreglo:")
        n = Comprobar.comp_n()
        if n in self.data:
            print("El numero si esta dentro del arreglo.")
        else:
            print("El numero no se encuentra dentro del arreglo.")

        os.system("pause")

    def del_repetidos(self):  # Borra los numeros repetidos del arreglo
        print("Se han eliminado los numeros repetidos con exito!")
        self.data = np.unique(self.data)
        os.system("pause")

    def par_to0(self):  # Cambia los numeros pares del arreglo por un 0
        print("Se han cambiado los numeros pares por '0' con exito!")
        self.data = np.where(self.data % 2 == 0, 0, self.data)  # Si el modulo del numero y 2 es 0 entonces es par
        os.system("pause")

    def orden(self):  # Ordena el arreglo
        os.system("cls")
        print("\n\t*** O R D E N A R ***\n")
        print("1.- De menor a mayor (<<)")
        print("2.- De mayor a menor (>>)")
        print("0.- REGRESAR")

        op = Comprobar.comp_op(0, 2)

        if op == 0:
            return
        else:
            self.data.sort()
            if op == 1:
                print("El arreglo se ordeno de menor a mayor con exito!")
                os.system("pause")
            else:
                print("El arreglo se ordeno de mayor a menor con exito!")
                self.data = self.data[::-1]  # Ordena >>> con la lista ya ordenada <<<
                os.system("pause")

    def prom(self):
        print("El promedio del arreglo es:")
        print(self.data.mean())
        os.system("pause")

    def imp_array(self):  # Imprime el arreglo
        print(f"ARREGLO --> {self.data}\n")


def menuArreglo(tam, par1, par2):
    op = None
    arr = Arreglo(tam, par1, par2)

    while op != 0:
        os.system("cls")
        print("\n\t*** A R R E G L O   C O N   V A L O R E S   R A N D O M ***\n")
        arr.imp_array()
        print("1.- Buscar un numero en el arreglo.")
        print("2.- Eliminar numeros repetidos")
        print("3.- Cambiar los numeros pares por ceros (0)")
        print("4.- Ordenar el arreglo")
        print("5.- Obtener el promedio del arreglo")
        print("0.- REGRESAR")

        op = Comprobar.comp_op(0, 5)

        if op == 1:
            arr.buscar()
        elif op == 2:
            arr.del_repetidos()
        elif op == 3:
            arr.par_to0()
        elif op == 4:
            arr.orden()
        elif op == 5:
            arr.prom()
