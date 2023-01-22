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
const int MAX = 2101;
int dp[MAX][MAX], arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		int pre = i - 1;
		int nxt = i + 1;
		while (1) {
			if (pre < 1 || nxt > n) {
				break;
			}

			if (arr[pre] != arr[nxt]) {
				break;
			}

			dp[pre][nxt] = 1;
			pre--;
			nxt++;
		}

		if (arr[i] != arr[i - 1]) {
			continue;
		}
		dp[i - 1][i] = 1;

		pre = i - 2;
		nxt = i + 1;
		while (1) {
			if (pre < 1 || nxt > n) {
				break;
			}

			if (arr[pre] != arr[nxt]) {
				break;
			}

			dp[pre][nxt] = 1;
			pre--;
			nxt++;
		}
	}


	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (dp[a][b]) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	


	return 0;
}