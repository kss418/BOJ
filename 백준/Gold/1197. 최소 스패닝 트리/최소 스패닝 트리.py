import sys, heapq
input = sys.stdin.readline

MAX = 10101
n, m = map(int, input().split())
result = 0
v = [0] * (n + 1)
adj = [[] for _ in range(n + 1)]
pq = []  

for i in range(m):
    s, e, c = map(int, input().split())
    adj[s].append((e, c))
    adj[e].append((s, c))

# 시작 정점과 연결된 간선을 pq에 삽입
for e, c in adj[1]:
    heapq.heappush(pq, (c, 1, e))
v[1] = 1  # 시작 정점 방문 처리

while pq:
    c, s, e = heapq.heappop(pq)
    # 다음 정점을 방문 했으면 -> 같은 집합이면
    # 건너 뜀
    if v[e] == 1:
        continue

    # 정답에 비용 추가 및 방문 처리
    result += c
    v[e] = 1

    for nxt, co in adj[e]:
        # 이미 방문한 정점이면 건너 뜀
        if v[nxt]:
            continue

        # pq에 간선 삽입
        heapq.heappush(pq, (co, e, nxt))

print(result)
