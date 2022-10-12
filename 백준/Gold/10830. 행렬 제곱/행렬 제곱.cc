#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[5][5], result[5][5], cal[5][5];
vector <bool> ord;
int n;

void pow() {
	fill(&cal[0][0], &cal[4][5], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cal[i][j] += result[i][k] * result[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = cal[i][j] % 1000;
		}
	}
}

void mul() {
	fill(&cal[0][0], &cal[4][5], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cal[i][j] += result[i][k] * arr[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = cal[i][j] % 1000;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	long long p;
	int num;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			arr[i][j] = num;
			result[i][j] = num;
		}
	}


	while (p != 1) {
		if (p % 2 == 0) {
			p >>= 1;
			ord.push_back(0);
		}
		else {
			p--;
			ord.push_back(1);
		}
	}
	reverse(ord.begin(), ord.end());

	for (auto i : ord) {
		if (i == 0) {
			pow();
		}
		else {
			mul();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] % 1000 << " ";
		}
		cout << "\n";
	}

	return 0;
}
