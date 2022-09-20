#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[101][101];
vector <pair<int, int>> xa, ya;
int x, y, k, a, b, c, d;
bool xex, yex;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> x >> y >> k;
	while (k--) {
		cin >> a >> b >> c >> d;
		if (c - a == 1 || a - c == 1) {
			xa.push_back({ max(a, c),b });
		}
		else {
			ya.push_back({ max(b, d), a });
		}
	}

	dp[0][0] = 1;
	for (int i = 1; i <= x; i++) {
		xex = true;
		for (auto j : xa) {
			if (j.first == i && j.second == 0) {
				xex = false;
			}
		}
		if (xex) {
			dp[0][i] = dp[0][i - 1];
		}
	}

	for (int i = 1; i <= y; i++) {
		yex = true;
		for (auto j : ya) {
			if (j.first == i && j.second == 0) {
				yex = false;
			}
		}
		if (yex) {
			dp[i][0] = dp[i - 1][0];
		}
	}

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			yex = true;
			xex = true;
			for (auto k : xa) {
				if (k.first == i && k.second == j) {
					xex = false;
				}
			}

			for (auto k : ya) {
				if (k.first == j && k.second == i) {
					yex = false;
				}
			}

			if (xex && yex) {
				dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
			}
			else if (xex) {
				dp[j][i] = dp[j][i - 1];
			}
			else if (yex) {
				dp[j][i] = dp[j - 1][i];
			}
		}
	}

	
	cout << dp[y][x];

	return 0;
}
 