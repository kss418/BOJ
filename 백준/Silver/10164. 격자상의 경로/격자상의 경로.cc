#include <iostream>
#include <cmath>
using namespace std;
int x, y, k, prex;
double prey;

long long per(int x1,int y1) {
	long long dp[20][20];
	for (int i = 1; i <= x1; i++) {
		dp[1][i] = 1;
	}

	for (int i = 1; i <= y1; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= y1; i++) {
		for (int j = 2; j <= x1; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	return dp[y1][x1];
}


int main(){
	cin >> y >> x >> k;
	if (k == 0 || k == 1) {
		cout << per(x, y);
	}

	else if (k % x == 0) {
		cout << per(x, k / x);
	}

	else {
		prex = k % x;
		prey = ceil(static_cast<double>(k) / x);
		cout << per(prex, prey) * per(x - prex + 1, y - prey + 1);
	} 

	return 0;
}
