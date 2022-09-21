#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[30] = {};
vector <int> result;
int out = 0;
string alp;
int mul, num, n;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--) {
		cin >> alp;
		mul = 1;
		for (int i = alp.size() - 1; i >= 0; i--) {
			arr[(int)alp[i] - 65] += mul;
			mul *= 10;
		}
	}

	for (int i = 0; i <= 29; i++) {
		if (arr[i] != 0) {
			result.push_back(arr[i]);
		}
	}

	sort(result.begin(), result.end());
	reverse(result.begin(), result.end());

	num = 9;
	for (auto i : result) {
		out += i * num;
		num--;
	}

	cout << out;
	

	return 0;
}
