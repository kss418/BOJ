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

const int MAX = 510;
int arr[MAX][MAX], dp[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct node {
	int v;
	int x;
	int y;
};

struct cmp {
	bool operator()(node a,node b) {
		return a.v > b.v;
	}
};

priority_queue <node, vector<node>, cmp> pq;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			pq.push({ arr[i][j],j,i });
		}
	}

	int result = 0;
	while (!pq.empty()) {
		int cur = pq.top().v;
		int curx = pq.top().x;
		int cury = pq.top().y;
		pq.pop();

		dp[cury][curx] = 1;
		for (int i = 0; i < 4; i++) {
			int nxtx = curx + dx[i];
			int nxty = cury + dy[i];

			if (nxtx <= 0 || nxty <= 0 || nxtx > n || nxty > n) {
				continue;
			}

			if (!dp[nxty][nxtx] || arr[nxty][nxtx] >= arr[cury][curx]) {
				continue;
			}

			dp[cury][curx] = max(dp[cury][curx],dp[nxty][nxtx] + 1);
		}

		result = max(result, dp[cury][curx]);
	}
	
	cout << result;

	

	return 0;
}