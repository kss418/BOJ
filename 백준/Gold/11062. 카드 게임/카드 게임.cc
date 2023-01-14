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

const int MAX = 1010;
int arr[MAX];
int dp[MAX][MAX][2];

void dfs(int st, int en, int t) {
	if (st > en) {
		dp[st][en][0] = 0;
		dp[st][en][1] = 0;
		return;
	}

	if (dp[st][en][t] != -1) {
		return;
	}

	dfs(st + 1, en, t ^ 1);
	dfs(st, en - 1, t ^ 1);
	dp[st][en][0] = max(dp[st + 1][en][1] + arr[st], dp[st][en - 1][1] + arr[en]);
	dp[st][en][1] = min(dp[st + 1][en][0], dp[st][en - 1][0]);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		dfs(1, n, 0);
		cout << dp[1][n][0] << "\n";
	}


	return 0;
}