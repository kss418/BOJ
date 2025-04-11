import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

inf = 1000000000
n = int(input().rstrip())
l = [0] * (n + 1)
r = [0] * (n + 1)
idx = [0] * (n + 1)
root = [1] * (n + 1)
mx = [0] * (n + 1)
mn = [inf] * (n + 1)
num = 0

for _ in range(n):
    arr = list(map(int, input().rstrip().split()))
    idx = arr[0]
    l[idx], r[idx] = arr[1], arr[2]
    
    if l[idx] != -1:
       root[l[idx]] = 0
    if r[idx] != -1:
        root[r[idx]] = 0

def dfs(cur, dep):
    global num
    if l[cur] != -1:
        dfs(l[cur], dep + 1)

    num += 1
    mn[dep] = min(mn[dep], num)
    mx[dep] = max(mx[dep], num)

    if r[cur] != -1:
        dfs(r[cur], dep + 1)

for i in range(1, n + 1):
    if root[i] == 0:
        continue
    dfs(i, 1)

result = 0
diff = 0

for i in range(1, n + 1):
    if mx[i] - mn[i] + 1 > diff:
        diff = mx[i] - mn[i] + 1
        result = i

print(f"{result} {diff}")