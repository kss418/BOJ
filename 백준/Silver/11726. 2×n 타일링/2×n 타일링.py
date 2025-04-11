import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

dp = [-1] * 1010
mod = 10007
dp[0] = 1

def solve(cur):
    if(cur < 0):
        return 0
    if dp[cur] != -1:
        return dp[cur]
    dp[cur] = 0

    dp[cur] = (solve(cur - 1) + solve(cur - 2)) % mod
    return dp[cur]

n = int(input().rstrip())
print(solve(n))