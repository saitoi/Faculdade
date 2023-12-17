# Tarefa 2 ii.2)

def aprox_segunda_derivada(f, x0, v, delta_x):
    numerador = f(v + delta_x) - 2 * f(x0) + f(v - delta_x)
    denominador = delta_x ** 2
    segunda_derivada = numerador / denominador
    return segunda_derivada


def ordem_erro(delta_x):
    return delta_x**2

def f(x):
    return x ** 2  # Exemplo de função quadrática

x0 = 1  # Ponto no qual a segunda derivada será aproximada
v = 2  # Ponto "v" no domínio
delta_x = 0.1  # Incremento

aproximacao = aprox_segunda_derivada(f, x0, v, delta_x)
error = ordem_erro(delta_x)

print("Derivada :", aproximacao)
print("Ordem do erro :", error)