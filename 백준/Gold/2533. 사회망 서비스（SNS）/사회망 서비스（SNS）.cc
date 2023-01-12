#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 1010101;
vector <int> arr[MAX];
int dp[MAX][2];
int result;

void dfs(int cur, int p) {
	if (dp[cur][0] != -1) {
		return;
	}

	dp[cur][0] = 0;
	dp[cur][1] = 0;
	for (auto nxt : arr[cur]) {
		if (nxt == p) {
			continue;
		}

		dfs(nxt, cur);
		dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
		dp[cur][0] += dp[nxt][1];
	}
	dp[cur][1]++;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i < n; i++) {
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}
	dfs(1, 0);

	cout << min(dp[1][0], dp[1][1]);
	

	return 0;
}