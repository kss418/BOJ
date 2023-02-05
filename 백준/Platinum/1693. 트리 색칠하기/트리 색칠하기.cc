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
ll dp[MAX][23], lg;


ll dfs(ll cur, ll p, ll color) {
	ll& ret = dp[cur][color];
	if (ret != -1) return ret;
	ret = color;

	ll tmp = 0;
	for (auto nxt : arr[cur]) {
		if (nxt == p) continue;
		ll pa = INF;

		for (int i = 1; i <= lg; i++) {
			if (i == color) continue;
			pa = min(pa, dfs(nxt, cur, i));
		}
		tmp += pa;
	}
	ret += tmp;

	return ret;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; (1 << i) <= n; i++) {
		lg = i;
	}

	for (int i = 1; i < n; i++) {
		ll st, en;
		cin >> st >> en;
		arr[st].push_back(en);
		arr[en].push_back(st);
	}
	memset(dp, -1, sizeof(dp));

	ll result = INF;
	for (int i = 1; i <= lg; i++) {
		result = min(result, dfs(1, 0, i));
	}

	cout << result;


	return 0;
}