#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 111;
int arr[MAX], cost[MAX];
int dp[MAX][MAX * MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10001; j++) {
			if (j >= cost[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + arr[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= 10001; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			return 0;
		}
	}

	return 0;
}