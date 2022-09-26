#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int n, now = 0;
int arr[10007] = {};
long long result = 0;


void buy(int num) {
	int cur;
	if (arr[num] == 0) {
		return;
	}

	if (arr[num + 1] == 0) {
		result += arr[num] * 3;
		arr[num] = 0;
		return;
	}

	if (arr[num + 2] == 0) {
		cur = min(arr[num], arr[num + 1]);
		result += cur * 5;
		arr[num] -= cur;
		arr[num + 1] -= cur;
		return;
	}

	if (arr[num + 2] < arr[num + 1]) {
		cur = min(arr[num], arr[num + 1] - arr[num + 2]);
		result += cur * 5;
		arr[num] -= cur;
		arr[num + 1] -= cur;
		return;
	}

	cur = min({ arr[num],arr[num + 1],arr[num + 2] });
	result += cur * 7;
	arr[num] -= cur;
	arr[num + 1] -= cur;
	arr[num + 2] -= cur;

	return;
}



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	while (now != n) {
		if (arr[now] == 0) {
			now++;
		}
		buy(now);
	}

	cout << result;


	return 0;
}
