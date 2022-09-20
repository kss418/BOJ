#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int mod = 1000000007;
long long dp1[1000000];
long long dp2[1000000];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	dp1[0] = 1;
	dp1[1] = 2;
	dp1[2] = 7;
	dp2[2] = 0;


	for (int i = 3; i <= n; i++) {
		dp2[i] = ((dp2[i - 1] % mod) + (dp1[i - 3] % mod)) % mod;
		dp1[i] = ((dp1[i - 1] * 2) % mod + (dp1[i - 2] * 3) % mod) % mod;
		dp1[i] += 2 * dp2[i] % mod;
	}

	cout << dp1[n] % mod;


	return 0;
}
