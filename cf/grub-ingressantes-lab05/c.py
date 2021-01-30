N = int(4e3 + 5)

(n, a, b, c) = map(int, input().split())

ans = 0
for qtdA in range(0, N):
    if qtdA*a > n:
        break
    for qtdB in range(0, N):
        resto = n - (qtdA*a + qtdB*b)
        if resto < 0:
            break
        if resto%c == 0:
            ans = max([ans, qtdA+qtdB+resto//c])

print(ans)
