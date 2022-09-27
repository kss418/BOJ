#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long arr[100003];
long long seg[400010];
long long n, m, k, num, a, b, c, d;

long long mk_seg(long long st, long long en, long long node) {
	if (st == en) {
		seg[node] = arr[st];
		return seg[node];
	}
	
	long long mid = (st + en) / 2;
	seg[node] = mk_seg(st, mid, node * 2) + mk_seg(mid + 1, en, node * 2 + 1);
	return seg[node];
}

long long query(long long st, long long en, long long node, long long l, long long r) {
	if (l > en || r < st) {
		return 0;
	}

	if (l <= st && r >= en) {
		return seg[node];
	}

	long long mid = (st + en) / 2;
	return query(st, mid, node * 2, l, r) + query(mid + 1, en, node * 2 + 1, l, r);
}

long long update(long long st, long long en, long long node, long long index, long long value) {
	if (index < st || index > en) {
		return seg[node];
	}

	if (st == en) {
		seg[node] = value;
		return seg[node];
	}
	long long mid = (st + en) / 2;
	seg[node] = update(st, mid, node * 2, index, value) + update(mid + 1, en, node * 2 + 1, index, value);
	return seg[node];
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}

	mk_seg(1, n, 1);


	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		if (a > b) {
			long long tmp = a;
			a = b;
			b = tmp;
		}
		cout << query(1, n, 1, a, b) << "\n";
		update(1, n, 1, c, d);
	}
	return 0;
}