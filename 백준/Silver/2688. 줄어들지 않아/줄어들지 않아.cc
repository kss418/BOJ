#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, num;
long long dp[65][10];
long long result[65];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	fill(&dp[0][0], &dp[64][10], 0);
	fill(result, result + 65, 0);

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	
	for (int i = 1; i <= 64; i++) {
		for (int j = 0; j <= 9; j++) {
			result[i] += dp[i][j];
		}
	}

	while (n--) {
		cin >> num;
		cout << result[num] << "\n";
	}

	return 0;
}
