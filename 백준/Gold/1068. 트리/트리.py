import sys
input = sys.stdin.readline

n = int(input().rstrip())
p = list(map(int, input().rstrip().split()))
a = [[] for _ in range(55)]
root = 0
result = 0

def dfs(cur):
    global result
    if cur == m:
        return
    for nxt in a[cur]:
        dfs(nxt)
    
    if len(a[cur]) == 0 or (len(a[cur]) == 1 and a[cur][0] == m):
        result += 1

for i in range(len(p)):
    if p[i] == -1:
        root = i 
    else:
        a[p[i]].append(i)
m = int(input().rstrip())

dfs(root)
print(result)
