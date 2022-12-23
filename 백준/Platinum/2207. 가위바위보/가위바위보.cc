#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
vector <int> arr[20001];
int ord[20001], finish[20001];
stack <int> list;
vector <vector<int>> scc;
int seq = 1;


int oppo(int n) {
	if (n > 10000) {
		return n - 10000;
	}
	else {
		return n + 10000;
	}
}

int dfs(int node) {
	list.push(node);
	ord[node] = seq++;

	int ret = ord[node];
	for (auto i : arr[node]) {
		if (!ord[i]) {
			ret = min(ret, dfs(i));
		}
		else if (!finish[i]) {
			ret = min(ret, ord[i]);
		}
	}

	if (ret == ord[node]) {
		vector <int> cur;
		while (1) {
			int top = list.top();
			list.pop();
			finish[top] = 1;
			cur.push_back(top);
			if (node == top) {
				scc.push_back(cur);
				break;
			}
		}
	}

	return ret;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 0) {
			a = -a + 10000;
		}

		if (b < 0) {
			b = -b + 10000;
		}

		arr[oppo(b)].push_back(a);
		arr[oppo(a)].push_back(b);
	}
	
	for (int i = 1; i <= n; i++) {
		if (ord[i] == 0) {
			dfs(i);
		}
	}

	for (int i = 10001; i <= 10000 + n; i++) {
		if (ord[i] == 0) {
			dfs(i);
		}
	}

	int flag = 1;
	for (auto i : scc) {
		int num[20001] = {};
		if (!flag) {
			break;
		}

		for (auto j : i) {
			num[j] = 1;
			if (num[oppo(j)] == 1) {
				flag = 0;
				break;
			}
		}
	}

	if (flag) {
		cout << "^_^";
	}
	else {
		cout << "OTL";
	}




	return 0;
}


