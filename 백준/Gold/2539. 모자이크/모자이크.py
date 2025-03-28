import sys
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
l = int(input().rstrip())
black = int(input().rstrip())

a = []
for _ in range(black):
    y, x = list(map(int, input().rstrip().split()))
    a.append((x, y))
a.sort()

def decision(cur):
    cnt = 0
    last = int(-1e12)
    for x, y in a:
        if y > cur:
            return 0
        if x - last + 1 <= cur:
            continue
        last = x
        cnt += 1
    return cnt <= l

def minimization():
    lo = 1
    hi = int(2e6)
    while(lo < hi):
        mid = (lo + hi) // 2
        if(decision(mid)):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(minimization())

