import sys
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = list(map(int, input().rstrip().split()))
a.sort()
num = [0] * 201010

def decision(cur):
    last = 0
    for i in range(1, n + 1):
        if(i <= cur):
            last = max(a[i - 1] - m + 1, 1)
        else:
            last = max(a[i - 1] - m + 1, num[i - cur - 1] + m, 1)
        num[i - 1] = last

        if a[i - 1] - num[i - 1] < 0:
            return 0
    return 1


def minimization():
    lo = 1
    hi = 201010
    while lo < hi:
        mid = (lo + hi) // 2
        if(decision(mid)):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(minimization())
