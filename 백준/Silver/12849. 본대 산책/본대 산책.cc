#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[100001][8];
vector <int> arr[8];
int n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	dp[0][0] = 1;
	arr[0].push_back(1);
	arr[0].push_back(2);

	arr[1].push_back(0);
	arr[1].push_back(2);
	arr[1].push_back(3);

	arr[2].push_back(0);
	arr[2].push_back(1);
	arr[2].push_back(3);
	arr[2].push_back(4);

	arr[3].push_back(1);
	arr[3].push_back(2);
	arr[3].push_back(4);
	arr[3].push_back(5);

	arr[4].push_back(2);
	arr[4].push_back(3);
	arr[4].push_back(5);
	arr[4].push_back(6);

	arr[5].push_back(3);
	arr[5].push_back(4);
	arr[5].push_back(7);

	arr[6].push_back(4);
	arr[6].push_back(7);

	arr[7].push_back(5);
	arr[7].push_back(6);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 7; j++) {
			for (auto k : arr[j]) {
				dp[i][j] += dp[i - 1][k] % 1000000007;
			}
			dp[i][j] %= 1000000007;
		}
	}

	cout << dp[n][0];

	return 0;
}
