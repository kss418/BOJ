import sys
input = sys.stdin.readline

n = int(input().rstrip())
a = []
a.append(0)
for _ in range(n):
    num = int(input().rstrip())
    a.append(num)

dp = [[0, 0] for _ in range(303)]

for i in range(1, n + 1):
    if(i >= 2):
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + a[i]
    else:
        dp[i][0] = a[i]

    dp[i][1] = dp[i - 1][0] + a[i]

print(max(dp[n][0], dp[n][1]))