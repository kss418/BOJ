#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[16][16];
int dp[16][1 << 16];
int n;

int dfs(int cur, int visit) {
	if (dp[cur][visit] != -1) {
		return dp[cur][visit];
	}

	if (visit == (1 << n) - 1) {
		if (arr[cur][0] != 0) {
			return arr[cur][0];
		}
		
		return 1000000000;
	}

	dp[cur][visit] = 1000000000;
	for (int i = 0; i < n; i++) {
		if (visit & (1 << i) || arr[cur][i] == 0) {
			continue;
		}

		dp[cur][visit] = min(dp[cur][visit], dfs(i, visit | (1 << i)) + arr[cur][i]);
	}

	return dp[cur][visit];
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	fill(&dp[0][0], &dp[15][1 << 16], -1);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	cout << dfs(0, 1);



	return 0;
}
