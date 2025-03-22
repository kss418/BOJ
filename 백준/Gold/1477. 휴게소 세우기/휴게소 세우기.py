import sys
input = sys.stdin.readline

n, m, l = list(map(int, input().rstrip().split()))
a = list(map(int, input().rstrip().split()))
a.append(0)
a.append(l)
a.sort()

def decision(cur):
    cnt = 0
    for i in range(1, n + 2):
        diff = a[i] - a[i - 1]
        cnt += diff // cur
        if diff % cur == 0:
            cnt -= 1
    return cnt <= m

def minimazation():
    lo = 1
    hi = l
    while(lo < hi):
        mid = (lo + hi) // 2
        if(decision(mid)):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(minimazation())