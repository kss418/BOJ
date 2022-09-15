#include <iostream>
using namespace std;
int n;
int arr[501][501];
int dp[501][501];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> dp[n][i];
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
		}
	}

	cout << dp[1][1];

	return 0;
}
