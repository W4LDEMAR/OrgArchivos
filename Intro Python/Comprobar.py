# Comprobaciones necesarias


def comp_n():  # Comprueba si el usuario ingreso un numero
    n = input()

    while not n.isnumeric():
        print("ERROR: No se ingreso un numero, intenta de nuevo.")
        n = input()

    return int(n)


def comp_op(x, y):  # Comprueba que la opcion deseada este dentro de los parametros

    print("Ingresa la opcion deseada:")
    op = comp_n()

    while op < x or op > y:
        print("ERROR: Elige una opcion dentro del menu.\n")
        op = comp_op(x, y)

    return op
