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
ll result;

ll mod(ll a, ll b) {
	return (a % b >= 0) ? a % b : a % b + b; 
}

tuple <ll,ll,ll> ext_gcd(ll a, ll b) {
	if (!b) return { a, 1, 0 };
	ll g, x, y;
	tie(g, x, y) = ext_gcd(b, a % b);
	return { g, y, x - a / b * y };
}

ll gcd(ll a, ll b) {
	while (b) {
		ll mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}

ll inv(ll a, ll m) {
	ll g, x, y;
	tie(g, x, y) = ext_gcd(a, m);
	if (!a || g != 1) return -1;
	return x;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll m, seed, x1, x2, a, c;
	cin >> m >> seed >> x1 >> x2;
	
	if (seed > x1) a = (x1 - x2) * inv(seed - x1, m);
	else a = (x2 - x1) * inv(x1 - seed, m);
	a = mod(a, m);
	c = mod(x1 - seed * a, m);

	cout << a << " " << c;
	
	return 0;
}