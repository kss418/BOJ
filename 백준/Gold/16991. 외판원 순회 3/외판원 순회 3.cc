#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;
int n, x, y;
double dp[16][1 << 16];
vector <pair<int, int>> arr;


double dfs(int cur,int visit) {;
	if (dp[cur][visit] != -1) {
		return dp[cur][visit];
	}


	if (visit == (1 << n) - 1) {
		int curx = abs(arr[0].first - arr[cur].first);
		int cury = abs(arr[0].second - arr[cur].second);
		double dist = sqrt(curx * curx + cury * cury);

		return dist;
	}


	dp[cur][visit] = 1e9;
	for (int i = 0; i < n; i++) {
		if (visit & (1 << i)) {
			continue;
		}
		int curx = abs(arr[i].first - arr[cur].first);
		int cury = abs(arr[i].second - arr[cur].second);
		double dist = sqrt(curx * curx + cury * cury);
		dp[cur][visit] = min(dp[cur][visit], dfs(i, visit | (1 << i)) + dist);
	}


	return dp[cur][visit];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;

	cout.precision(8);
	fill(&dp[0][0], &dp[15][1 << 16], -1);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back({ x,y });
	}

	cout << dfs(0, 1 << 0);


	return 0;
}
