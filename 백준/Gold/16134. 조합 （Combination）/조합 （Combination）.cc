#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 2010101;
const ll MOD = 1e9 + 7;


ll mod(ll a, ll b) {
	return (a % b >= 0) ? a % b : a % b + b;
}

tuple <ll, ll, ll> gcd(ll a, ll b) {
	if (!b) return { a,1,0 };
	ll g, x, y;
	tie(g, x, y) = gcd(b, a % b);
	return{ g, y, y - a / b * x };
}

ll inv(ll a, ll m) {
	ll g, x, y;
	tie(g, x, y) = gcd(a, m);
	if (!a || g != 1) return -1;
	return x;
}

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

struct comb {
	const ll b;
	vector<ll> fac, in;

	comb (ll a, ll b) : b(b) {
		fac.resize(a + 1);
		in.resize(a + 1);
		fac[0] = 1;
		for (int i = 1; i < a; i++) fac[i] = fac[i - 1] * i % b;
		in[a - 1] = pow_mod(fac[a - 1], b - 2, b);
		for (int i = a - 2; i >= 0; i--) in[i] = in[i + 1] * (i + 1) % b;
	}

	ll ret(ll a, ll b, ll c) {
		if (a < b) return 0;
		return fac[a] * in[b] % c * in[a - b] % c;
	}
};


int main() {
	fastio;

	cin >> n >> m;
	comb a(MAX, MOD);
	cout << a.ret(n, m, MOD);


	return 0;
}