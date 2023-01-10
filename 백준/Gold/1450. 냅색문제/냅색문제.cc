#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 31;
int arr[MAX];
vector <ll> sarr1, sarr2;
vector <int> result;

void bt1() {
	if (result.size() == (int)(n / 2)) {
		ll sum = 0;
		for (int i = 0; i < result.size(); i++) {
			if (result[i]) {
				sum += arr[i + 1];
			}
		}
		sarr1.push_back(sum);
		return;
	}

	for (int i = 0; i <= 1; i++) {
		result.push_back(i);
		bt1();
		result.pop_back();
	}
}

void bt2() {
	if (result.size() == n - (int)(n / 2)) {
		ll sum = 0;
		for (int i = 0; i < result.size(); i++) {
			if (result[i]) {
				sum += arr[i + 1 + (int)(n / 2)];
			}
		}
		sarr2.push_back(sum);
		return;
	}

	for (int i = 0; i <= 1; i++) {
		result.push_back(i);
		bt2();
		result.pop_back();
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n + 1);

	int result = 0;
	bt1(); bt2();
	sort(sarr1.begin(), sarr1.end());
	sort(sarr2.begin(), sarr2.end());

	for (auto i : sarr1) {
		if (i <= m) {
			auto iter = upper_bound(sarr2.begin(),sarr2.end(),(m - i));
			if (iter == sarr2.end()) {
				result += sarr2.size();
				continue;
			}
			result += iter - sarr2.begin();
		}
	}

	cout << result;

	return 0;
}