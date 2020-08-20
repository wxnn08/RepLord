memo = dict()
def possibilities(maxH, n):
    if n == 0:
        return 1
    if maxH == 0:
        return 0

    if (maxH, n) in memo:
        return memo[(maxH, n)]

    ans = 0
    for i in range(1, maxH+1):
        if n-i >= 0:
            ans += possibilities(i-1, n-i)

    memo[(maxH, n)] = ans
    return ans

def solution(n):
    return possibilities(n, n)-1

n = int(input())
print(solution(n))
