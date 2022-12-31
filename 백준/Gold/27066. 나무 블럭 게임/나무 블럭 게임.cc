#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	double result = 0;
	deque <double> arr;
	cout.precision(9);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	int mid;
	int first = arr.front();
	int fisize = 1;
	arr.pop_front();
	arr.push_front(0);


	while (arr.size() > 1) {
		if (arr.size() % 2 == 1) {
			mid = (arr.size() - 1) / 2;
			mid++;
		}
		else {
			mid = arr.size() / 2;
		}
		mid--;

		result = max(result, arr[mid]);
		arr.pop_front();
		first += arr.front();
		arr.pop_front();
		arr.push_front(0);
		fisize++;
	}

	result = max(result, first / (double)fisize);
	cout << result;

	return 0;
}
