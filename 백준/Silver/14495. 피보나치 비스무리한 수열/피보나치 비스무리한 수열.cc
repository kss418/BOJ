#include <iostream>
using namespace std;
int n;
long long dp[117];

int main(){
	cin >> n;

	dp[1] = 1, dp[2] = 1, dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 3];
	}

	cout << dp[n];

	return 0;
}
