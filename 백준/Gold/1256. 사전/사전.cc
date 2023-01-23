#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101;
ll dp[MAX][MAX];
vector <char> result;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 0; i <= max(n, m); i++) {
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	dp[0][0] = 0;

	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min(dp[i][j - 1] + dp[i - 1][j], ll(1e9));
		}
	}
	
	if (dp[n][m] < k) {
		cout << -1;
		return 0;
	}
	ll cur = k;
	
	while (1) {
		if (!n) {
			for (int i = 1; i <= m; i++) {
				result.push_back('z');
			}
			break;
		}

		if (!m) {
			for (int i = 1; i <= n; i++) {
				result.push_back('a');
			}
			break;
		}

		if (cur > dp[n - 1][m]) {
			cur -= dp[n - 1][m];
			m--;
			result.push_back('z');
		}
		else {
			n--;
			result.push_back('a');
		}
	}
	

	for (auto i : result) {
		cout << i;
	}

	

	return 0;
}