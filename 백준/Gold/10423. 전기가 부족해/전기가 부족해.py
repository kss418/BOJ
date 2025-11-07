import sys, heapq
input = sys.stdin.readline

MAX = 10101
n, m, k = map(int, input().split())
result = 0
v = [0] * (n + 1)
adj = [[] for _ in range(n + 1)]
pq = []  

a = list(map(int, input().split()))
for i in range(m):
    s, e, c = map(int, input().split())
    adj[s].append((e, c))
    adj[e].append((s, c))

for i in a:
    v[i] = 1
    for e, c in adj[i]:
        heapq.heappush(pq, (c, i, e))

while pq:
    c, s, e = heapq.heappop(pq)
    if v[e] == 1:
        continue
    result += c
    v[e] = 1

    for nxt, co in adj[e]:
        if v[nxt]:
            continue
        heapq.heappush(pq, (co, e, nxt))

print(result)
