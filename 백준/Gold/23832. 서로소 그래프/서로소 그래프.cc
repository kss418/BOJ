#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1110;

ll op(ll a) {
	ll ret = a;
	for (ll i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			ret *= (1 - 1 / (double)i);
		}
		while (a % i == 0)	a /= i;
		if (a == 1) break;
	}

	if (a > 1) ret *= (1 - 1 / (double)a);
	return ret;
}

int main() {
	fastio;

	cin >> n;
	ll result = 0;
	for (int i = 2; i <= n; i++) {
		result += op(i);
	}
	cout << result;


	return 0;
}