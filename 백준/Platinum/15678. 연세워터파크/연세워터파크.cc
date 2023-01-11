#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 101010;
ll dp[MAX];
ll arr[MAX];
deque <pair<ll,int>> q;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}


	for (int i = 1; i <= n; i++) {
		while (!q.empty() && q.front().second < i - m) {
			q.pop_front();
		}

		if (!q.empty()) {
			dp[i] = max(dp[i], q.front().first + arr[i]);
		}

		while (!q.empty() && q.back().first < dp[i]) {
			q.pop_back();
		}

		q.push_back({ dp[i],i });
	}

	ll result = -1e16;
	for (int i = 1; i <= n; i++) {
		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}