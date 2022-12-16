#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int result = 1000000;
int n;
int arr2[1001][1001];
int arr5[1001][1001];
pair <int, int> min2[1001][1001];
pair <int, int> min5[1001][1001];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int num;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> num;
			if (num == 0) {
				arr2[y][x] = -1;
				arr5[y][x] = -1;
				continue;
			}

			while (num % 2 == 0) {
				num /= 2;
				arr2[y][x]++;
			}
			while (num % 5 == 0) {
				num /= 5;
				arr5[y][x]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (arr2[i - 1][1] == -1) {
			arr2[i][1] = -1;
		}

		min2[i][1].first = min2[i - 1][1].first + arr2[i][1];
		min2[i][1].second = min2[i - 1][1].second + arr5[i][1];
		min5[i][1].first = min5[i - 1][1].first + arr2[i][1];
		min5[i][1].second = min5[i - 1][1].second + arr5[i][1];
	}

	for (int i = 1; i <= n; i++) {
		if (arr2[1][i - 1] == -1) {
			arr2[1][i] = -1;
		}

		min2[1][i].first = min2[1][i - 1].first + arr2[1][i];
		min2[1][i].second = min2[1][i - 1].second + arr5[1][i];
		min5[1][i].first = min5[1][i - 1].first + arr2[1][i];
		min5[1][i].second = min5[1][i - 1].second + arr5[1][i];
	}

	for (int y = 2; y <= n; y++) {
		for (int x = 2; x <= n; x++) {
			if (arr2[y][x - 1] == -1 && arr2[y - 1][x] == -1) {
				arr2[y][x] = -1;
			}
			else if (arr2[y][x - 1] == -1){
				min2[y][x].first = min2[y - 1][x].first + arr2[y][x];
				min2[y][x].second = min2[y - 1][x].second + arr5[y][x];
			}
			else if (arr2[y - 1][x] == -1) {
				min2[y][x].first = min2[y][x - 1].first + arr2[y][x];
				min2[y][x].second = min2[y][x - 1].second + arr5[y][x];
			}
			else if (min2[y][x - 1].first >= min2[y - 1][x].first) {
				min2[y][x].first = min2[y - 1][x].first + arr2[y][x];
				min2[y][x].second = min2[y - 1][x].second + arr5[y][x];
			}
			
			else if (min2[y][x - 1].first <= min2[y - 1][x].first) {
				min2[y][x].first = min2[y][x - 1].first + arr2[y][x];
				min2[y][x].second = min2[y][x - 1].second + arr5[y][x];
			}
			
			if (arr2[y][x - 1] == -1 && arr2[y - 1][x] == -1) {
				arr2[y][x] = -1;
			}
			else if (arr2[y][x - 1] == -1) {
				min5[y][x].first = min5[y - 1][x].first + arr2[y][x];
				min5[y][x].second = min5[y - 1][x].second + arr5[y][x];
			}
			else if (arr2[y - 1][x] == -1) {
				min5[y][x].first = min5[y][x - 1].first + arr2[y][x];
				min5[y][x].second = min5[y][x - 1].second + arr5[y][x];
			}
			else if (min5[y][x - 1].second >= min5[y - 1][x].second) {
				min5[y][x].first = min5[y - 1][x].first + arr2[y][x];
				min5[y][x].second = min5[y - 1][x].second + arr5[y][x];
			}
			else if (min5[y][x - 1].second <= min5[y - 1][x].second) {
				min5[y][x].first = min5[y][x - 1].first + arr2[y][x];
				min5[y][x].second = min5[y][x - 1].second + arr5[y][x];
			}
			else {
				arr2[y][x] = -1;
			}
		}
	}

	cout << min(min(min2[n][n].first, min2[n][n].second), min(min5[n][n].first, min5[n][n].second)) << "\n";
	


	return 0;
}
