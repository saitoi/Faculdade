# Refazer Letra b

import math
from decimal import Decimal

def calcular_pi(n):
    pi = Decimal(0)
    fatorial_i = Decimal(1)
    fatorial_2i1 = Decimal(1)
    for i in range(n):
        if i > 0:
            fatorial_i *= i
            fatorial_2i1 *= (2 * i) * (2 * i + 1)
        pi += (Decimal(2) ** i) * ((fatorial_i ** 2) / fatorial_2i1)
    return pi * 2

parametros = [5, 10, 50, 100, 500, 1000, 5000];

for i in parametros:
    print("Valor obtido para pi (n =",i,") = ",calcular_pi(i))
    print("Acuracia (n =",i,") = ",(abs(Decimal(math.pi)-calcular_pi(i)))/Decimal(math.pi))
    print("Diferença absoluta (n =",i,") :",abs(Decimal(math.pi)-calcular_pi(i)))
    print("--------------------------------------------------------")

print("Valor tabelado para pi : ",math.pi)
