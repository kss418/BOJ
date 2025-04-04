import sys
import heapq
input = sys.stdin.readline

n = int(input().rstrip())
a = []
pq = []

for _ in range(n):
    r, l = list(map(int, input().rstrip().split()))
    if r < l:
        r, l = l, r
    a.append((r, l))

d = int(input().rstrip())
a.sort()
result = 0

for r, l in a:
    heapq.heappush(pq, l)
    while len(pq) != 0 and pq[0] < r - d:
        heapq.heappop(pq)
    result = max(result, len(pq))

print(result)