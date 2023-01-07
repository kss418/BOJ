#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, m, k; string s;

const int MAX = 1101010;
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


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
	ll result = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
		result += query(1, n, 1, num + 1, n);
		update(1, n, 1, num, 1);
    }

	cout << result;

    return 0;
}