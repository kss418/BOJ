#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
long long dp[201][201];


int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	fill(&dp[0][0], &dp[200][201], 0);
	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			for (int l = 0; l <= i; l++) {
				dp[i][j] += dp[i - l][j - 1] % (int)1e9;
			}
		}
	}

	cout << dp[n][k] % (int)1e9;


	return 0;
}
