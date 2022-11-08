#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int bi, n, ret;
deque <int> q;
int ind[100001] = {}, ti[100001] = {}, dp[100001] = {};
vector <int> arr[100001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> bi >> n;
		q.clear();
		fill(ind,ind + 100000,0);
		fill(ti, ti + 100000, 0);
		fill(dp, dp + 100000, 0);

		for (int i = 0; i < 100001; i++) {
			arr[i].clear();
		}
		
		for (int i = 1; i < bi + 1; i++) {
			cin >> ti[i];
			dp[i] = ti[i];
		}

		
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			ind[b]++;
		}

		cin >> ret;

		for (int i = 1; i < bi + 1; i++) {
			if (!ind[i]) {
				q.push_back(i);
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop_front();
			for (auto i : arr[cur]) {
				ind[i]--;
				dp[i] = max(dp[i], ti[i] + dp[cur]);
				if (!ind[i]) {
					q.push_back(i);
				}
			}
		}

		cout << dp[ret] << "\n";
	}


	return 0;
}
