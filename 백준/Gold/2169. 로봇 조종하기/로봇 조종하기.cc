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

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010;
int dp[MAX][MAX][3], arr[MAX][MAX];



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int y, x;
	cin >> y >> x;
	fill(&dp[0][0][0], &dp[y + 1][x + 1][3], -INF);
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1][1] = arr[1][1];
	for (int i = 2; i <= x; i++) {
		dp[1][i][1] = dp[1][i - 1][1] + arr[1][i];
	}

	for (int i = 2; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][k] + arr[i][j]);
			}
		}

		for (int j = 1; j <= x; j++) {
			dp[i][j][1] = max({ dp[i][j - 1][0] + arr[i][j],dp[i][j - 1][1] + arr[i][j] ,dp[i][j][1] });
		}

		for (int j = x; j >= 1; j--) {
			dp[i][j][2] = max({ dp[i][j + 1][0] + arr[i][j],dp[i][j + 1][2] + arr[i][j] ,dp[i][j][2] });
		}
	}


	cout << max({ dp[y][x][0] ,dp[y][x][1],dp[y][x][2] });


	return 0;
}