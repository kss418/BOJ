#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int x, y;
int arr[502][502];
int dp[502][502];

int dfs(int a, int b) {
	int cur = dp[a][b];
	int ret = 0;

	if (cur != -1) {
		return cur;
	}

	if (arr[a + 1][b] > arr[a][b]) {
		ret += dfs(a + 1,b);
	}

	if (arr[a - 1][b] > arr[a][b]) {
		ret += dfs(a - 1, b);
	}

	if (arr[a][b - 1] > arr[a][b]) {
		ret += dfs(a, b - 1);
	}

	if (arr[a][b + 1] > arr[a][b]) {
		ret += dfs(a, b + 1);
	}

	return dp[a][b] = ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> y >> x;
	fill(&dp[0][0], &dp[501][502], 0);

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			dp[i][j] = -1;
			cin >> arr[i][j];
		}
	}

	dp[1][1] = 1;
	dfs(y, x);
	cout << dp[y][x];

	return 0;
}
