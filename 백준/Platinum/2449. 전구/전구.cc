#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 210;
int arr[MAX];
int dp[MAX][MAX];

bool deter(int st, int mid , int en) {
	if (arr[st] == arr[mid + 1] || arr[st] == arr[en]) {
		return 1;
	}

	if (arr[mid] == arr[mid + 1] || arr[mid] == arr[en]) {
		return 1;
	}
	return 0;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	fill(&dp[0][0], &dp[n + 1][n + 1], 1e9);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][i] = 0;
	}

	for (int d = 1; d < n; d++) {
		for (int i = 1; i <= n; i++) {
			if (i + d > n) {
				break;
			}

			for (int j = i; j <= n; j++) {
				if (deter(i, j, i + d)) {
					dp[i][i + d] = min(dp[i][i + d], dp[i][j] + dp[j + 1][i + d]);
				}
				else {
					dp[i][i + d] = min(dp[i][i + d], dp[i][j] + dp[j + 1][i + d] + 1);
				}
			}
		}
	}

	cout << dp[1][n];

	

	return 0;
}