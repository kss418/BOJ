#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
vector <int> arr;
int over[4000001];
int start[4000001];
int na[4000001];



int ub(int num) {
	int st = 0, en = m - 1;
	int m = en;
	while (en > st) {
		int mid = (st + en) / 2;
		
		if (arr[mid] < arr[m] && arr[mid] > num) {
			m = mid;
		}

		if (arr[mid] > num) {
			en = mid;
		}
		else if (arr[mid] == num) {
			return mid + 1;
		}
		else {
			st = mid + 1;
		}
	}

	return m;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());


	int put = 1;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		int cur = ub(num);
		
		if (!na[cur]) {
			na[cur] = put++;
			over[na[cur]] = 1;
			start[na[cur]] = cur;
		}
		else {
			while (na[cur]) {
				cur = start[na[cur]];
				cur += over[na[cur]];
			}
			na[cur] = na[cur - 1];
			over[na[cur]]++;
		}
		
			
		cout << arr[cur] << " ";
	}


	return 0;
}
