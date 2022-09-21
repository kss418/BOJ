#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int t, n, k;
int dp[1121][15] = { 0, };
int prime[1121] = {};
vector <int> arr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int i = 2; i <= pow(1120, 0.5) + 1; i++) {
		if (prime[i] == 0) {
			for (int j = 2 * i; j <= 1120; j += i) {
				prime[j] = 1;
			}
		}
	}

	dp[0][0] = 1;
	for (int i = 2; i <= 1120; i++) {
		if (prime[i] == 0) {
			arr.push_back(i);
		}
	}

	for (int k = 0; k < arr.size(); k++) {
		for (int j = 14; j >= 1; j--) {
			for (int i = 2; i <= 1120; i++) {
				if (i >= arr[k]) {
					dp[i][j] += dp[i - arr[k]][j - 1];
				}
			}
		}
	}

	while (t--) {
		cin >> n >> k;
		cout << dp[n][k] << "\n";
	}
	

	return 0;
}
