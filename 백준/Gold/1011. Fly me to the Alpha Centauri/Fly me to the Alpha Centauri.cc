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
const int MAX = 12;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		ll diff = abs(n - m);
		ll result = 0;
		for (ll i = 1; i <= (1 << 18); i++) {
			ll cur;
			if (i % 2) {
				cur = ((i + 1) * (i + 1)) >> 2ll;
			}
			else {
				cur = (i * (i + 2)) >> 2ll;
			}

			if (cur >= diff) {
				result = i;
				break;
			}
		}
		
		cout << result << "\n";
	}
	

	return 0;
}