n, s = input().split(" ")
n = int(n)
s = int(s)
l = []

for i in range(n):
    nome, valor = input().split(" ")
    valor = int(valor)
    l.append((valor, nome))

l.sort()
ans = []
for i in range(n-1, -1, -1):
    if (s >= l[i][0]):
        ans.append(l[i][1])
        s -= l[i][0]

if(s > 0):
    print(0)
else:
    print(len(ans))
    for nome in ans:
        print(nome)
