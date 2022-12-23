#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
vector <int> arr[2001];
int ord[2001], finish[2001];
stack <int> list;
vector <vector<int>> scc;
int seq = 1;


int oppo(int n) {
	if (n > 1000) {
		return n - 1000;
	}
	else {
		return n + 1000;
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

void init() {
	fill(ord, ord + 2001, 0);
	fill(finish, finish + 2001, 0);
	for (int i = 0; i < 2001; i++) {
		arr[i].clear();
	}
	scc.clear();
	seq = 1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	while (cin >> n >> m) {
		init();
		arr[1001].push_back(1);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (a < 0) {
				a = -a + 1000;
			}

			if (b < 0) {
				b = -b + 1000;
			}

			arr[oppo(b)].push_back(a);
			arr[oppo(a)].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (ord[i] == 0) {
				dfs(i);
			}
		}

		for (int i = 1001; i <= 1000 + n; i++) {
			if (ord[i] == 0) {
				dfs(i);
			}
		}

		int flag = 1;
		for (auto i : scc) {
			int num[2001] = {};
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
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}






	return 0;
}


