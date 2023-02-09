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
const int MAX = 2020;
ll in[MAX], fac[MAX], MOD;
vector <ll> an, ak;


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
		ll ret = pow_mod(a, b / 2, c);
		return (ret % c * ret % c) * a % c;
	}
	else {
		ll ret = pow_mod(a, b / 2, c);
		return (ret % c * ret % c) % c;
	}
}

ll cal(ll a, ll b, ll c) {
	if (a < b) return 0;
	return fac[a] * in[b] % c * in[a - b] % c;
}

ll luc(ll a, ll b, ll c) {
	if (a < b || a < 0 || b < 0) return 0;
	if (!a || !b || a == b) return 1;
	return cal(a % c, b % c, c) * luc(a / c, b / c, c) % c;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	 
	cin >> n >> k >> MOD;

	fac[0] = 1;
	for (int i = 1; i < MOD; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	in[MOD - 1] = pow_mod(fac[MOD - 1], MOD - 2, MOD);
	for (int i = MOD - 2; i >= 0; i--) {
		in[i] = in[i + 1] * (i + 1) % MOD;
	}
	
	cout << luc(n, k, MOD);
	
	return 0;
}