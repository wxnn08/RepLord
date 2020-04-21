n = int(input())

signal = -1 if n%2 == 1 else 1
num = (n + int(n%2))//2

print(signal*num)
