import sys
from collections import deque
input = sys.stdin.readline

inf = 1000000000
d = [[inf] * 1010 for i in range(1010)]
a = []
q = deque()

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def outrange(cy, cx):
    if cy < 0 or cx < 0 or cy >= n or cx >= m:
        return 1
    return a[cy][cx] == -1

def bfs():
    while len(q) != 0:
        cy, cx= q.popleft()
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if(outrange(ny, nx)):
                continue
            if(d[ny][nx] != inf):
                continue
            d[ny][nx] = d[cy][cx] + 1
            q.append((ny, nx))

m, n = list(map(int, input().rstrip().split()))
for i in range(n):
    b = list(map(int, input().rstrip().split()))
    a.append(b)

    for j in range(len(b)):
        if a[i][j] != 1:
            continue
        d[i][j] = 0
        q.append((i, j))

bfs()

result = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == -1:
            continue
        result = max(result, d[i][j])

print(-1 if result == inf else result)

