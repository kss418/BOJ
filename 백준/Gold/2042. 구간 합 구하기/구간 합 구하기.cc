#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long arr[1000003];
long long seg[4000010];
long long n, m, k, num, a, b;

long long mk_seg(int st, int en, int node) {
	if (st == en) {
		return seg[node] = arr[st];
	}
	int mid = (st + en) / 2;
	seg[node] = mk_seg(st, mid, node * 2) + mk_seg(mid + 1, en, node * 2 + 1);
	return seg[node];
}

long long query(int st, int en, int node, int left, int right) {
	if (left > en || right < st) {
		return 0;
	}

	if (left <= st && en <= right) {
		return seg[node];
	}
	int mid = (st + en) / 2;
	return query(st, mid, node * 2, left, right) + query(mid + 1, en, node * 2 + 1, left, right);
	
}

void update(int st, int en, int node, int index, long long value) {
	if (index < st || index > en) {
		return;
	}

	seg[node] += value;
	if (st == en) {
		return;
	}
	int mid = (st + en) / 2;
	update(st, mid, node * 2, index, value);
	update(mid + 1, en, node * 2 + 1, index, value);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}
	mk_seg(1, n, 1);
	
	for (int i = 0; i < m + k; i++) {
		cin >> num >> a >> b;
		if (num == 1){
			long long tmp = arr[a];
			arr[a] = b;
			update(1, n, 1, a, b - tmp);
		}
		else {
			cout << query(1, n, 1, a, b) << "\n";
		}
	}
	
	return 0;
}