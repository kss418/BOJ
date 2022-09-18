#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, st, m, num;
int dp[51][1001];
int result = -1;
vector <int> arr;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> st >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	fill(&dp[0][0], &dp[50][1001], 0);
	dp[0][st] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j + arr[i - 1] <= m) {
				dp[i][j + arr[i - 1]] = max(dp[i - 1][j], dp[i][j + arr[i - 1]]);
			}

			if (j - arr[i - 1] >= 0) {
				dp[i][j - arr[i - 1]] = max(dp[i - 1][j], dp[i][j - arr[i - 1]]);
			}
		}
	}
	

	for (int i = 0; i <= m; i++) {
		if (dp[n][i] == 1) {
			result = i;
		}
	}

	cout << result;
	
	return 0;
}
