# Soma de Kahn - Letra a

from math import factorial

def kahan_sum(input):
    sum = 0.0
    c = 0.0
    for i in input:
        y = i - c
        t = sum + y
        c = (t - sum) - y
        sum = t
    return sum

def newton_euler_pi(n):
    series = [(((-1) ** i) * factorial(6 * i) * (13591409 + 545140134 * i)) / ((factorial(3 * i) ** 3) * (factorial(i) ** 6) * (-640320 ** (3 * i))) for i in range(n)]
    return (426880 * (10005 ** 0.5)) / kahan_sum(series)

approximation = newton_euler_pi(3)
print(approximation*-1)


