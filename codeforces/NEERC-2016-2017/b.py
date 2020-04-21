inp = open('input.txt', 'r')
out = open('output.txt', 'w')

for N in inp:
	n = int(N)
	x = n // 3
	ans = 2
	for i in range(1, x):
		ans *= 4
		ans += i
	out.write(str(ans) + '\n')
