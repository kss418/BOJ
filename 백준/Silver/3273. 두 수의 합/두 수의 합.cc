#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 101010;
int arr[MAX];



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;

	sort(arr, arr + n + 1);
	int st = 1, en = n;
	int result = 0;

	while (st < en) {
		if (arr[st] + arr[en] < m) {
			st++;
		}
		else if (arr[st] + arr[en] > m) {
			en--;
		}
		else {
			st++;
			en--;
			result++;
		}
	}

	cout << result;
	
	return 0;
}