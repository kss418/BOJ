#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[10001][3];
vector <int> arr;
int n, num;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[0][0] = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	dp[1][0] = 0;
	dp[1][1] = arr[0];
	dp[1][2] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
		dp[i][1] = dp[i - 1][0] + arr[i - 1];
		dp[i][2] = dp[i - 1][1] + arr[i - 1];
	}

	cout << max({ dp[n][0], dp[n][1], dp[n][2] });
	
	return 0;
}
