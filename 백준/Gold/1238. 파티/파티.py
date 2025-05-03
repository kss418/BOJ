import sys
import heapq
input = sys.stdin.readline

INF = 10**12
n, m, x = map(int, input().split())
adj = [[] for _ in range(n+1)]

for _ in range(m):
    s, e, c = map(int, input().split())
    adj[s].append((e, c))

d = [[INF] * (n+1) for _ in range(n+1)]

for i in range(1, n+1):
    pq = []
    heapq.heappush(pq, (0, i))  
    while pq:
        cd, cur = heapq.heappop(pq)
        if d[i][cur] <= cd:
            continue
        d[i][cur] = cd
        for nxt, co in adj[cur]:
            nd = cd + co
            if d[i][nxt] > nd:
                heapq.heappush(pq, (nd, nxt))

result = 0
for i in range(1, n+1):
    result = max(result, d[i][x] + d[x][i])

print(result)


