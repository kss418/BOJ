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
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010;
int dp[MAX][MAX];
int arr[MAX][MAX];
int result;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> y >> x;
	for (int i = 1; i <= y; i++) {
		cin >> s;
		for (int j = 0; j < x; j++) {
			arr[i][j + 1] = s[j] - '0';
			if (arr[i][j + 1]) {
				dp[i][j + 1] = 1;
			}
		}
	}

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j ++) {
			if (!arr[i][j]) {
				continue;
			}
			
			dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
			result = max(result, dp[i][j]);
		}
	}


	cout << result * result;

	return 0;
}