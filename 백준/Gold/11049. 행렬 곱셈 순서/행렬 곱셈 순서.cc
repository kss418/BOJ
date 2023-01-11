#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 510;
int arr[MAX][2];
int dp[MAX][MAX];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	fill(&dp[0][0], &dp[n + 1][n + 1], 1e9);

	for (int i = 1; i < n; i++) {
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}

	for (int d = 1; d <= n; d++) {
		for (int i = 1; i <= n; i++) {
			if (i + d > n) {
				break;
			}

			for (int j = i; j <= i + d; j++) {
				dp[i][i + d] = min(dp[i][j] + dp[j + 1][i + d] + arr[i][0] * arr[j][1] * arr[i + d][1], dp[i][i + d]);
			}
		}
	}
	
	cout << dp[1][n];

	return 0;
}