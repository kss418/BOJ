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


tuple <ll,ll,ll> gcd(ll a, ll b) {
	if (!b) return { a, 1, 0 };
	ll g, x, y;
	tie(g, x, y) = gcd(b, a % b);
	return { g, y, x - a / b * y };
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	 
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (n == 1 && m == 1) {
			cout << 2 << '\n';
			continue;
		}
		else if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		else if (m == 1) {
			if (n + 1 <= 1e9) {
				cout << n + 1 << "\n";
			}
			else {
				cout << "IMPOSSIBLE\n";
			}
			continue;
		}

		ll result = get<2>(gcd(n, m));
		if (result <= 0) result += n;
		if (result > 1e9 || (result * m) % n != 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

	

		cout << result << "\n";
	}

	
	return 0;
}