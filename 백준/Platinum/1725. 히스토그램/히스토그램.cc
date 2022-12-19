#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	stack <pair<int, int>> list;
	int n, num;
	cin >> n;
	int result = 0;
	int mi = 1000000001;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (list.empty()) {
			list.push({ num,i });
		}
		else {
			if (list.top().first > num) {
				while (!list.empty() && list.top().first > num) {
					int cur = list.top().first;
					list.pop();
					if (!list.empty()) {
						result = max(result, (i - list.top().second - 1) * cur);
					}
					else {
						result = max(result, (i - 1) * cur);
					}
				}
			}

			list.push({ num,i });
		}
	}

	while (!list.empty()) {
		int cur = list.top().first;
		list.pop();
		if (!list.empty()) {
			result = max(result, (n - list.top().second) * cur);
		}
		else {
			result = max(result, n * cur);
		}


	}
	cout << result << "\n";


	return 0;
}
