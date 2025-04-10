import sys
from collections import deque
input = sys.stdin.readline

inf = 1000000000
n, m = list(map(int, input().rstrip().split()))

a = []
a.append((0, 0))
for _ in range(n):
    x, y = list(map(int, input().rstrip().split()))
    a.append((x, y))
a.append((10000, 10000))

def dist(a, b):
    dx = a[0] - b[0]
    dy = a[1] - b[1]
    return dx * dx + dy * dy

def decision(num):
    num *= 10
    q = deque()
    d = [inf] * (n + 2)
    d[0] = 0
    q.append(0)

    while len(q):
        cur = q.popleft()
        for nxt in range(1, n + 2):
            if dist(a[nxt], a[cur]) > num * num:
                continue
            
            if d[nxt] != inf:
                continue

            q.append(nxt)
            d[nxt] = d[cur] + 1
        
    return d[n + 1] - 1 <= m


def minimization():
    lo = 0
    hi = 10000
    while lo < hi:
        mid = (lo + hi) // 2
        if decision(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(minimization())