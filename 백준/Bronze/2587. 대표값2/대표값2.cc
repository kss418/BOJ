#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	vector <int> arr;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		sum += num;
	}

	sort(arr.begin(), arr.end());
	cout << sum / 5 << "\n" << arr[2];


	return 0;
}
