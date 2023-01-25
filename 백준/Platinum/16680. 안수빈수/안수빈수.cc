#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1;


bool dt(ll num) {
	ll ret = 0;
	while (num) {
		ret += num % 10;
		num /= 10;
	}

	return ret % 2;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		ll cur = n;
		while (!dt(cur)) {
			cur *= 2;
		}

		cout << cur << "\n";
	}

	return 0;
}