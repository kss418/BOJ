#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
long long b, c, n, now = 0;
long long arr[1000007] = {};
long long result = 0;


void buy(int num) {
	int cur;
	if (arr[num] == 0) {
		return;
	}

	if (arr[num + 1] == 0) {
		result += arr[num] * b;
		arr[num] = 0;
		return;
	}

	if (arr[num + 2] == 0) {
		cur = min(arr[num], arr[num + 1]);
		result += cur * (b + c);
		arr[num] -= cur;
		arr[num + 1] -= cur;
		return;
	}

	if (arr[num + 2] < arr[num + 1]) {
		cur = min(arr[num], arr[num + 1] - arr[num + 2]);
		result += cur * (b + c);
		arr[num] -= cur;
		arr[num + 1] -= cur;
		return;
	}

	cur = min({ arr[num],arr[num + 1],arr[num + 2] });
	result += cur * (b + 2 * c);
	arr[num] -= cur;
	arr[num + 1] -= cur;
	arr[num + 2] -= cur;

	return;
}



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> b >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (b > c) {
		while (now != n) {
			if (arr[now] == 0) {
				now++;
			}
			buy(now);
		}
	}

	else {
		for (int i = 0; i < n; i++) {
			result += arr[i] * b;
		}
	}

	cout << result;


	return 0;
}
