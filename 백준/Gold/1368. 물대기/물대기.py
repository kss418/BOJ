import sys, heapq
input = sys.stdin.readline

MAX = 303
n = int(input())
result = 0
v = [0] * (n + 1)
adj = [[] for _ in range(n + 1)]
pq = []  

for i in range(1, n + 1):
    c = int(input())
    adj[0].append((i, c))

for i in range(1, n + 1):
    c = list(map(int, input().split()))
    for j in range(n):
        if c == 0:
            continue
        adj[i].append((j + 1, c[j]))

v[0] = 1
for e, c in adj[0]:
    heapq.heappush(pq, (c, 0, e))

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
