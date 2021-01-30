n = int(input())

# Verifico se o sinal é positivo ou negativo
sinal = -1 if n%2 == 1 else 1

# Somar um se n é impar e depois dividir por 2
num = (n + (n%2))//2

print(sinal*num)
