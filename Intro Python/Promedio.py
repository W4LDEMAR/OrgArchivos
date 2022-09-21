# Promedio de n valores
import os

import Comprobar


def prom():
    os.system("cls")
    print("\n\t*** P R O M E D I O ***\n")
    print("Ingresa el numero de datos que deseas promediar:")
    n = Comprobar.comp_n()
    res = 0

    for i in range(n):
        print(f"Ingresa el {i + 1}° numero:")
        res += Comprobar.comp_n()

    return res / n
