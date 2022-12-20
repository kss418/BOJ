#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
stack <ll> list;
ll arr[100001];
ll sum[100001];
ll seg[400004];

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
	ios_base::sync_with_stdio(false);


	ll n, num;
	int st, en;
	cin >> n;
	ll result = -1;

	sum[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	mk_seg(1, n, 1);


	for (ll i = 1; i <= n; i++) {
		ll num = arr[i];
		if (list.empty()) {
			list.push(i);
		}
		else {
			if (arr[list.top()] > num) {
				while (!list.empty() && arr[list.top()] > num) {
					int cur = list.top();
					list.pop();
					if (!list.empty()) {
						if (result < (query(1, n, 1, list.top() + 1, i - 1)) * (sum[i - 1] - sum[list.top()])) {
							result = max(result, (query(1, n, 1, list.top() + 1, i - 1)) * (sum[i - 1] - sum[list.top()]));
							st = list.top() + 1;
							en = i - 1;
						}
					}
					else {
						if (result < sum[i - 1] * query(1, n, 1, 1, cur)) {
							result = max(result, sum[i - 1] * query(1, n, 1, 1, cur));
							st = 1;
							en = i - 1;
						}
					}
				}
			}

			list.push(i);
		}
	}

	while (!list.empty()) {
		int cur = list.top();
		list.pop();
		if (!list.empty()) {
			if (result < (query(1, n, 1, list.top() + 1, n)) * (sum[n] - sum[list.top()])) {
				result = max(result, (query(1, n, 1, list.top() + 1, n)) * (sum[n] - sum[list.top()]));
				st = list.top() + 1;
				en = n;
			}
		}
		else {
			if (result < (query(1, n, 1, 1, n) * sum[n])) {
				result = max(result, (query(1, n, 1, 1, n) * sum[n]));
				st = 1;
				en = n;
			}
		}
	}

	cout << result << "\n";
	cout << st << " " << en;


	return 0;
}
