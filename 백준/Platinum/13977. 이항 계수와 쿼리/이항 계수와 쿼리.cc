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
const int MAX = 4010101;
const ll MOD = 1e9 + 7;
ll in[MAX], fac[MAX];


tuple <ll,ll,ll> gcd(ll a, ll b) {
	if (!b) return { a, 1, 0 };
	ll g, x, y;
	tie(g, x, y) = gcd(b, a % b);
	return { g, y, x - a / b * y };
}

ll inv(ll a, ll m) {
	ll g, x, y;
	tie(g, x, y) = gcd(a, m);
	if (!a || g != 1) return -1;
	return x;
}

ll mod(ll a, ll b) {
	return (a % b >= 0) ? a % b : a % b + b;
}

ll pow_mod(ll a, ll b, ll c) {
	if (!b) return 1;

	if (b % 2) {
		b--;
		ll ret = pow_mod(a, b / 2, c) % c;
		return (ret % c * ret % c) * a % c;
	}
	else {
		ll ret = pow_mod(a, b / 2, c) % c;
		return (ret % c * ret % c) % c;
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	 
	fac[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	in[MAX - 1] = pow_mod(fac[MAX - 1], MOD - 2, MOD);
	for (int i = MAX - 2; i >= 0; i--) {
		in[i] = in[i + 1] * (i + 1) % MOD;
	}

	cin >> m;
	while (m--) {
		cin >> n >> k;
		cout << fac[n] * in[k] % MOD * in[n - k] % MOD << "\n";
	}
	
	
	return 0;
}