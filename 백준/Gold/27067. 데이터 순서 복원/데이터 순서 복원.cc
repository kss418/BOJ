#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
int indegree[3001];
int visit[3001];
int a[3001], b[3001], c[3001];
vector <int> arr[3001];
int cnt[3001][3001];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	


	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cnt[a[i]][a[j]]++;
			cnt[b[i]][b[j]]++;
			cnt[c[i]][c[j]]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cnt[i][j] >= 2) {
				arr[i].push_back(j);
				indegree[j]++;
			}
		}
	}

	deque <int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push_back(i);
		}
	}

	vector <int> result;
	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();
		if (visit[cur]) {
			continue;
		}

		result.push_back(cur);
		visit[cur] = 1;
		for (auto nxt : arr[cur]) {
			if (visit[nxt]) {
				continue;
			}

			indegree[nxt]--;
			if (!indegree[nxt]) {
				q.push_back(nxt);
			}
		}
	}

	for (auto i : result) {
		cout << i << " ";
	}
	
	return 0;
}
