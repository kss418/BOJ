#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 315159;
int arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	int cnt = 1;
	for (int i = n - 1; i >= 1; i--) {
		if (m >= i) {
			m -= i;
			arr[i + 1] = cnt++;
		}

		if (m == 0) {
			break;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			arr[i] = cnt++;
		}
		cout << arr[i] << " ";
	}


	return 0;
}