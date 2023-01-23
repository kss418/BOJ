#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 55;
const ll MOD = 1000007;
ll dp[MAX][MAX][MAX][MAX], arr[MAX][MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> y >> x;
		arr[y][x] = i;
	}


	if (!arr[1][1]) {
		dp[1][1][0][0] = 1;
	}
	else {
		dp[1][1][arr[1][1]][1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(i == 1 && j == 1){
				continue;
			}

			if (arr[i][j]) {
				for (int k = 0; k < arr[i][j]; k++) {
					for (int l = 1; l <= 50; l++) {
						dp[i][j][arr[i][j]][l] += (dp[i - 1][j][k][l - 1] % MOD+ dp[i][j - 1][k][l - 1] % MOD) % MOD;
					}
				}
			}
			else {
				for (int k = 0; k <= 50; k++) {
					for (int l = 0; l <= 50; l++) {
						dp[i][j][k][l] = (dp[i - 1][j][k][l] % MOD + dp[i][j - 1][k][l] % MOD) % MOD;
					}
				}
			}
		}
	}

	for (int i = 0; i <= k; i++) {
		ll cur = 0;
		for (int j = 0; j <= 50; j++) {
			cur += dp[n][m][j][i];
		}
		cout << cur % MOD << " ";
	}


	return 0;
}