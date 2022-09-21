#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string n;
long long dp[5001];
long long result = 0;
int mod = 1000000;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	dp[0] = 1;
	if (n[0] != '0') {
		dp[1] = 1;
	}
	else {
		dp[1] = 0;
	}

	for (int i = 1; i < n.size(); i++) {
		if (n[i] == '0') {
			if (n[i - 1] == '1' || n[i - 1] == '2') {
				dp[i + 1] = dp[i - 1] % mod;
			}

			else {
				cout << 0;
				return 0;
			}
		}

		else if (n[i - 1] == '1') {
			dp[i + 1] = (dp[i] % mod + dp[i - 1] % mod) % mod;
		}

		else if (n[i - 1] == '2') {
			if (n[i] == '6' || n[i] == '5' || n[i] == '4' || n[i] == '3' || n[i] == '2' || n[i] == '1') {
				dp[i + 1] = (dp[i] % mod + dp[i - 1] % mod) % mod;
			}
			else {
				dp[i + 1] = dp[i] % mod;
			}
		}

		else {
			dp[i + 1] = dp[i] % mod;
		}
	}

	cout << dp[n.size()] % mod;
	

	return 0;
}
