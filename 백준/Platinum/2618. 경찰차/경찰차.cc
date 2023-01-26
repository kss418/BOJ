#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010;
ll dp[MAX][MAX];
pll track[MAX][MAX];
vector <int> trace;


struct pos {
	ll x;
	ll y;
};
pos arr[MAX];

ll dist(pos a, pos b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= m; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	arr[0] = { 1,1 };
	dp[0][0] = 0;
	pos two = { n,n };

	for (int k = 1; k <= m; k++) {
		for (int j = 0; j <= m; j++) {
			if (j >= k) {
				break;
			}

			if (dp[k][j] > dp[k - 1][j] + dist(arr[k], arr[k - 1])) {
				track[k][j] = { k - 1,j };
				dp[k][j] = min(dp[k][j], dp[k - 1][j] + dist(arr[k], arr[k - 1]));
			}

			if (dp[k][k - 1] > dp[j][k - 1] + dist(arr[k], arr[j])) {
				track[k][k - 1] = { j,k - 1 };
				dp[k][k - 1] = min(dp[k][k - 1], dp[j][k - 1] + dist(arr[k], arr[j]));
			}

			if (k == 1) {
				if (dp[j][k] > dp[j][k - 1] + dist(arr[k], two)) {
					track[j][k] = { j,k - 1 };
					dp[j][k] = min(dp[j][k], dp[j][k - 1] + dist(arr[k], two));
				}
			}
			else {
				if (dp[j][k] > dp[j][k - 1] + dist(arr[k], arr[k - 1])) {
					track[j][k] = { j,k - 1 };
					dp[j][k] = min(dp[j][k], dp[j][k - 1] + dist(arr[k], arr[k - 1]));
				}
			}

			if (j == 0) {
				if (dp[k - 1][k] > dp[k - 1][j] + dist(arr[k], two)) {
					track[k - 1][k] = { k - 1,j };
					dp[k - 1][k] = min(dp[k - 1][k], dp[k - 1][j] + dist(arr[k], two));
				}
			}
			else {
				if (dp[k - 1][k] > dp[k - 1][j] + dist(arr[k], arr[j])) {
					track[k - 1][k] = { k - 1,j };
					dp[k - 1][k] = min(dp[k - 1][k], dp[k - 1][j] + dist(arr[k], arr[j]));
				}
			}
		}
	}

	ll result = INF;
	pll st = { 0,0 };

	for (int i = 0; i <= m; i++) {
		if (dp[i][m] < result) {
			result = dp[i][m];
			st = { i,m };
		}

		if (dp[m][i] < result) {
			result = dp[m][i];
			st = { m,i };
		}
	}

	cout << result << "\n";

	while (st.first || st.second) {
		if (st.first > track[st.first][st.second].first) {
			trace.push_back(1);
		}
		else {
			trace.push_back(2);
		}

		st = track[st.first][st.second];
	}
	reverse(trace.begin(), trace.end());

	for (auto i : trace) {
		cout << i << "\n";
	}
	

	return 0;
}