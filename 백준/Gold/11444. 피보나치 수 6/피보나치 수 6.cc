#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long arr[2][2], result[2][2], cal[2][2];
int n = 2;
const int mod = 1000000007;

void pow() {
	fill(&cal[0][0], &cal[1][2], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cal[i][j] += result[i][k] * result[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = cal[i][j] % mod;
		}
	}
}

void mul() {
	fill(&cal[0][0], &cal[1][2], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cal[i][j] += result[i][k] * arr[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = cal[i][j] % mod;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	long long num;
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 0;
	result[0][0] = 1;
	result[0][1] = 1;
	result[1][0] = 1;
	result[1][1] = 0;
	cin >> num;

	vector <bool> ord;
	while (num != 1) {
		if (num % 2 == 0) {
			ord.push_back(0);
			num >>= 1;
		}
		else {
			ord.push_back(1);
			num--;
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

	cout << result[1][0] % mod;
	
	return 0;
}
