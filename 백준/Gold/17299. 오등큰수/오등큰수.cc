#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
int arr[1000001];
int result[1000001];
int num[1000001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	stack <int> list;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		arr[num[i]]++;
	}


	for (int i = 0; i < n; i++) {
		if (list.empty()) {
			list.push(i);
		}
		else {
			if (!list.empty() && arr[num[list.top()]] < arr[num[i]]) {
				while (!list.empty() && arr[num[list.top()]] < arr[num[i]]) {
					result[list.top()] = num[i];
					list.pop();
				}
			}
			list.push(i);
		}
	}

	while (!list.empty()) {
		result[list.top()] = -1;
		list.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}

	return 0;
}
