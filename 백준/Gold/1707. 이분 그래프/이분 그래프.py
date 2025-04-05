import sys
sys.setrecursionlimit(10**6)
from collections import deque
input = sys.stdin.readline

result = 0

def add(s, e):
    # 양방향 간선 추가
    a[s].append(e)
    a[e].append(s)

def dfs(cur, num):
    global result
    v[cur] = num

    for nxt in a[cur]:
        if v[nxt] != -1:
            if(v[nxt] != num ^ 1):
                result = 0
            continue
        dfs(nxt, num ^ 1)
            
t = int(input().rstrip())
for _ in range(t):
    v = [-1] * 20101
    a = [[] for _ in range(20101)]
    result = 1

    n, m = list(map(int, input().rstrip().split()))
    for _ in range(m):
        s, e = list(map(int, input().rstrip().split()))
        add(s, e)
    
    for i in range(1, n + 1):
        if v[i] != -1:
            continue
        dfs(i, 0)
    
    print("YES" if result == 1 else "NO")