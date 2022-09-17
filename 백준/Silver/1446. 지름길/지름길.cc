#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int n, k, st, en, cost;
int dp[10001];
vector <tuple <int, int, int>> road;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 0;
	cin >> n >> k;
	while (n--) {
		cin >> st >> en >> cost;
		road.push_back({ en, st, cost });
	}
	sort(road.begin(), road.end());

	for (int i = 1; i <= k; i++) {
		dp[i] = dp[i - 1] + 1;
		for (auto j : road) {
			tie(en, st, cost) = j;
			if (i == en) {
				dp[en] = min(dp[st] + cost, dp[en]);
			}
		}
	}

	cout << dp[k];

	return 0;
}
