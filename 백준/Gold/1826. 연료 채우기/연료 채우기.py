import sys
import heapq
input = sys.stdin.readline

n = int(input().rstrip())
a = []
for _ in range(n):
    x, y = list(map(int, input().rstrip().split()))
    a.append((x, y))
en, fuel = list(map(int, input().rstrip().split()))
pq = []

a.append((en, 0))
a.sort()
result = 0

for x, y in a:
    while x > fuel:
        if len(pq) == 0:
            print(-1)
            exit()
        result += 1
        fuel += -heapq.heappop(pq)

    heapq.heappush(pq, -y)

print(result)
