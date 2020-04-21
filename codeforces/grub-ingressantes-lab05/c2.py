N = int(4e3 + 5)

(n, a, b, c) = map(int, input().split())

ans = 0
for qtdA in range(0, N):
    for qtdB in range(0, N):
        for qtdC in range(0, N):
            if qtdA*a+qtdB*b+qtdC*c == n:
                ans = max([ans, qtdA+qtdB+qtdC])

print(ans)
