#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int min_dp[2][3];
int max_dp[2][3];
int n, num;
int arr[3];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i <= 2; i++) {
		cin >> arr[i];
		min_dp[0][i] = arr[i];
		max_dp[0][i] = arr[i];
	}


	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 2; j++) {
			cin >> arr[j];
		}
		min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + arr[0];
		min_dp[1][1] = min({ min_dp[0][0], min_dp[0][1],min_dp[0][2] }) + arr[1];
		min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + arr[2];

		max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + arr[0];
		max_dp[1][1] = max({ max_dp[0][0], max_dp[0][1],max_dp[0][2] }) + arr[1];
		max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + arr[2];

		for (int k = 0; k <= 2; k++) {
			max_dp[0][k] = max_dp[1][k];
			min_dp[0][k] = min_dp[1][k];
		}
	}

	cout << max({ max_dp[0][0],max_dp[0][1],max_dp[0][2] }) << " " << min({ min_dp[0][0],min_dp[0][1],min_dp[0][2] });


	return 0;
}
