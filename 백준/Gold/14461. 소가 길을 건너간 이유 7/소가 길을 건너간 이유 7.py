import sys
import heapq

INF = 10**12
MAX = 3 * 10201

input = sys.stdin.readline

n, m = map(int, input().split())
a = [[0] * (n + 2) for _ in range(n + 2)]
for i in range(1, n + 1):
    row = list(map(int, input().split()))
    for j in range(1, n + 1):
        a[i][j] = row[j - 1]

adj = [[] for _ in range(MAX)]
d = [INF] * MAX
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def outrange(cy, cx):
    return cy <= 0 or cx <= 0 or cy > n or cx > n

def num(cy, cx, cnt):
    return cnt * 10101 + cy * 101 + cx

for i in range(1, n + 1):
    for j in range(1, n + 1):
        for k in range(4):
            ny = i + dy[k]
            nx = j + dx[k]
            if outrange(ny, nx):
                continue
            adj[num(i, j, 0)].append((num(ny, nx, 1), m))
            adj[num(i, j, 1)].append((num(ny, nx, 2), m))
            adj[num(i, j, 2)].append((num(ny, nx, 0), m + a[ny][nx]))

pq = []
heapq.heappush(pq, (0, num(1, 1, 0)))

while pq:
    cd, cur = heapq.heappop(pq)
    if d[cur] <= cd:
        continue
    d[cur] = cd
    for nxt, co in adj[cur]:
        if d[nxt] <= cd + co:
            continue
        heapq.heappush(pq, (cd + co, nxt))

result = INF
for i in range(3):
    result = min(result, d[num(n, n, i)])
print(result)
