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
const int MAX = 110;
int dp[32][MAX][MAX][MAX];
int a, b, c;


int dfs(int cur, int cura, int curb, int curc) {
	if (cura <= 0 && curb <= 0 && curc <= 0) {
		return 0;
	}

	if (dp[cur][cura][curb][curc] != -1) {
		return dp[cur][cura][curb][curc];
	}

	if (cur % 2 == 1) {
		int reta = 0, retb = 0, retc = 0;
		if (cura) reta = dfs(cur + 1, max(cura - cur, 0), curb, curc) + min(cura, cur);
		if (curb) retb = dfs(cur + 1, cura, max(curb - cur, 0), curc) + min(curb, cur);
 		if (curc) retc = dfs(cur + 1, cura, curb, max(curc - cur, 0)) + min(curc, cur);

		dp[cur][cura][curb][curc] = max({ reta,retb,retc });
	}
	else {
		int reta = 1e9, retb = 1e9, retc = 1e9;
		if (cura) reta = dfs(cur + 1, max(cura - cur, 0), curb, curc);
		if (curb) retb = dfs(cur + 1, cura, max(curb - cur, 0), curc);
		if (curc) retc = dfs(cur + 1, cura, curb, max(curc - cur, 0));

		dp[cur][cura][curb][curc] = min({ reta,retb,retc });
	}

	return dp[cur][cura][curb][curc];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;
	memset(dp, -1, sizeof(dp));
	int result = dfs(1, a, b, c);
	if (result * 2 > a + b + c) {
		cout << "F";
	}
	else if (result * 2 < a + b + c) {
		cout << "S";
	}
	else {
		cout << "D";
	}
	
	

	return 0;
}