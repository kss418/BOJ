#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int n;
int arr[7000][7000] = { 0, };
void dfs(int x, int y, int n) {
	if (n == 3) {
		for (int i = 0; i <= 2;i++) {
			arr[x + i][y + i] = 1;
			arr[x - i][y + i] = 1;
			arr[x + i][y + 2] = 1;
			arr[x - i][y + 2] = 1;
		}
		return;
	}

	dfs(x , y, n / 2);
	dfs(x + n / 2, y + n / 2, n / 2);
	dfs(x - n / 2, y + n / 2, n / 2);
	return;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	dfs(3500, 0, n);

	for (int j = 0; j < n; j++) {
		for (int i = 3500 - n + 1; i < 3500 + n; i++) {
			if (arr[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}