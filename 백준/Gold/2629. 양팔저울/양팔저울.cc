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


const int MAX = 31;
int arr[MAX], dp[MAX][100001];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[0][50000] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = -50000; j < 50000; j++) {
			if (arr[i] + j <= 50000) {
				dp[i][arr[i] + j + 50000] = max(dp[i - 1][j + 50000], dp[i][arr[i] + j + 50000]);
			}

			if (j - arr[i] > -50000) {
				dp[i][j - arr[i] + 50000] = max(dp[i - 1][j + 50000], dp[i][j - arr[i] + 50000]);
			}
			dp[i][j + 50000] = max(dp[i][j + 50000], dp[i - 1][j + 50000]);
		}
	}

	cin >> m;
	while (m--) {
		cin >> k;
		if (dp[n][k + 50000]) {
			cout << "Y" << " ";
		}
		else {
			cout << "N" << " ";
		}
	}


	return 0;
}