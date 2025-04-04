import sys
import heapq
input = sys.stdin.readline

pq1 = []
pq2 = []
n = int(input().rstrip())
for i in range(n):
    x = int(input().rstrip())
    if i % 2 == 0:
        heapq.heappush(pq1, -x)
    else:
        heapq.heappush(pq2, x)

    if len(pq2) != 0 and -pq1[0] > pq2[0]:
        t1 = -pq1[0]
        t2 = pq2[0]
        heapq.heappop(pq1)
        heapq.heappop(pq2)
        heapq.heappush(pq1, -t2)
        heapq.heappush(pq2, t1)
    
    print(-pq1[0])

