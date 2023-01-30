#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 15 * 15 * 1010;
int seq = 2;
map <string, int> arr[MAX];


void insert(vector <string> a) {
	int cur = 1;
	for (auto st : a) {
		if (arr[cur].find(st) == arr[cur].end()) {
			arr[cur][st] = seq++;
		}
		cur = arr[cur][st];
	}
}

void dfs(int cur, int cnt) {
	for (auto nxt : arr[cur]) {
		for (int i = 1; i <= cnt; i++) {
			cout << "--";
		}
		cout << nxt.first << "\n";

		dfs(nxt.second, cnt + 1);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> m;
		vector <string> cur;
		for (int j = 1; j <= m; j++) {
			cin >> s;
			cur.push_back(s);
		}
		insert(cur);
	}

	dfs(1, 0);


	return 0;
}