#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int dp[1001][201];
int expr[201];
int level[201];
int dist[201][201];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> level[i] >> expr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i >= dist[j][k] && dp[i - dist[j][k]][j] >= level[k]) {
					dp[i][k] = max(dp[i][k], dp[i - dist[j][k]][j]);
					dp[i + 1][k] = max(dp[i + 1][k], dp[i][k] + expr[k]);
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[t][i]);
	}

	cout << result;

	return 0;
}
