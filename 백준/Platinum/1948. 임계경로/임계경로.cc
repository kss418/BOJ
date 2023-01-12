#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <deque>
#include <stack>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 10101;
vector <pair<int, int>> arr[MAX];
vector <int> track[MAX];
int indegree[MAX], dist[MAX], v[MAX];
int cnt;
deque <int> q;


void dfs(int cur, int p) {
	if (v[cur]) {
		return;
	}
	v[cur] = 1;

	for (auto nxt : track[cur]) {
		if (nxt == p) {
			continue;
		}

		cnt++;
		dfs(nxt, cur);
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int st, en, cost;
		cin >> st >> en >> cost;
		arr[st].push_back({ en,cost });
		indegree[en]++;
	}
	int st, en;
	cin >> st >> en;
	q.push_back(st);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();

		for (auto nxt : arr[cur]) {
			indegree[nxt.first]--;
			if (dist[cur] + nxt.second > dist[nxt.first]) {
				dist[nxt.first] = dist[cur] + nxt.second;
				track[nxt.first].clear();
				track[nxt.first].push_back(cur);
			}
			else if (dist[cur] + nxt.second == dist[nxt.first]) {
				track[nxt.first].push_back(cur);
			}

			if (!indegree[nxt.first]) {
				q.push_back(nxt.first);
			}
		}
	}

	cout << dist[en] << "\n";
	dfs(en, 0);
	cout << cnt;
	



	return 0;
}