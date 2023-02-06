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
const int MAX = 501;
vector <ll> arr[MAX];
ll cnt[MAX];


ll dfs(ll cur, ll p) {
	if (cnt[cur]) return 1;
	cnt[cur] = 1;
	ll ret = 0;

	for (auto nxt : arr[cur]) {
		if (nxt == p) continue;
		ret += dfs(nxt, cur);
	}

	if (ret) return 1;
	return 0;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll cur = 0;
	while (1) {
		cur++;
		cin >> n >> m;

		if (!(n + m)) {
			break;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) arr[i].clear();

		for (int i = 1; i <= m; i++) {
			ll st, en;
			cin >> st >> en;
			arr[en].push_back(st);
			arr[st].push_back(en);
		}

		ll result = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[i]) continue;
			if (!dfs(i, 0))	result++;
		}

		if (result == 1) {
			cout << "Case " << cur << ": There is one tree.\n";
		}
		else if (result) {
			cout << "Case " << cur << ": A forest of " << result << " trees.\n";
		}
		else {
			cout << "Case " << cur << ": No trees.\n";
		}
	}
	


	return 0;
}