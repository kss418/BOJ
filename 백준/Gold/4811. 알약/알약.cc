#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[31][31];
long long result[31];
int n, num;


int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	fill(&dp[0][0], &dp[30][31], 0);
	dp[0][0] = 1;

	for (int i = 1; i <= 30; i++) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	while (true) {
		cin >> num;
		if (num == 0) {
			break;
		}

		cout << dp[num][num] << "\n";
	}
	

	return 0;
}
