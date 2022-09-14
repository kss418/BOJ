#include <iostream>
using namespace std;
int dp[100001];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	fill(dp, dp + n + 1, 100001);
	
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];

	return 0;
}
