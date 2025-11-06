import sys, heapq
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    pq = []
    for i in range(n):
        heapq.heappush(pq, a[i])
    
    result = 0
    while len(pq) > 1:
        fi = heapq.heappop(pq)
        se = heapq.heappop(pq)

        result += fi + se
        heapq.heappush(pq, fi + se)
    
    print(result)

t = int(input())
for _ in range(t):
    solve()




