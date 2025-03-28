import sys
input = sys.stdin.readline

n = int(input().rstrip())
m = int(input().rstrip())

def decision(cur):
    cnt = 0
    for i in range(1, n + 1):
        cnt += min(cur // i, n)
    return cnt >= m

def minimization():
    lo = 1
    hi = int(2e10)
    while lo < hi:
        mid = (lo + hi) // 2
        if decision(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(minimization())