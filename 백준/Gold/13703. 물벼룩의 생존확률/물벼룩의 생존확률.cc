#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, st;
long long dp[64][130];
unsigned long long result = 0;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> st >> n;
	fill(&dp[0][0], &dp[63][130], 0);
	dp[0][st] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][2];

		for (int j = 2; j <= 127; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}

		if (st == 0 && i == 1) {
			dp[1][1] = 1;
		}
	}

	for (int i = 1; i <= 127; i++) {
		result += dp[n][i];
	}

    if(st == 0){
        cout << 0;
    }
    
    else if(n == 0){
        cout << 1;
    }
    
    else{
        cout << result;
    }


	return 0;
}
