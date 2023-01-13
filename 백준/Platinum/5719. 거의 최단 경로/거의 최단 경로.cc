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

const int MAX = 510;
vector <int> track[MAX];
vector <pair<int, int>> arr[MAX];
int dist[MAX], unable[MAX][MAX], v[MAX];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dfs(int cur, int p) {
	if (v[cur]) {
		return;
	}
	v[cur] = 1;

	for (auto nxt : track[cur]) {
		if (nxt == p) {
			continue;
		}

		unable[nxt][cur] = 1;
		dfs(nxt, cur);
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	while (1) {
		cin >> n >> m;
		if (!n && !m) {
			break;
		}

		for (int i = 0; i < n; i++) {
			arr[i].clear();
			track[i].clear();
		}

		memset(unable, 0, sizeof(unable));
		memset(v, 0, sizeof(v));
		memset(dist, 0x3f, sizeof(dist));
		int st, en;
		cin >> st >> en;
		dist[st] = 0;

		while (m--) {
			int a, b, cost;
			cin >> a >> b >> cost;
			arr[a].push_back({ cost,b });
		}
		pq.push({ dist[st],st });

		while (!pq.empty()) {
			int cur = pq.top().second;
			int curd = pq.top().first;
			pq.pop();

			if (dist[cur] != curd) {
				continue;
			}

			for (auto i : arr[cur]) {
				int nxt = i.second;
				int nxtd = i.first;

				if (dist[nxt] > dist[cur] + nxtd) {
					dist[nxt] = dist[cur] + nxtd;
					track[nxt].clear();
					track[nxt].push_back(cur);
					pq.push({ dist[nxt],nxt });
				}
				else if (dist[nxt] == dist[cur] + nxtd) {
					track[nxt].push_back(cur);
				}
			}
		}

		dfs(en, -1);
		memset(dist, 0x3f, sizeof(dist));

		dist[st] = 0;
		pq.push({ dist[st],st });

		while (!pq.empty()) {
			int cur = pq.top().second;
			int curd = pq.top().first;
			pq.pop();

			if (dist[cur] != curd) {
				continue;
			}

			for (auto i : arr[cur]) {
				int nxt = i.second;
				int nxtd = i.first;

				if (unable[cur][nxt]) {
					continue;
				}

				if (dist[nxt] > dist[cur] + nxtd) {
					dist[nxt] = dist[cur] + nxtd;
					pq.push({ dist[nxt],nxt });
				}
			}
		}

		if (dist[en] == 0x3f3f3f3f) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[en] << "\n";
		}
	}

	return 0;
}