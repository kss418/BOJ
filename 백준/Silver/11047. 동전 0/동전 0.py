import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]

result = 0
for i in range(n - 1, -1, -1):
    div = m // a[i]
    result += div
    m -= div * a[i]

print(result)
