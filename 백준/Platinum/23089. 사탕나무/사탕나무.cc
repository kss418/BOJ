#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;
vector <ll> arr[MAX], ord;
ll dp[MAX][22], diff[22];


void dfs1(ll cur, ll p) {
	for (int i = 0; i <= m; i++) dp[cur][i] = 1;

	for (auto nxt : arr[cur]) {
		if (nxt == p) continue;
		dfs1(nxt, cur);
		for (int i = 1; i <= m; i++) {
			dp[cur][i] += dp[nxt][i - 1];
		}
	}
}


void dfs2(ll cur, ll p) {
	if (p) {
		for (int i = 0; i <= m; i++) diff[i] = dp[cur][i];

		for (int i = 1; i <= m; i++) {
			if (i == 1) {
				dp[cur][i]++;
				continue;
			}
			dp[cur][i] += dp[p][i - 1] - diff[i - 2];
		}
	}

	for (auto nxt : arr[cur]) {
		if (nxt == p) continue;
		dfs2(nxt, cur);
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		ll st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}

	dfs1(1, 0);
	dfs2(1, 0);


	ll result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, dp[i][m]);
	}

	cout << result;


	return 0;
}