#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;
vector <pll> arr[MAX];
ll result, dp[MAX];


void dfs(ll cur, ll p) {
	ll curn = 0;
	priority_queue <ll> pq;
	for (auto i : arr[cur]) {
		ll nxt = i.first;
		ll cst = i.second;
		if (nxt == p) continue;

		dfs(nxt, cur);
		pq.push(dp[nxt] + cst);
		dp[cur] = max(dp[cur], dp[nxt] + cst);
	}

	ll fi = 0;
	if (!pq.empty()) {
		fi = pq.top();
		pq.pop();
	}

	ll se = 0;
	if (!pq.empty()) {
		se = pq.top();
	}


	result = max(fi + se, result);
}


int main() {
	cin.tie(0); 
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll st, en, c;
		cin >> st;
		while (1) {
			cin >> en;
			if (en == -1) {
				break;
			}

			cin >> c;
			arr[st].push_back({ en ,c });
		}
	}

	dfs(1, 0);
	cout << result;
	

	return 0;
}