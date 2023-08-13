def soma_kahan(grupo):
    euler = 0
    e = 0
    fatorial = 1

    for i in range(len(grupo)):
        if i > 1:
            fatorial *= i
        temp = euler
        y = grupo[i]
        euler = temp + y
        e = (temp - euler) + y
    
    return euler