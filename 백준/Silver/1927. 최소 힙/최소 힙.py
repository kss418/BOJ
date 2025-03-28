import sys
import heapq
input = sys.stdin.readline

pq = []
n = int(input().rstrip())
for _ in range(n):
    x = int(input().rstrip())
    
    if x != 0:
        heapq.heappush(pq, x)
    else:
        if len(pq) == 0:
            print(0)
        else:
            print(heapq.heappop(pq))