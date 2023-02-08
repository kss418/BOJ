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
const int MAX = 4;
vector <ll> arr, md;


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

pll crt(ll a1, ll m1, ll a2, ll m2) {
	ll g = get<0>(gcd(m1, m2));
	ll m = m1 / g * m2;
	if ((a2 - a1) % g) return{ -1,-1 };
	ll mul = mod((a2 - a1) / g, m2);
	ll x = mod(get<1>(gcd(m1, m2)), m2) * mul % m2;
	return { (a1 + x * m1) % m,m };
}

pll crt(const vector<ll>& a, const vector<ll>& m) {
	ll fa = a[0], fm = m[0];
	for (ll i = 1; i < m.size(); i++) {
		ll ca, cm;
		tie(ca,cm) = crt(fa, fm, a[i], m[i]);
		if (cm == -1) return { -1,-1 };
		tie(fa, fm) = tie(ca, cm);
	}

	return { fa,fm };
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		arr.clear();
		md.clear();
		for (int i = 1; i <= 3; i++) {
			cin >> n;
			arr.push_back(n);
		}
		for (int i = 1; i <= 3; i++) {
			cin >> n;
			md.push_back(n);
		}

		cout << crt(md,arr).first << "\n";
	}
	
	
	return 0;
}