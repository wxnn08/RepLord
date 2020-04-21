n = int(input())

i1 = 0
i2 = 0
for i in range(0, n):
    (a, b) = map(int, input().split())
    i1 += int(a%2)
    i2 += int(b%2)
if n == 1 and (i1%2 or i2%2):
    print(-1)
elif (i1+i2)%2 == 1:
    print(-1)
elif i1%2 or i2%2:
    print(1)
else:
    print(0)
