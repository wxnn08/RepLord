def is_super_lucky(n):
    n4 = 0
    n7 = 0
    while n > 0:
        if n%10 == 4:
            n4 += 1
        if n%10 == 7:
            n7 += 1
        n //= 10
    return n4 != 0 and n7 != 0 and n4 == n7

def cria_lista(ns, n):
    if n > 1e10:
        return
    if is_super_lucky(n):
        ns.append(n)

    cria_lista(ns, n*10+7)
    cria_lista(ns, n*10+4)
    return

ns = []
cria_lista(ns, 0)
ns.sort()

n = int(input())
for i in ns:
    if i >= n:
        print(i)
        break
