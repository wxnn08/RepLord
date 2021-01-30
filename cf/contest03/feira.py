d = int(input())
(pa, va) = map(int, input().split())
(pb, vb) = map(int , input().split())
(pc, vc) = map(int , input().split())

ans = 0

for i in range(0, 1000):
    for j in range(0, 1000):
        if i*pa + j*pb <= d:
            qtc = (d-i*pa-j*pb)//pc
            ans = max(ans, i*va + j*vb + qtc*vc)

print(ans)
