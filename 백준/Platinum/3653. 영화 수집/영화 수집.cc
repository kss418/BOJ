#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 201010;
int arr[MAX], seg[4 * MAX], pos[MAX];


int mk_seg(int st, int en, int node) {	
	if (st == en) {
		seg[node] = arr[st];
		return seg[node];
	}

	int mid = (st + en) / 2;

	seg[node] = mk_seg(st, mid, node * 2) + mk_seg(mid + 1, en, node * 2 + 1);
	return seg[node];
}


int update(int st, int en, int node, int idx, int value) {
	if (idx < st || idx > en) {
		return seg[node];
	}

	if (st == en) {
		seg[node] = value;
		return seg[node];
	}

	int mid = (st + en) / 2;
	seg[node] = update(st, mid, node * 2, idx, value) + update(mid + 1, en, node * 2 + 1, idx, value);
	return seg[node];
}

int query(int st, int en, int node, int l, int r) {
	if (st > r || en < l) {
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

	cin >> t;
	while (t--) {
		cin >> n >> m;

		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= n; i++) {
			arr[i] = 1;
		}

		for (int i = 1; i <= n; i++) {
			pos[i] = n - i + 1;
		}
		mk_seg(1, n + m + 1, 1);

		int last = n + 1;
		for (int i = 1; i <= m; i++) {
			int q;
			cin >> q;
			cout << query(1, n + m + 1, 1, pos[q] + 1, n + m + 1) << " ";
			update(1, n + m + 1, 1, last, 1);
			update(1, n + m + 1, 1, pos[q], 0);
			pos[q] = last++;
		}
		cout << "\n";
	}

	return 0;
}