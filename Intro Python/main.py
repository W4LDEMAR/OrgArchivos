"""
ESTRUCTURA DE ARCHIVOS Y ORGANIZACION DE DATOS
Sosa Hernandez Saul Waldemar
Ejercicio 1 de programacion den python
"""

import os
import Comprobar as c
import ListaVRandom
import Promedio

if __name__ == '__main__':

    op = None

    while op != 0:

        os.system("cls")
        print("\n\t**** M E N U ****\n")
        print("1.- Promedio de n numeros")
        print("2.- Lista de numeros aleatorios")
        print("3.- Acciones con un arreglo")
        print("0.- SALIR")

        op = c.comp_op(0, 3)

        if op == 1:  # Llama a la funcion del promedio
            Promedio.prom()
        elif op == 2:  # Llama el menu de la lista con numeros aleatorios
            ListaVRandom.menuListaVRandom()




