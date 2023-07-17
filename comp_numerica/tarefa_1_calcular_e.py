# Letra b)

import math

def calcular_e(n):
  e = 0

  for i in range(n):
    e += 1/math.factorial(i)
  
  return e

parametros = [5, 10, 50, 100, 500, 1000, 5000];

for i in parametros:
    print("Valor obtido para e (n =",i,") = ",calcular_e(i))
    print("Acuracia (n =",i,") = ",(abs(math.e-calcular_e(i)))/math.e)
    print("Diferença absoluta (n =",i,") :",abs(math.e-calcular_e(i)))
    print("--------------------------------------------------------")