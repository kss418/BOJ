#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long arr[1000003];
long long seg[4000010];
long long n, m, k, num, a, b;
int mod = 1000000007;


long long mk_seg(int st, int en, int node) {
	if (st == en) {
		seg[node] = arr[st];
		return seg[node];
	}
	int mid = (st + en) / 2;

	seg[node] = ((mk_seg(st, mid, node * 2) % mod) * (mk_seg(mid + 1, en, node * 2 + 1) % mod)) % mod;
	return seg[node]; 
}

long long query(int st, int en, int node, int l, int r) {
	if (l > en || r < st) {
		return 1;
	}

	if (l <= st && en <= r) {
		return seg[node];
	}
	int mid = (st + en) / 2;
	return ((query(st, mid, node * 2, l, r) % mod) * (query(mid + 1, en, node * 2 + 1, l, r) % mod)) % mod;
}

long long update(int st, int en, int node, int index, long long value) {
	if (index < st || index > en) {
		return seg[node];
	}

	if (st == en) {
		seg[node] = value;
		return seg[node];
	} 
	int mid = (st + en) / 2;
	seg[node] = ((update(st, mid, node * 2, index, value) % mod) * (update(mid + 1, en, node * 2 + 1, index, value) % mod)) % mod;
	return seg[node];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 1; i < 4 * n + 5; i++) {
		seg[i] = 1;
	}
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}
	mk_seg(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		cin >> num >> a >> b;
		if (num == 1) {
			update(1, n, 1, a, b);
		}
		else {
			cout << query(1, n, 1, a, b) << "\n";
		}
	}
	return 0;
}