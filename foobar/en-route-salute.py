def solution(s):
    cont = 0
    ans = 0
    for c in s:
        if c == '>':
            cont += 1
        if c == '<':
           ans += cont
    return ans*2

s = input()
print(solution(s))
