import sys
import heapq
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = list(map(int, input().rstrip().split()))

def decision(cur):
    pq = [0] * cur

    mx = 0
    for i in a:
        now = heapq.heappop(pq) + i
        heapq.heappush(pq, now)
        mx = max(mx, now)
    
    return mx <= m

def maximization():
    lo = 1
    hi = int(2e5)
    while lo < hi:
        mid = (lo + hi) // 2
        if(decision(mid)):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(maximization())
