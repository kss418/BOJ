import sys
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = []
for _ in range(n):
    x = int(input().rstrip())
    a.append(x)
a.sort() 

def decision(cur):
    cnt = 0
    last = -1e12

    for i in a:
        if i - last < cur:
            continue
        last = i
        cnt += 1

    return cnt >= m

def maximization():
    lo = 1
    hi = int(2e9)
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if decision(mid):
            lo = mid
        else:
            hi = mid - 1
    return lo

print(maximization())