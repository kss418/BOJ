#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 11;
vector <ll> result;


tuple <ll, ll, ll> gcd(ll a, ll b) {
	if (!b) return { a,1,0 };
	ll g, x, y;
	tie(g, x, y) = gcd(b, a % b);
	return{ g, y, y - a / b * x };
}

ull mul_mod(ll a, ll b, ll c) {
	ll ret = a * b - c * ull(1.l / c * a * b);
	return ret + c * (ret < 0) - c * (ret >= (ll)c);
}

ull pow_mod(ull a, ull b, ull c) {
	ull ret = 1; a %= c;
	for (; b; b >>= 1) {
		if (b & 1) ret = mul_mod(ret, a, c);
		a = mul_mod(a, a, c);
	}
	return ret;
}

bool mr(ull a, ull b) {
	if (a % b == 0) return 0;
	for (ll d = a - 1; ; d >>= 1) {
		ll t = pow_mod(b, d, a);
		if (d & 1) return t != 1 && t != a - 1;
		if (t == a - 1) return 0;
	}
}

bool is_prime(ull n) {
	if (n == 2 || n == 3 || n == 5 || n == 7) return 1;
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return 0;
	if (n < 121) return n > 1;
	if (n < 1ull << 32) for (ull i : { 2, 7, 61 }) {
		if (n == i) return 1;
		if (n > i && mr(n, i)) return 0;
	}
	else for (ull i : { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
		if (n == i) return 1;
		if (n > i && mr(n, i)) return 0;
	}
	return 1;
}

ll f(ll a, ll b, ll c) {
	return (mul_mod(a, a, c) + b) % c;
}

void get_prime(ll n) {
	if (n == 1) return;

	if (n % 2 == 0) {
		result.push_back(2);
		get_prime(n / 2);
		return;
	}

	if (is_prime(n)) {
		result.push_back(n);
		return;
	}

	ll a, b, c, g = n;
	do {
		if (g == n) {
			a = b = rand() % (n - 2) + 2;
			c = rand() % 20 + 1;
		}
		a = f(a, c, n);
		b = f(f(b, c, n), c, n);
		g = get<0>(gcd(abs(a - b), n));
	} while (g == 1);

	get_prime(g);
	get_prime(n / g);
}

int main() {
	fastio;

	cin >> n;
	get_prime(n);
	sort(result.begin(), result.end());
	for (auto i : result) cout << i << "\n";


	return 0;
}