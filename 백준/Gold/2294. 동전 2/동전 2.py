import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

INF = 10**12
def solve(cur):
    if cur < 0:
        return INF
    
    if dp[cur] != -1:
        return dp[cur]
    if cur == 0:
        dp[cur] = 0
        return 0

    dp[cur] = INF
    for i in range(1, n+1):
        dp[cur] = min(dp[cur], solve(cur - a[i]) + 1)

    return dp[cur]

n, m = map(int, input().split())
a = [0] * (n+1)
for i in range(1, n+1):
    a[i] = int(input())

dp = [-1] * (m+1)

ans = solve(m)
print(-1 if ans == INF else ans)