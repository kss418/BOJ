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
vector <ll> arr[MAX];
ll dp[MAX];

void dfs(ll cur, ll p) {
	dp[cur] += dp[p];
	for (auto nxt : arr[cur]) {
		dfs(nxt, cur);
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (i == 1) continue;
		arr[k].push_back(i);
	}

	while (m--) {
		ll v, c;
		cin >> v >> c;
		dp[v] += c;
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++) cout << dp[i] << " ";


	return 0;
}