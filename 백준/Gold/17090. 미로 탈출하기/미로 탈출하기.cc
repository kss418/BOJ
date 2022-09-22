#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int x, y;
int dp[501][501];
char arr[501][501];
string in;
int result = 0;


int find(int b, int a) {
	dp[b][a] = 0;
	if (arr[b][a] == 'U') {
		if (dp[b - 1][a] != -1) {
			return dp[b][a] = dp[b - 1][a];
		}

		return dp[b][a] = find(b - 1, a);
	}
	else if (arr[b][a] == 'D') {
		if (dp[b + 1][a] != -1) {
			return dp[b][a] = dp[b + 1][a];
		}

		return dp[b][a] = find(b + 1, a);
	}
	else if (arr[b][a] == 'R') {
		if (dp[b][a + 1] != -1) {
			return dp[b][a] = dp[b][a + 1];
		}

		return dp[b][a] = find(b, a + 1);
	}
	else {
		if (dp[b][a - 1] != -1) {
			return dp[b][a] = dp[b][a - 1];
		}

		return dp[b][a] = find(b, a - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> y >> x;
	for (int i = 0; i < y; i++) {
		cin >> in;
		for (int j = 0; j < in.size(); j++) {
			arr[i][j] = in[j];
		}
	}

	fill(&dp[0][0], &dp[500][501], -1);

	for (int i = 0; i < x; i++) {
		if (arr[0][i] == 'U') {
			dp[0][i] = 1;
		}

		if (arr[y - 1][i] == 'D') {
			dp[y - 1][i] = 1;
		}
	}

	for (int i = 0; i < y; i++) {
		if (arr[i][0] == 'L') {
			dp[i][0] = 1;
		}

		if (arr[i][x - 1] == 'R') {
			dp[i][x - 1] = 1;
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (dp[i][j] == -1) {
			dp[i][j] = find(i, j);
			}
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			result += dp[i][j];
		}
	}

	cout << result;


	return 0;
}
