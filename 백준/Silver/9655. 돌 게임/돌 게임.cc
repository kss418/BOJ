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

const int MAX = 1010;
int dp[MAX];
deque <pair <int, int>> q;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	q.push_back({ 0,0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int value = q.front().second;
		q.pop_front();
		
		if (dp[cur] != -1 || cur > n) {
			continue;
		}
		dp[cur] = value;

		for (auto nxt : { cur + 1, cur + 3 }) {
			q.push_back({ nxt,value ^ 1 });
		}
	}
	
	
	if (dp[n]) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}


	return 0;
}