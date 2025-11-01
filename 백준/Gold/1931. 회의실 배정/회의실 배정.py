import sys
input = sys.stdin.readline

n = int(input())
a = []
for _ in range(n):
    s, e = map(int, input().split())
    a.append((e, s))

a.sort()

la = -1
result = 0
for e, s in a:
    if s < la:
        continue
    la = e
    result += 1

print(result)
