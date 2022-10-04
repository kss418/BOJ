#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int s, n, num, m = 0, st = 0, en = 0, tar;
vector <int> arr;
int track[800001];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	fill(track, track + 800000, 987654321);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];
			track[sum] = min(track[sum], j);
		}
	}

	for (int i = 1; i < 400000; i++) {
		st = track[i] + 1;
		en = n - 1;
		tar = s - i;
		while (st < en) {
			int cur = arr[st] + arr[en];
			if (cur > tar) {
				en--;
			}
			else if (cur < tar) {
				st++;
			}
			else {
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";


	return 0;
}
