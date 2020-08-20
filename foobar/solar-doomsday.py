import math

def solution(area):
    ans = []
    while area > 0:
        val = int(math.sqrt(area))
        ans.append(val*val)
        area -= (val*val)
    return ans

area = int(input())
print(solution(area))
