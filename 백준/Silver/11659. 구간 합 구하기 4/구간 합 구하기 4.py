import sys
import heapq
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = list(map(int, input().rstrip().split()))
sum = []
for i in a:
    if len(sum) == 0:
        sum.append(i)
    else:
        sum.append(sum[-1] + i)

def cal(l, r):
    if l == 0:
        return sum[r]
    return sum[r] - sum[l - 1]

for _ in range(m):
    l, r = list(map(int, input().rstrip().split()))
    print(cal(l - 1, r - 1))