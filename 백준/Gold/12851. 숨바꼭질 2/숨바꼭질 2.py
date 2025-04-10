import sys
from collections import deque
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
d = [-1] * 101010
cnt = [0] * 101010

for i in range(101010):
    d[i] = -1

q = deque()
def bfs(st):
    q.append(st)
    d[st] = 0
    cnt[st] = 1

    while len(q) != 0:
        cur = q.popleft()
        for nxt in (cur + 1, cur - 1, 2 * cur):
            if nxt < 0 or nxt >= 101010:
                continue

            if d[nxt] == -1:
                q.append(nxt)
                d[nxt] = d[cur] + 1
            
            if d[nxt] == d[cur] + 1:
                cnt[nxt] += cnt[cur]

bfs(n)
print(d[m])
print(cnt[m])