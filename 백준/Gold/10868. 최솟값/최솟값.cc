#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long arr[1000003];
long long seg[4000010];
long long n, m, k, num, a, b;

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

	if (l <= st && en <= r) {
		return seg[node];
	}
	int mid = (st + en) / 2;
	return min(query(st, mid, node * 2, l, r), query(mid + 1, en, node * 2 + 1, l, r));
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i < 4 * n + 5; i++) {
		seg[i] = 1;
	}
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}
	mk_seg(1, n, 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << query(1, n, 1, a, b) << "\n";
	}
	return 0;
}