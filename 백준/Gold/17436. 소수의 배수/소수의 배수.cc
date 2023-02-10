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

int main() {
	fastio;

	ll result = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i < (1 << n); i++) {
		ll cnt = 0;
		ll cur = 1;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cnt++;
				cur *= arr[j + 1];
			}
		}

		if (cnt % 2) result += get_cnt(m, cur);
		else result -= get_cnt(m, cur);
	}

	cout << result;

	return 0;
}