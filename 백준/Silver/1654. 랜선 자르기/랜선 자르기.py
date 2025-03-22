import sys
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = [int(input().rstrip()) for _ in range(n)]

def decision(cur):
    cnt = 0
    for i in a:
        cnt += i // cur
    return cnt >= m

def maximazation():
    lo = 1
    hi = 2 ** 31 - 1
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if(decision(mid)):
            lo = mid
        else:
            hi = mid - 1
    return lo

print(maximazation())
