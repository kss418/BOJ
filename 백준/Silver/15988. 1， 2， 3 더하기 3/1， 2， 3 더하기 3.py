import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

mod = 10 ** 9 + 9
dp = [-1] * 1010101
dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(3, 1010101):
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    print(dp[n])