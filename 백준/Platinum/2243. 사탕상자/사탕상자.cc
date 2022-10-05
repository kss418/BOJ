#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a, b, c, n, seg[4000004] = {};

void update(int st, int en, int node, int num, int value) {
	if (st > num || en < num) {
		return;
	}

	seg[node] += value;
	if (st == en) {
		return;
	}

	int mid = (st + en) / 2;
	update(st, mid, node * 2, num, value);
	update(mid + 1, en, node * 2 + 1, num, value);
}

int query(int st, int en, int node, int num) {
	if (st == en) {
		return en;
	}

	int mid = (st + en) / 2;
	if (seg[node * 2] < num) {
		return query(mid + 1, en, node * 2 + 1, num - seg[node * 2]);
	}
	else {	
		return query(st, mid, node * 2, num);
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a == 1) {
			int cur = query(1, 1000000, 1, b);
			update(1, 1000000, 1, cur, -1);
			cout << cur << "\n";
		}
		else {
			cin >> c;
			update(1, 1000000, 1, b, c);
		}
	}
	
	return 0;
}
