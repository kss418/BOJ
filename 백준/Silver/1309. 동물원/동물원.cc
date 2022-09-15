#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001], s[100001];
int n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	dp[1] = 2;
	s[1] = 1;
	for (int i = 2; i <= n; i++) {
		s[i] = (s[i - 1] % 9901 + dp[i - 1] % 9901) % 9901;
		dp[i] = ((2 * s[i - 1]) % 9901 + dp[i - 1] % 9901) % 9901;
	}
	
	cout << (s[n] % 9901 + dp[n] % 9901) % 9901;
	

	return 0;
}
