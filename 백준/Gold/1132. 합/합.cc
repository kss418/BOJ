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
const int MAX = 55;
pll num[10];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		ll cur = 1;
		num[s[0] - 'A'].second = 1;
		for (int j = s.size() - 1;j >= 0;j--) {
			num[s[j] - 'A'].first += cur;
			cur *= 10;
		}
	}

	sort(num, num + 10);

	ll result = 0;
	ll cnt = 1;
	ll zero = 0;
	for (int i = 0; i <= 9; i++) {
		if (!zero && !num[i].second) {
			zero = 1;
		}
		else {
			result += num[i].first * cnt;
			cnt++;
		}
	}

	cout << result;

	return 0;
}