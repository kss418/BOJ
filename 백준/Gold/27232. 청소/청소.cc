#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 501010;
int arr[MAX], num[MAX];
set <int> pl, mi;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	ll dist = INF;
	ll result = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		num[arr[i]] = i;
		pl.insert(arr[i]);
		mi.insert(-arr[i]);

		auto cur = pl.find(arr[i]);
		auto pre = mi.upper_bound(-arr[i]);
		auto nxt = pl.upper_bound(arr[i]);


		if (pre == mi.end() && nxt == pl.end()) {}
		else if (pre == mi.end()) {
			result += abs(num[*nxt] - num[*cur]);
		}
		else if (nxt == pl.end()) {
			result += abs(num[-*pre] - num[*cur]);
		}
		else {
			result += abs(num[*nxt] - num[*cur]);
			result += abs(num[-*pre] - num[*cur]);
			result -= abs(num[-*pre] - num[*nxt]);
		}
		

		if (pl.size() > m) {
			cur = pl.find(arr[i - m]);
			pre = mi.upper_bound(-arr[i - m]);
			nxt = pl.upper_bound(arr[i - m]);


			if (pre == mi.end() && nxt == pl.end()) {}
			else if (pre == mi.end()) {
				result -= abs(num[*nxt] - num[*cur]);
			}
			else if (nxt == pl.end()) {
				result -= abs(num[-*pre] - num[*cur]);
			}
			else {
				result -= abs(num[*nxt] - num[*cur]);
				result -= abs(num[-*pre] - num[*cur]);
				result += abs(num[-*pre] - num[*nxt]);
			}

			pl.erase(pl.find(arr[i - m]));
			mi.erase(mi.find(-arr[i - m]));
		}

		if (pl.size() == m) {
			dist = min(result, dist);
		}
	}
	
	cout << dist;


	return 0;
}