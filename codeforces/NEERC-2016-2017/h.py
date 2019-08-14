inp = open('input.txt', 'r')
out = open('output.txt', 'w')

for N in inp:
	n = int(N)
	x = min(8, n - 1)
	ans = 8 * (9 ** x) * (10 ** (n - x - 1))
	out.write(str(ans) + '\n')
