#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 10101;
ll dp[MAX][MAX];
pll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll diff, st;
		cin >> diff >> st;
		arr[i] = { diff,st };
	}
	sort(arr + 1, arr + n + 1);
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ll diff = arr[j].first;
			ll st = arr[j].second;
			dp[i][j] = max(dp[i - 1][j - 1] + st + diff * (i - 1),dp[i][j - 1]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i][n] << "\n";
	}

	return 0;
}