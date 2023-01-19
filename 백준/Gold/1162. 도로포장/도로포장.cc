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
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 10101;

struct node {
	ll d;
	ll c;
	ll en;
};
vector <pll> arr[MAX];
ll dp[MAX][21];

struct cmp {
	bool operator()(node a, node b) {
		return a.d > b.d;
	}
};
priority_queue <node, vector<node>, cmp> pq;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll st, en, cost;
		cin >> st >> en >> cost;
		arr[st].push_back({ cost,en });
		arr[en].push_back({ cost,st });
	}
	memset(dp, 0x3f, sizeof(dp));

	dp[1][k] = 0;
	pq.push({ 0, k, 1 });

	while (!pq.empty()) {
		ll cur = pq.top().en;
		ll curd = pq.top().d;
		ll curc = pq.top().c;
		pq.pop();

		if (dp[cur][curc] != curd) {
			continue;
		}

		for (auto i : arr[cur]) {
			ll nxt = i.second;
			ll nxtd = curd + i.first;
			ll nxtc = curc - 1;

			if (dp[nxt][curc] > nxtd) {
				dp[nxt][curc] = nxtd;
				pq.push({ nxtd,curc,nxt });
			}

			if (dp[nxt][nxtc] > curd && nxtc >= 0) {
				dp[nxt][nxtc] = curd;
				pq.push({ curd,nxtc,nxt });

				for (int j = nxtc; j <= k; j++) {
					if (dp[nxt][j] <= curd) {
						break;
					}
					dp[nxt][j] = curd;
				}
			}
		}
	}

	if (k >= m) {
		cout << 0;
	}
	else {
		cout << dp[n][0];
	}

	return 0;
}