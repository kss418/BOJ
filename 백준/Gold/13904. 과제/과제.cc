#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, day, value, result, cur;
vector <pair<int, int>> arr;
vector <int> era;
int check[1001] = {};


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	result = 0;

	cin >> n;
	while (n--) {
		cin >> day >> value;
		arr.push_back({ value,day });
	}
	sort(arr.begin(), arr.end(), greater<>());
	while (!arr.empty()) {
		for (int i = 0; i < arr.size(); i++) {
			cur = arr[i].second;

			while (check[cur] == 1) {
				cur -= 1;
				if (cur == 0) {
					break;
				}
			}

			if (cur != 0) {
				check[cur] = 1;
				result += arr[i].first;
			}
			arr.erase(arr.begin() + i);
			break;
		}
	}


	cout << result;
	return 0;
}