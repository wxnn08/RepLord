l = list()

while (1):
	try:
		val = input()
		l.clear()
		while (val!=-999999):
			l.append(val)
			val = input()

		for i in range (1, len(l)):
			print((l[i]));

	except EOFError:
		break
