#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, r, q, a, b, num;
int dp[100001] = {};
int v[100001] = {};
vector <int> arr[100001];


int dfs(int root) {
	int ret = 1;
	v[root] = 1;

	for (auto i : arr[root]) {
		if (v[i] == 0) {
			ret += dfs(i);
		}
	}

	return dp[root] = ret;
}



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a); 
	}

	dfs(r);

	while(q--) {
		cin >> num;
		cout << dp[num] << "\n";
	}

	return 0;
}
