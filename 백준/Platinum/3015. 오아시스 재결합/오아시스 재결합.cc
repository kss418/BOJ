#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
stack <pair<ll, int>> list;
ll arr[500001];
ll result = 0;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	

	for (int i = 0; i < n; i++) {
		if (list.empty()) {
			list.push({ arr[i],1 });
		}
		else {
			if (list.top().first < arr[i]) {
				while (!list.empty() && list.top().first < arr[i]) {
					result += list.top().second;
					list.pop();
				}

				if (!list.empty() && list.top().first > arr[i]) {
					result++;
				}

				if (!list.empty() && list.top().first == arr[i]) {
					int cur = list.top().second;
					list.pop();
					if (!list.empty() && list.top().first > arr[i]) {
						result++;
					}
					list.push({ arr[i], cur + 1 });
					result += cur;
				}
				else {
					list.push({ arr[i],1 });
				}
			}

			else if (list.top().first > arr[i]) {
				list.push({ arr[i],1 });
				result++;
			}

			else {
				int ord = list.top().second;
				list.pop();
				if (!list.empty() && list.top().first > arr[i]) {
					result += ord + 1;
				}
				else if (!list.empty() && list.top().first < arr[i]) {
					result += ord;
				}
				else {
					result += ord;
				}
				list.push({ arr[i] , ord + 1 });
			}
		}
	}

	cout << result;

	return 0;
}
