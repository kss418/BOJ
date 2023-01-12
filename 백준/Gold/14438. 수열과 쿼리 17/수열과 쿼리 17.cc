#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long arr[100003];
long long seg[401000];
int com, a, b, n, m;

int mk_seg(int st, int en, int node) {
	if (st == en) {
		seg[node] = arr[st];
		return seg[node];
	}

	int mid = (st + en) / 2;
	seg[node] = min(mk_seg(st, mid, node * 2), mk_seg(mid + 1, en, node * 2 + 1));
	return seg[node];
}

int query(int st, int en, int node, int l, int r) {
	if (l > en || r < st) {
		return 1000000000;
	}

	if (r >= en && st >= l) {
		return seg[node];
	}

	int mid = (st + en) / 2;
	return min(query(st, mid, node * 2, l, r), query(mid + 1, en, node * 2 + 1, l, r));
}

int update(int st, int en, int node,int index ,int value) {
	if (index < st || index > en) {
		return seg[node];
	}

	if (st == en) {
		seg[node] = value;
		return seg[node];
	}

	int mid = (st + en) / 2;
	seg[node] = min(update(st, mid, node * 2, index, value), update(mid + 1, en, node * 2 + 1, index, value));
	return seg[node];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}
	cin >> m;
	mk_seg(1, n, 1);

	while (m--) {
		cin >> com >> a >> b;
		if (com == 1) {
			update(1, n, 1, a, b);
		}
		else{
			cout << query(1, n, 1, a, b) << "\n";
		}
	}
	return 0;
}