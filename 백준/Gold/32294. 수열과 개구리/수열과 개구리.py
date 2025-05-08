import sys
import heapq

MAX = 201010
INF = 10**12

input = sys.stdin.readline
n = int(input())
a = [0] + list(map(int, input().split()))
b = [0] + list(map(int, input().split()))

adj = [[] for _ in range(MAX)]
d = [INF] * MAX
pq = []

for i in range(1, n + 1):
    nx = i - a[i]
    if nx <= 0:
        adj[0].append((i, b[i]))
    else:
        adj[nx].append((i, b[i]))

    nx = i + a[i]
    if nx > n:
        adj[0].append((i, b[i]))
    else:
        adj[nx].append((i, b[i]))

heapq.heappush(pq, (0, 0))

while pq:
    cd, cur = heapq.heappop(pq)
    if d[cur] <= cd:
        continue
    d[cur] = cd

    for nxt, co in adj[cur]:
        if d[nxt] <= cd + co:
            continue
        heapq.heappush(pq, (cd + co, nxt))

print(' '.join(str(d[i]) for i in range(1, n + 1)))
