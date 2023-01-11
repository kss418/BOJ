#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 510;
int arr[MAX];
int sum[MAX];
int dp[MAX][MAX];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		fill(&dp[0][0], &dp[n + 1][n + 1], 1e8);
		for (int i = 1; i <= n; i++) {
			dp[i][i] = 0;
		}
		
		for (int d = 1; d < n; d++) {
			for (int i = 1; i <= n; i++) {
				for (int j = i ; j <= n; j++) {
					if (i + d > n) {
						break;
					}

					dp[i][i + d] = min(dp[i][i + d], dp[i][j] + dp[j + 1][i + d] + sum[i + d] - sum[i - 1]);
				}
			}
		}

		cout << dp[1][n] << "\n";
	}
	

	

	return 0;
}