import sys
from collections import deque
input = sys.stdin.readline
v = [0] * 1010
a = [[] for _ in range(1010)]

def add(s, e):
    # 양방향 간선 추가
    a[s].append(e)
    a[e].append(s)

def bfs(st):
    q = deque()
    # 큐에 시작점 추가 및 방문 처리
    q.append(st)
    v[st] = 1

    while len(q) != 0:
        cur = q.popleft()
        print(cur, end = ' ')
        for nxt in a[cur]:
            # 방문한 정점이면 넘어 감
            if v[nxt] == 1:
                continue
            # 큐에 다음 정점 삽입 및 방문 처리
            v[nxt] = 1
            q.append(nxt)

def dfs(cur):
    # 방문한 정점으로 표시
    v[cur] = 1
    print(cur, end = ' ')

    for nxt in a[cur]:
        # 다음 정점이 방문한 정점이면 넘어 감
        if v[nxt] == 1:
            continue
        dfs(nxt)

n, m, k = list(map(int, input().rstrip().split()))
for _ in range(m):
    s, e = list(map(int, input().rstrip().split()))
    add(s, e)

for i in range(1, n + 1):
    a[i].sort()

dfs(k)
print()
for i in range(1, n + 1):
    v[i] = 0
bfs(k)
