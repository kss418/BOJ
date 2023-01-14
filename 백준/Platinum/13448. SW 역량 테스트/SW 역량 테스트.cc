#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 51;
ll M[MAX], P[MAX], R[MAX], dp[MAX][101010];
vector <int> num;

bool cmp(int a,int b) {
	return R[a] * P[b] < P[a] * R[b];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int ti;
	cin >> n >> ti;
	for (int i = 1; i <= n; i++) {
		cin >> M[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> P[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> R[i];
	}

	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}
	sort(num.begin(), num.end(), cmp);

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= ti; j++) {
			if (j >= R[num[i - 1]]) {
				dp[i][j] = max(dp[i - 1][j - R[num[i - 1]]] + M[num[i - 1]] - j * P[num[i - 1]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	ll result = 0;
	for (int i = 0; i <= ti; i++) {
		result = max(result, dp[n][i]);
	}

	cout << result;
	
	return 0;
}