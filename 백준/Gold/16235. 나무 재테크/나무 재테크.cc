#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int n, m, k, num;
int x, y, age;
int nxtx, nxty;
int add[11][11];
int ene[11][11];
int dead[11][11] = {};
int xa[8] = { -1,-1,-1,0,0,1,1,1 };
int ya[8] = { -1,0,1,-1,1,-1,0,1 };
vector <int> arr[11][11];

void spring() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j].empty()) {
				continue;
			}
			int die = 0;
			sort(arr[i][j].begin(), arr[i][j].end());
			int again = arr[i][j].size();
			for (int k = 0; k < again; k++) {
				if (die == 0 && arr[i][j][k] <= ene[i][j]) {
					ene[i][j] -= arr[i][j][k];
					arr[i][j][k]++;
				}
				else {
					die = 1;
					if (arr[i][j].back() % 2 == 0) {
						dead[i][j] += arr[i][j].back() / 2;
					}
					else {
						dead[i][j] += (arr[i][j].back() - 1) / 2;
					}
					arr[i][j].pop_back();
				}
			}
		}
	}
}

void summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ene[i][j] += dead[i][j];
			dead[i][j] = 0;
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j].empty()) {
				continue;
			}
			for (int k = 0; k < arr[i][j].size(); k++) {
				if (arr[i][j][k] % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						nxtx = j + xa[l];
						nxty = i + ya[l];
						if (nxtx >= n || nxtx < 0 || nxty >= n || nxty < 0) {
							continue;
						}
						arr[nxty][nxtx].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ene[i][j] += add[i][j];
		}
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			ene[i][j] = 5;
			add[i][j] = num;
		}
	}

	while (m--) {
		cin >> y >> x >> age;
		arr[y - 1][x - 1].push_back(age);
	}

	while (k--) {
		spring();
		summer();
		fall();
		winter();

	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result += arr[i][j].size();
		}
	}
	cout << result;
	return 0;
}
