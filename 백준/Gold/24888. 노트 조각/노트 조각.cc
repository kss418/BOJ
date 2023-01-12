#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 201010;
vector <pair<int, int>> arr[MAX];
ll a[MAX], d[MAX], dp[MAX], track[MAX];
priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	fill(d, d + n + 1,1e16);
	memset(dp, -1, sizeof(dp));

	while (m--) {
		int st, en, cost;
		cin >> st >> en >> cost;
		arr[st].push_back({ en,cost });
		arr[en].push_back({ st,cost });
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	
	dp[1] = a[1];
	d[1] = 0;
	pq.push({ d[1], 1 });
	while (!pq.empty()) {
		pair <ll, int> cur = pq.top();
		pq.pop();
		if (d[cur.second] != cur.first) {
			continue;
		}

		for (auto nxt : arr[cur.second]) {
			if (d[nxt.first] > d[cur.second] + nxt.second) {
				d[nxt.first] = d[cur.second] + nxt.second;
				track[nxt.first] = cur.second;
				dp[nxt.first] = dp[cur.second] + a[nxt.first];

				pq.push({ d[nxt.first],nxt.first });
			}
			else if (d[nxt.first] == d[cur.second] + nxt.second) {
				if (dp[nxt.first] < dp[cur.second] + a[nxt.first]) {
					track[nxt.first] = cur.second;
					dp[nxt.first] = dp[cur.second] + a[nxt.first];
					pq.push({ d[nxt.first],nxt.first });
				}
			}
		}
	}

	vector <int> result;
	if (dp[n] == cnt) {
		int cur = n;
		while (1) {
			result.push_back(cur);
			if (cur == 1) {
				break;
			}
			cur = track[cur];
		}

		reverse(result.begin(), result.end());
		cout << result.size() << "\n";
		for (auto i : result) {
			cout << i << " ";
		}
	}
	else {
		cout << -1;
	}



	return 0;
}