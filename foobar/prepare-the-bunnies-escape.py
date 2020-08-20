from Queue import PriorityQueue

moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def availablePos((l, c), m):
    L = len(m)
    C = len(m[0])
    return l >= 0 and c >= 0 and l < L and c < C and m[l][c] == 0

def dij(m):
    L = len(m)
    C = len(m[0])
    pq = PriorityQueue()
    pq.put((1, (0, 0)))

    visit = set()
    while pq.qsize() > 0:
        (dist, (l, c)) = pq.get()
        if (l, c) == (L-1, C-1):
            return dist
        if (l, c) in visit:
            continue
        visit.add((l, c))
        for (ml, mc) in moves:
            nextPos = (l+ml, c+mc)
            if availablePos(nextPos, m):
                pq.put((dist+1, nextPos))
    return 500


def solution(m):
    ans = dij(m)
    for l in range(len(m)):
        for c in range(len(m[0])):
            if m[l][c] == 1:
                m[l][c] = 0
                ans = min(ans, dij(m))
                m[l][c] = 1
    return ans

print(solution([[0, 1, 0, 0, 0], [0, 0, 0, 1, 0], [1, 1, 1, 0, 0], [1, 1, 1, 0, 0]]))
