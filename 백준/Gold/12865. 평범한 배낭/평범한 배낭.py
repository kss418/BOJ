import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
w = [0] * (n + 1)
c = [0] * (n + 1)
for i in range(1, n + 1):
    w[i], c[i] = map(int, input().split())

dp = [[-1] * (m + 1) for _ in range(n + 1)]

def solve(cur, num):
    if dp[cur][num] != -1:
        return dp[cur][num]
    
    dp[cur][num] = 0
    if cur == 0:
        return dp[cur][num]

    dp[cur][num] = max(dp[cur][num], solve(cur - 1, num))
    if num >= w[cur]:
        dp[cur][num] = max(dp[cur][num], solve(cur - 1, num - w[cur]) + c[cur])
    
    if num >= 1:
        dp[cur][num] = max(dp[cur][num], dp[cur][num - 1])

    return dp[cur][num]

print(solve(n, m))