#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long result = 0;
int mod = 1e9;
long long dp[101][10][1 << 10];

long long dfs(int cur, int num, int visit) {
	long long ret = dp[cur][num][visit];
	if (num > 9 || num < 0) {
		return 0;
	}

	if (ret != -1) {
		return ret % mod;
	}

	if (cur == 1 || !(visit & (1 << num))) {
		dp[cur][num][visit] = 0;
		return 0;
	}


	ret = 0;

	ret += dfs(cur - 1, num + 1, visit | (1 << num)) % mod;
	ret += dfs(cur - 1, num + 1, visit & ~(1 << num)) % mod;
	ret += dfs(cur - 1, num - 1, visit | (1 << num)) % mod;
	ret += dfs(cur - 1, num - 1, visit & ~(1 << num)) % mod;

	return dp[cur][num][visit] = ret % mod;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	fill(&dp[0][0][0], &dp[100][9][1 << 10], -1);


	dp[1][0][1 << 0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}

	for (int i = 0; i <= 9; i++) {
		dfs(n, i, (1 << 10) - 1);
	}

	for (int i = 0; i <= 9; i++) {
		result += dp[n][i][(1 << 10) - 1] % mod;
	}

	cout << result % mod;


	return 0;
}
