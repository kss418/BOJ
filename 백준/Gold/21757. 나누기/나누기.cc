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
const int MAX = 101010;
ll arr[MAX], sum[MAX], dp[MAX][4];



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}

	if (sum[n] % 4) {
		cout << 0;
		return 0;
	}

	dp[0][0] = 1;
	ll mod = sum[n] / 4;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 3; j++) {
			dp[i][j] = dp[i - 1][j];
			if (sum[i] == mod * j) {
				dp[i][j] += dp[i - 1][j - 1];
			}
		}
	}

	cout << dp[n][3];

	

	return 0;
}