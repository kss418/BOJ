import sys
import heapq

MAX = 10101
INF = 10**12

def init():
    global pq, adj
    pq.clear()
    for i in range(1, n + 1):
        adj[i].clear()

def run():
    global n, m, k, d, adj, pq
    n, m, k = map(int, sys.stdin.readline().split())
    init()
    for _ in range(m):
        s, e, c = map(int, sys.stdin.readline().split())
        adj[e].append((s, c))
    
    for i in range(MAX):
        d[i] = INF
    heapq.heappush(pq, (0, k))

    while pq:
        cd, cur = heapq.heappop(pq)
        if d[cur] <= cd:
            continue
        d[cur] = cd

        for nxt, co in adj[cur]:
            if d[nxt] <= cd + co:
                continue
            heapq.heappush(pq, (cd + co, nxt))
    
    cnt = 0
    result = 0
    for i in range(1, n + 1):
        if d[i] == INF:
            continue
        cnt += 1
        result = max(result, d[i])
    print(cnt, result)

t = int(sys.stdin.readline())
d = [INF] * MAX
adj = [[] for _ in range(MAX)]
pq = []
for _ in range(t):
    run()