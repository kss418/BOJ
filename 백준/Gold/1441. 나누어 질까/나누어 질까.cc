#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1110;
ll arr[MAX];


ll get_cnt(ll a, ll b) {
	return a / b;
}

tuple <ll, ll, ll> gcd(ll a, ll b) {
	if (!b) return{ a,1,0 };
	ll g, x, y;
	tie(g, x, y) = gcd(b, a % b);
	return { g, y, y - a / b * x };
}

ll lcm(ll a, ll b) {
	return a * b / get<0>(gcd(a, b));
}

int main() {
	fastio;

	ll result = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i < (1 << n); i++) {
		ll cnt = 0;
		ll cur = INF;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				if (cur == INF) cur = arr[j + 1];
				cnt++;
				cur = lcm(cur, arr[j + 1]);

				if (cur > k) break;
			}
		}
		if (cur > k) continue;

		ll curr = get_cnt(k, cur) - get_cnt(m - 1, cur);
		if (cnt % 2) result += curr;
		else result -= curr;
	}

	cout << result;

	return 0;
}