#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][3][2];
int n;
int mod = 1000000;
int result = 0;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	dp[0][0][0] = 1;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i][0][0] = (dp[i - 1][0][0] % mod + dp[i - 1][1][0] % mod + dp[i - 1][2][0] % mod) % mod;
		dp[i][0][1] = (dp[i - 1][2][1] % mod + dp[i - 1][1][1] % mod + dp[i - 1][0][1] % mod + dp[i - 1][0][0] % mod + dp[i - 1][1][0] % mod + dp[i - 1][2][0] % mod) % mod;

		for (int j = 1; j <= 2; j++) {
			for (int k = 0; k <= 1; k++) {
				dp[i][j][k] = dp[i - 1][j - 1][k] % mod;
			}
		}
	}

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 1; j++) {
			result += dp[n][i][j] % mod;
		}
	}
	
	cout << result % mod;

	return 0;
}
