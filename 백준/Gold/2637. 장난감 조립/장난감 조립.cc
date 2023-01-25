#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 110;
vector <pi> arr[MAX];
int dp[MAX][MAX], indegree[MAX];
set <int> stand;
deque <int> q;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int en, st, k;
		cin >> en >> st >> k;
		arr[st].push_back({ en,k });
		indegree[en]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push_back(i);
			stand.insert(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();

		for (auto i : arr[cur]) {
			int nxt = i.first;
			int cnt = i.second;
			
			if (stand.count(cur)) {
				dp[nxt][cur] += cnt;
			}
			else {
				for (auto j : stand) {
					dp[nxt][j] += dp[cur][j] * cnt;
				}
			}

			indegree[nxt]--;
			if (!indegree[nxt]) {
				q.push_back(nxt);
			}
		}
	}

	for (int i = 1; i < n; i++) {
		if (dp[n][i]) {
			cout << i << " " << dp[n][i] << "\n";
		}
	}
	

	return 0;
}