# Tarefa 2 i.1)

def aproximacao_derivada(f, x0, delta_x):
    numerador = -f(x0 + 2*delta_x) + 4*f(x0 + delta_x) - 3*f(x0)
    denominador = 2*delta_x
    primeira_derivada = numerador/denominador
    return primeira_derivada

def ordem_erro(delta_x):
    return delta_x**2

# Exemplo de função
def f(x):
    return x**2

x0 = float(input("Escolha um ponto x0: "))
delta_x = float(input("Escolha um Δx: "))



Derivada = aproximacao_derivada(f, x0, delta_x)
error = ordem_erro(delta_x)

print("Derivada :", Derivada)
print("Ordem do erro :", error)