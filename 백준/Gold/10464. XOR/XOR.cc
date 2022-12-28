#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int sum[101];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		a--;
		int result1 = 0, result2 = 0;
		while (a % 4 != 3 && a >= 0) {
			result1 ^= a;
			a--;
		}

		while (b % 4 != 3 && b >= 0) {
			result2 ^= b;
			b--;
		}

		int result = result1 ^ result2;
		cout << result << '\n';
	}
	
	
	return 0;
}

