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


struct node {
	ll d;
	ll c;
	ll en;
};

struct cmp {
	bool operator()(node a, node b) {
		return a.d < b.d;
	}
};

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101;
vector <node> arr[MAX];
ll dp[MAX][MAX * MAX];
queue <node> pq;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> k >> m;
		for (int i = 0; i <= n; i++) {
			arr[i].clear();
		}

		while (m--) {
			int st, en, c, d;
			cin >> st >> en >> c >> d;
			arr[st].push_back({ d,c,en });
		}

		memset(dp, 0x3f, sizeof(dp));

		dp[0][0] = 0;
		dp[1][0] = 0;
		pq.push({ 0,0,1 });
		while (!pq.empty()) {
			ll cur = pq.front().en;
			ll curd = pq.front().d;
			ll curc = pq.front().c;
			pq.pop();

			if (dp[cur][curc] != curd) {
				continue;
			}

			for (auto i : arr[cur]) {
				ll nxt = i.en;
				ll nxtd = i.d;
				ll nxtc = i.c;

				if (curc + nxtc > k) {
					continue;
				}

				if (dp[nxt][curc + nxtc] > dp[cur][curc] + nxtd) {
					dp[nxt][curc + nxtc] = dp[cur][curc] + nxtd;
					pq.push({ dp[nxt][curc + nxtc],curc + nxtc,nxt });
				}
			}
		}

		ll result = INF;
		for (int i = 0; i <= k; i++) {
			result = min(result, dp[n][i]);
		}

		if (result == INF) {
			cout << "Poor KCM\n";
		}
		else {
			cout << result << "\n";
		}
	}


	return 0;
}