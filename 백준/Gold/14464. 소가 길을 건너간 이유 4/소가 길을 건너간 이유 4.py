import sys
import heapq
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = []
for _ in range(n):
    x = int(input().rstrip())
    a.append(x)

b = []
for _ in range(m):
    l, r = list(map(int, input().rstrip().split()))
    b.append((l, r))

a.sort()
b.sort()

idx = 0
result = 0
pq = []

for i in a:
    while idx < m and b[idx][0] <= i:
        heapq.heappush(pq, b[idx][1])
        idx += 1
    
    while len(pq) != 0 and pq[0] < i:
        heapq.heappop(pq)
    
    if len(pq) != 0:
        result += 1
        heapq.heappop(pq)
    
print(result)


