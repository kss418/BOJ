#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 501010;
ll arr[MAX], seg[4 * MAX];
pll num[MAX];

void update(int st, int en, int node, int idx, int value) {
	if (st > idx || en < idx) {
		return;
	}
	
	seg[node] += value;
	if (st == en) {
		return;
	}

	int mid = (st + en) / 2;
	update(st, mid, node * 2, idx, value);
	update(mid + 1, en, node * 2 + 1, idx, value);
}


ll query(int st, int en, int node, int l,int r) {
	if (l > en || r < st) {
		return 0;
	}

	if (l <= st && en <= r) {
		return seg[node];
	}

	int mid = (st + en) / 2;
	return query(st, mid, node * 2, l, r) + query(mid + 1, en, node * 2 + 1, l, r);
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) { 
		cin >> num[i].first;
		num[i].second = i;
	}
	sort(num + 1, num + n + 1);

	for (int i = 1; i <= n; i++) {
		arr[num[i].second] = i;
	}

	for (int i = 1; i <= n; i++) {
		cout << i - query(1, n, 1, 1, arr[i]) << "\n";
		update(1, n, 1, arr[i], 1);
	}
		

	return 0;
}