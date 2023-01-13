#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 1010;
vector <pair <ll, int>> arr[MAX];
ll dist[MAX][MAX], query[MAX];
pair <int, int> mi[MAX];

struct node {
	ll d;
	int v;
	int c;
};


struct cmp {
	bool operator()(node a, node b) {
		return a.d < b.d;
	}
};

priority_queue <node, vector<node>, cmp> pq;




int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> n >> m >> k;
	int st, en;
	cin >> st >> en;
	memset(dist, 0x3f, sizeof(dist));
	memset(mi, 0x3f, sizeof(mi));
	while (m--) {
		int a, b, cost;
		cin >> a >> b >> cost;
		arr[a].push_back({ cost,b });
		arr[b].push_back({ cost,a });
	}

	dist[st][0] = 0;
	mi[st] = { 0,0 };
	pq.push({ dist[st][0],st,0});
	while (!pq.empty()) {
		int cur = pq.top().v;
		ll curd = pq.top().d;
		int curc = pq.top().c;
		pq.pop();

		if (dist[cur][curc] != curd) {
			continue;
		}

		if (curc >= n) {
			continue;
		}

		for (auto i : arr[cur]) {
			int nxt = i.second;
			ll nxtd = i.first;
			int nxtc = curc + 1;

			if (dist[nxt][nxtc] > dist[cur][curc] + nxtd) {
				if (mi[nxt].second > nxtc || mi[nxt].first > dist[cur][curc] + nxtd) {
					dist[nxt][nxtc] = dist[cur][curc] + nxtd;
					node p = { dist[nxt][nxtc] ,nxt,nxtc };
					pq.push(p);
					if (mi[nxt].first > dist[nxt][nxtc]) {
						mi[nxt].first = dist[nxt][nxtc];
						mi[nxt].second = nxtc;
					}
					else if (mi[nxt].first == dist[nxt][nxtc]) {
						mi[nxt].second = min(mi[nxt].second, nxtc);
					}
				}
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		cin >> query[i];
	}

	for (int i = 0; i <= k; i++) {
		ll result = 1e10;
		for (int j = 1; j <= n; j++) {
			dist[en][j] += query[i] * j;
			result = min(result, dist[en][j]);
		}
		cout << result << "\n";
	}

	return 0;
}