#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, m, k; string s;

const int MAX = 2101010;
int seg[4 * MAX];

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
	for (int i = 1; i <= n; i++) {
		int com, x;
		cin >> com >> x;
		if (com == 1) {
			update(1, MAX, 1, x, 1);
		}
		else {
			int cur = query(1, MAX, 1, x);
			cout << cur << "\n";
			update(1, MAX, 1, cur, -1);
		}
	}



    return 0;
}