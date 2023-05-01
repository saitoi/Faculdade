# Refazendo Letra b)

import math

def calcular_e(n):
    e = 0
    termo = 1
    denominador = 1

    for i in range(1, n+1):
        termo *= i
        e += denominador/termo
        denominador = 1/termo

    return e

print(calcular_e(5000))
print("Desvio percentual: ", (abs(math.e-calcular_e(5000)))/math.e)
print("Desvio absoluto: ", abs(math.e-calcular_e(5000)))
