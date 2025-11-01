#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, num;
int result = 10000;
int arr[51][51];
vector <int> pt;
vector <pair<int, int>> charr;
vector <pair<int, int>> btarr;
void bt();
void bf();
int visited[14] = {};


void bt() {
	for (int i = 0; i < charr.size() - m; i++) {
		pt.push_back(0);
	}
	for (int i = 0; i < m; i++) {
		pt.push_back(1);
	}
	do {
		btarr.clear();
		for (int i = 0; i < charr.size(); i++) {
			if (pt[i] == 1) {
				btarr.push_back(charr[i]);
			}
		}
		bf();
	} while (next_permutation(pt.begin(), pt.end()));
}

void bf() {
	int ch = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (arr[y][x] == 1) {
				int d = 10000;
				for (int ord = 0; ord < btarr.size(); ord++) {
					d = min(d, abs(x - btarr[ord].first) + abs(y - btarr[ord].second));
				}
				ch += d;
			}
		}
	}
	result = min(result, ch);
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			arr[i][j] = num;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 2) {
				charr.push_back(make_pair(j, i));
			}
		}
	}

	bt();
	cout << result << endl;

	return 0;
}