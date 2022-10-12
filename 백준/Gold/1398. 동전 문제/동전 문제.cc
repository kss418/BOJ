#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;




int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	long long value;
	cin >> t;
	while (t--) {
		cin >> value;
		long long cur = 1;
		int result = 0;
		int cnt = 0;

		while (1) {
			if (value == 0) {
				break;
			}
			
			if (value < cur) {
				if (cnt % 2) {
					value -= (long long)(cur / 10);
				}
				else if (value >= 50 * (long long)(cur / 100) && cnt != 0) {
					value -= 25 * (long long)(cur / 100);
				}
				else if (value >= 25 * (long long)(cur / 100) && cnt != 0 && value % (long long)(cur / 10) >= 5 * (long long)(cur / 100)) {
					value -= 25 * (long long)(cur / 100);
				}
				else {
					value -= (long long)(cur / 10);
				}
				cur = 1;
				result++;
				cnt = 0;
				continue;
			}
			cnt++;
			cur *= 10;
		}

		cout << result << "\n";
	}


	return 0;
}
