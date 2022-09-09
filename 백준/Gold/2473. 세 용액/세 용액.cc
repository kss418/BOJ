#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
long long n, num, st, en ,cur;
vector <long long> arr;
long long MAX = 3000000010;
long long a, b, c;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	bool zero = false;
	for (int i = 0; i < n;i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n - 2 && !zero; ++i) {
		st = i + 1;
		en = n - 1;
		while (st < en) {
			cur = arr[i] + arr[st] + arr[en];
			if (MAX > abs(cur)) {
				MAX = abs(cur);
				tie(a, b, c) = { arr[i],arr[st],arr[en] };
			}
			if (cur > 0) {
				--en;
			}
			else if (cur < 0) {
				++ st;
			}
			else {
				zero = true;
				tie(a, b, c) = { arr[i],arr[st],arr[en] };
				break;
			}
		}
	}

	cout << a << " " << b << " " << c;
	return 0;
}

