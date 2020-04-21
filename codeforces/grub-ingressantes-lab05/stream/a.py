def eh_valido(n):
    if n == 0:
        return False
    cont4 = 0
    cont7 = 0
    while n > 0:
        if n%10 == 4:
            cont4 += 1
        if n%10 == 7:
            cont7 += 1
        n //= 10
    return cont4 == cont7

def cria_lista(ns, num_atual, limite):
    if num_atual >= limite:
        return
    if eh_valido(num_atual):
        ns.append(num_atual)
    cria_lista(ns, num_atual*10 + 4, limite)
    cria_lista(ns, num_atual*10 + 7, limite)
    return

ns = []
cria_lista(ns, 0, 1e11)
ns.sort()

n = int(input())
for atual in ns:
    if atual >= n:
        print(atual)
        break
