#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 110;
const int MOD = 1e9 + 7;
ll dp[MAX][MAX][MAX];

ll dfs(int cur, int l, int r) {
	ll& ret = dp[cur][l][r];
	if (ret != -1) {
		return ret;
	}
	
	if (!l || !r) {
		ret = 0;
		return ret;
	}

	if (cur == n && l == 1 && r == 1) {
		ret = 1;
		return ret;
	}
	else if (cur == n) {
		ret = 0;
		return ret;
	}
	


	ret = dfs(cur + 1, l - 1, r) + dfs(cur + 1, l, r - 1) + (n - cur - 1) * dfs(cur + 1, l, r);
	ret %= MOD;


	return ret;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int l, r;
	cin >> n >> l >> r;
	memset(dp, -1, sizeof(dp));

	cout << dfs(1, l, r) % MOD;



	return 0;
}