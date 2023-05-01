# Refazendo Letra b sem Fatorial

import math

def calcular_e(n):
    e = 0
    factorial = 1

    for i in range(n):
        if i > 0:
            factorial *= i
        e += 1 / factorial

    return e

parametros = [5, 10, 50, 100, 500, 1000, 5000];

for i in parametros:
    print("Valor obtido para e (n =",i,") = ",calcular_e(i))
    print("Acuracia (n =",i,") = ",(abs(math.e-calcular_e(i)))/math.e)
    print("Diferença absoluta (n =",i,") :",abs(math.e-calcular_e(i)))
    print("--------------------------------------------------------")

print("Valor tabelado para e : ",math.e)
