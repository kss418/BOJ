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
const int MAX = 101010;
vector <int> arr[MAX];
ll in[MAX], out[MAX], cnt, seg[4 * MAX], lazy[4 * MAX], pa[MAX];


void prop(int st, int en, int node) {
	if (!lazy[node]) {
		return;
	}

	if (st < en) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	seg[node] += lazy[node] * (en - st + 1);
	lazy[node] = 0;
}

void dfs(int cur,int p) {
	in[cur] = ++cnt;
	pa[cur] = p;
	for (auto nxt : arr[cur]) {
		if (nxt == p) continue;
		dfs(nxt, cur);
	}
	out[cur] = cnt;
}

void update(int st, int en, int node, int l, int r, ll value) {
	prop(st, en, node);

	if (en < l || st > r) {
		return;
	}

	if (st >= l && en <= r) {
		lazy[node] += value;
		prop(st, en, node);
		return;
	}

	int mid = (st + en) / 2;
	update(st, mid, node * 2, l, r, value);
	update(mid + 1, en, node * 2 + 1, l, r, value);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int st, int en, int node, int l,int r) {
	prop(st, en, node);

	if (en < l || st > r) {
		return 0;
	}

	if (st >= l && en <= r) {
		return seg[node];
	}

	int mid = (st + en) / 2;
	return query(st, mid, node * 2, l, r) + query(mid + 1, en, node * 2 + 1, l, r);
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (num == -1) {
			continue;
		}
		
		arr[i].push_back(num);
		arr[num].push_back(i);
	}

	dfs(1, 0);
	while (m--) {
		int com, a, b;
		cin >> com;
		if (com == 1) {
			cin >> a >> b;
			update(1, n, 1, in[a], in[a], b);
		}
		else {
			cin >> a;
			cout << query(1, n, 1, in[a], out[a]) << "\n";
		}
	}


	return 0;
}