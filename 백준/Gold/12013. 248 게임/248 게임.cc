#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 250;
int arr[MAX];
int dp[MAX][MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	fill(&dp[0][0], &dp[n + 1][n + 1], -1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][i] = arr[i];
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = arr[i] + 1;
		}
	}

	for (int d = 1; d < n; d++) {
		for (int i = 1; i <= n; i++) {
			if (i + d > n) {
				break;
			}

			for (int j = i; j <= n; j++) {
				if (dp[i][j] == dp[j + 1][i + d] && dp[i][j] != -1) {
					dp[i][i + d] = max(dp[i][i + d], dp[i][j] + 1);
				}
				else {
					dp[i][i + d] = max(dp[i][i + d], -1);
				}
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			result = max(result, dp[i][j]);
		}
	}

	cout << result;

	return 0;
}