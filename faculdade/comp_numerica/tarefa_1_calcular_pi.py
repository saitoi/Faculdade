# Letra a)

import math

def calcular_pi(n):
  pi = 0

  for i in range(n):
    pi += 2**i * (math.factorial(i)*math.factorial(i))/math.factorial(2*i+1)

  return pi*2

parametros = [5, 10, 50, 100, 500, 1000, 5000];

for i in parametros:
    print("Valor obtido para pi (n =",i,") = ",calcular_pi(i))
    print("Acuracia (n =",i,") = ",(abs(math.pi-calcular_pi(i)))/math.pi)
    print("Diferença absoluta (n =",i,") :",abs(math.pi-calcular_pi(i)))
    print("--------------------------------------------------------")