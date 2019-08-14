from functools import cmp_to_key

def cmp(a, b):
	x, y = a
	w, z = b
	
	return -1 if x*y != y*w and x * y > w * z else -1 if x > y else 0

vant1 = 0
vant2 = 0
ans = 0

n = int(input())

v = []
dans = []

amin = -1

for i in range(n):
	a, t = [int(x) for x in input().split(" ")]
	v.append((a, t))
	dans.append((a, t))

v = sorted(v, key=cmp_to_key(cmp))

for i in range(n - 1):
	x, y = v[i]
	vant1 += x * y
	x, y = dans[i]
	vant2 += x * y
	
	_, x = v[i + 1]
	_, y = dans[i + 1]
	ans += vant1 * x - vant2 * y

ans *= 1.0
print(ans)
