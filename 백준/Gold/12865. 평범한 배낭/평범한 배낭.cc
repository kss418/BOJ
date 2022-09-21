#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][100001] = { 0, };
vector <pair <int, int>> arr;
int n, k, w, v;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		arr.push_back({ w,v });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (arr[i - 1].first <= j) {
				dp[i][j] = max(dp[i - 1][j - arr[i - 1].first] + arr[i - 1].second, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];


	return 0;
}
