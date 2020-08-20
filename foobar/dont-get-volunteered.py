from Queue import PriorityQueue
moves = [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]

def convertPosition(pos):
    return (pos//8, pos%8)

def convertCoordinate(coord):
    (l, c) = coord
    return l*8 + c

def availableCoord(coord):
    (l, c) = coord
    return l >= 0 and l <= 7 and c >= 0 and c <= 7

def solution(src, dest):
    pq = PriorityQueue()
    pq.put((0, convertPosition(src)))
    visit = set()
    goal = convertPosition(dest)
    while pq.qsize() > 0:
        (dist, (l, c)) = pq.get()
        if (l, c) in visit:
            continue
        visit.add((l, c))
        if((l, c) == goal):
            return dist
        for (ml, mc) in moves:
            if availableCoord((l+ml, c+mc)):
                pq.put((dist+1, (l+ml, c+mc)))

a = int(input())
b = int(input())
print(solution(a, b))
