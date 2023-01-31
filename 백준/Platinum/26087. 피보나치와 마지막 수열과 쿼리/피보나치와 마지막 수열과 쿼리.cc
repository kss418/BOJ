#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010101;
const ll MOD = 1e9 + 7;
ll fib[MAX], arr[MAX], num[MAX];
vector <pll> query;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 0; i <= n; i++) {
		num[i] = i + 1;
	}

	for (int i = 2; i <= n; i++) {
		fib[i] = (fib[i - 1] % MOD + fib[i - 2] % MOD) % MOD;
		
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		query.push_back({ a,b });
	}
	reverse(query.begin(), query.end());

	for (int i = 0; i < query.size(); i++) {
		ll st = query[i].first;
		ll en = query[i].second;

		ll cur = num[st - 1];
		while (cur <= en) {
			if (!arr[cur]) {
				arr[cur] = fib[cur - st + 1];
			}
			ll nxt = num[cur];
			num[cur] = en + 1;
			cur = nxt;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}






	return 0;
}