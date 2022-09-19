#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long dp[101][10];
int mod = 1000000000;
long long result = 0;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] % mod;
		dp[i][9] = dp[i - 1][8] % mod;
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j + 1] % mod) % mod;
		}
	}

	for (int i = 0; i <= 9; i++) {
		result += dp[n][i] % 1000000000;
	}


	cout << result % 1000000000;

	return 0;
}
