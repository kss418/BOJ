#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long dp1[31], dp2[31];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= 29; i += 2) {
		dp1[i] = 0;
	}

	dp1[0] = 1;
	dp1[2] = 3;
	dp2[2] = 0;

	for (int i = 4; i <= 30; i += 2) {
		dp2[i] = dp2[i - 2] + dp1[i - 4];
		dp1[i] = dp1[i - 2] * 3 + dp2[i] * 2;
	}

	cout << dp1[n];

	return 0;
}
