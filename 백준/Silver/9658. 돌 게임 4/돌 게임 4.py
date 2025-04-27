import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

dp = [[-1] * 2 for _ in range(1010)]
n = int(input().rstrip())

dp[0][0] = 0
dp[0][1] = 1

def solve(cur, turn):
    if dp[cur][turn] != -1:
        return dp[cur][turn]
    dp[cur][turn] = turn ^ 1

    for i in [-1, -3, -4]:
        nxt = cur + i
        if nxt < 0: 
            break

        if turn == 1:
            dp[cur][turn] = max(dp[cur][turn], solve(nxt, turn ^ 1))
        else:
            dp[cur][turn] = min(dp[cur][turn], solve(nxt, turn ^ 1))

    return dp[cur][turn]

print("CY" if solve(n, 0) == 1 else "SK")