#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num, cur;
vector <int> arr;
long long n;
long long int dp[103][22];



int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	fill(&dp[0][0], &dp[102][22], 0);
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	dp[1][arr[0]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			cur = j + arr[i - 1];
			if (cur >= 0 && cur <= 20) {
				dp[i][cur] += dp[i - 1][j];
			}

			cur = j - arr[i - 1];
			if (cur >= 0 && cur <= 20) {
				dp[i][cur] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 1][arr[n - 1]];


	return 0;
}
