#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a, b, c, n, k, num, seg[4000004] = {};
vector <int> arr;


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


	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	int si = 0;
	long long result = 0;
	for (int i = 0; i < n; i++) {
		update(1, 66000, 1, arr[i] + 1, 1);
		si++;
		if (si == k) {
			result += query(1, 66000, 1, (int)((k + 1) / 2)) - 1;
			update(1, 66000, 1, arr[i - k + 1] + 1, -1);
			si--;
		}
	}
	
	cout << result;
	
	return 0;
}
