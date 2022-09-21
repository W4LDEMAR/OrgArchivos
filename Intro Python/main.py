"""
ESTRUCTURA DE ARCHIVOS Y ORGANIZACION DE DATOS
Sosa Hernandez Saul Waldemar
Ejercicio 1 de programacion en python
"""

import os
import Comprobar
import ListaVRandom
import Promedio
import ArregloNumpy

if __name__ == '__main__':

    op = None

    while op != 0:

        os.system("cls")
        print("\n\t**** M E N U ****\n")
        print("1.- Promedio de n numeros")
        print("2.- Lista de numeros aleatorios")
        print("3.- Acciones con un arreglo")
        print("0.- SALIR")

        op = Comprobar.comp_op(0, 3)

        if op == 1:  # Llama a la funcion del promedio
            print(f"El promedio es: {Promedio.prom()}")
            os.system("pause")
        elif op == 2:  # Llama el menu de la lista con numeros aleatorios
            ListaVRandom.menuListaVRandom(6, 1, 15)
        elif op == 3:  # Llama el menu del arreglo con numeros aleatorios
            ArregloNumpy.menuArreglo(10, 1, 10)




