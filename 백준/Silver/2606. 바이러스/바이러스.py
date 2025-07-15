from sys import stdin

n = int(stdin.readline())
num = int(stdin.readline())

graph = [[] for _ in range(n+1)]
visited = [0]*(n+1)

for _ in range(num):
    a,b = map(int,stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)


def dfs(n):
    visited[n] = 1
    for i in graph[n]:
        if visited[i] == 0:
            dfs(i)

dfs(1)
print(sum(visited)-1)
    