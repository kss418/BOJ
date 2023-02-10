#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1110;
const ll MOD = 1e9 + 7;

ll mul_mod(ll a, ll b, ll c) {
	ll ret = a * b - c * ll(1.l / c * a * b);
	return ret + c * (ret < 0) - c * (ret >= (ll)c);
}

ll pow_mod(ll a, ll b, ll c) {
	ll ret = 1; a %= c;
	for (; b; b >>= 1) {
		if (b & 1) ret = mul_mod(ret, a, c);
		a = mul_mod(a, a, c);
	}
	return ret;
}


int main() {
	fastio;

	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}

		cout << pow_mod(2, n - 2, MOD) << "\n";
	}


	return 0;
}