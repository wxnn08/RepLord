def to_tuple(n):
    a = n%2
    n //= 2
    b = n%2
    n //= 2
    c = n%2
    return (a,b,c)

def soma_tupla(tp, v):
    (a, b, c) = tp
    (na, nb, nc) = to_tuple(v);
    return (a+na, b+nb, c+nc)

def cria_lista(ns, qt, curr, points):
    if curr > 7:
        if ns.__contains__(qt):
            ns[qt] = max([ns[qt], points])
        else:
            ns[qt] = points
        return
    
    cria_lista(ns, soma_tupla(qt, curr), curr+1, points+1)
    cria_lista(ns, qt, curr+1, points)

ns = dict()
cria_lista(ns, (0,0,0), 1, 0)

tc = int(input())
while tc > 0:
    a, b, c = map(int, input().split())
    ans = 0
    for (na, nb, nc) in ns:
        if na <= a and nb <= b and nc <= c and ans < ns[(na,nb,nc)]:
            ans = ns[(na,nb,nc)]

    print(ans)
    tc -= 1
