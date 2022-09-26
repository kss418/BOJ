#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;
int n;
string chr;
int arr[16][16];
int dp[16][10][1 << 16];


int dfs(int cur, int value, int visit) {
	int& ret = dp[cur][value][visit];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int i = 1; i <= n; i++) {
		if ((visit & (1 << i)) || arr[cur][i] < value || cur == i) {
			continue;
		}

		ret = max(ret, dfs(i, arr[cur][i], visit | (1 << i)) + 1);
	}

	return ret;
}



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> chr;
		for (int j = 1; j <= n; j++) {
			arr[i][j] = chr[j - 1] - '0';
		}
	}

	cout << dfs(1, 0, 1 << 1) + 1;


	return 0;
}
