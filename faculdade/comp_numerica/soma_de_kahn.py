# Soma de Kahn Teste

import math

def kahan_sum(numbers):
    s = 0.0
    c = 0.0
    for number in numbers:
        y = number - c
        t = s + y
        c = (t - s) - y
        s = t
    return s

numbers = [1, 2, 3, 4, 5]

print(kahan_sum(numbers))