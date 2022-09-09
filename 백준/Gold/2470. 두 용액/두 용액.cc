#include <iostream>
#include <algorithm>
using namespace std;
int n, num, st, en;
int arr[100001];
pair <int, int> result;




int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	}
	sort(arr, arr + n);
	st = 0;
	en = n - 1;
	int diff = 2000000000;
	int cur;
	while (st != en) {
		cur = arr[st] + arr[en];
		if (abs(cur) < diff) {
			diff = abs(cur);
			result.first = arr[st];
			result.second = arr[en];
		}
		if (cur > 0) {
			en -= 1;
		}
		else if (cur < 0) {
			st += 1;
		}
		else {
			result.first = arr[st];
			result.second = arr[en];
			break;
		}
	}
	cout << result.first << " " << result.second;
	return 0;
}

