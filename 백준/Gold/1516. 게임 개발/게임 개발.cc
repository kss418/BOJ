#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 510;
vector <int> arr[MAX];
int ti[MAX], indegree[MAX], dp[MAX];
deque <int> q;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		cin >> ti[i];
		while (1) {
			int num;
			cin >> num;
			if (num == -1) {
				break;
			}
			arr[num].push_back(i);
			indegree[i]++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push_back(i);
			dp[i] = ti[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();

		for (auto nxt : arr[cur]) {
			dp[nxt] = max(dp[nxt], dp[cur] + ti[nxt]);

			indegree[nxt]--;
			if (!indegree[nxt]) {
				q.push_back(nxt);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << "\n";
	}

	

	return 0;
}