# Letra b sem fatorial e com Soma de Kahn

import math

def calcular_e_kahn(n):
    e = 0.0
    c = 0.0
    factorial = 1

    for i in range(n):
        if i > 0:
            factorial *= i
        y = (1 / factorial) - c
        t = e + y
        c = (t - e) - y
        e = t

    return e

parametros = [5, 10, 50, 100, 500, 1000, 5000];

for i in parametros:
    print("Valor obtido para e (n =",i,") = ",calcular_e_kahn(i))
    print("Acuracia (n =",i,") = ",(abs(math.e-calcular_e_kahn(i)))/math.e)
    print("Diferença absoluta (n =",i,") :",abs(math.e-calcular_e_kahn(i)))
    print("--------------------------------------------------------")

print("Valor tabelado para e : ",math.e)