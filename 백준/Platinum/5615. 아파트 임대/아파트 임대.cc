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
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 11;
vector <ull> l_list = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
vector <ull> i_list = { 2,7,61 };



ull pow_mod(ull a, ull b, ull c) {
	if (!b) return 1;

	if (b % 2) {
		b--;
		ull ret = pow_mod(a, b / 2, c) % c;
		return (ret % c * ret % c) * a % c;
	}
	else {
		ull ret = pow_mod(a, b / 2, c) % c;
		return (ret % c * ret % c) % c;
	}
}

bool mr(ull a, ull b) {
	ull cur = a - 1;
	cur /= 2;
	while (cur % 2 == 0) {
		if (pow_mod(b, cur, a) == a - 1) {
			return 1;
		}
		cur /= 2;
	}
	ull last = pow_mod(b, cur, a);
	if (last == a - 1 || last == 1) return 1;
	return 0;
}

bool is_prime(ull n) {
	if (n <= 1)
		return 0;
	if (n == 2 || n == 7 || n == 61) return 1;
	for (ull i : i_list)
		if (!mr(n, i))
			return 0;
	return 1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> t;
	ll result = 0;
	while (t--) {
		cin >> n;
		n = 2 * n + 1;
		result += is_prime(n);
	}
	cout << result;


	return 0;
}