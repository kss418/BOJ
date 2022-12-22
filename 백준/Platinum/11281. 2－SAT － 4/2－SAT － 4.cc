#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
vector <int> arr[20001];
vector <int> cur;
vector <vector<int>> result;
int ord[20001], finish[20001], num[20001], indegree[20001], value[20001];
int seq = 1;
int scc = 1;
stack <int> list;
vector <int> sccarr[20001];


int dfs(int node) {
	ord[node] = seq++;
	list.push(node);

	int ret = ord[node];
	for (auto i : arr[node]) {
		if (ord[i] == 0) {
			ret = min(ret, dfs(i));
		}
		else if (finish[i] == 0) {
			ret = min(ret, ord[i]);
		}
	}

	if (ret == ord[node]) {
		while (1) {
			int top = list.top();
			list.pop();
			finish[top] = 1;
			num[top] = scc;
			cur.push_back(top);
			if (top == node) {
				result.push_back(cur);
				cur.clear();
				break;
			}
		}
		scc++;
	}

	return ret;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	fill(value, value + 20001, -1);
	int n, m;
	int st, en;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> st >> en;
		if (st < 0 && en < 0) {
			arr[-st].push_back(10000 - en);
			arr[-en].push_back(10000 - st);
		}
		else if (st < 0) {
			arr[-st].push_back(en);
			arr[10000 + en].push_back(10000 - st);
		}
		else if (en < 0) {
			arr[10000 + st].push_back(10000 - en);
			arr[-en].push_back(st);
		}
		else {
			arr[10000 + st].push_back(en);
			arr[10000 + en].push_back(st);
		}
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
	for (auto i : result) {
		if (!flag) {
			break;
		}

		int ne[20001] = {};
		for (int j : i) {
			ne[j] = 1;
			if (j > 10000 && ne[j - 10000] == 1) {
				flag = 0;
				break;
			}

			if (j <= 10000 && ne[j + 10000] == 1) {
				flag = 0;
				break;
			}
		}
	}

	cout << flag << "\n";
	if (!flag) {
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (auto j : arr[i]) {
			if (num[j] != num[i]) {
				sccarr[num[i]].push_back(num[j]);
				indegree[num[j]]++;
			}
		}
	}

	for (int i = 10001; i <= 10000 + n; i++) {
		for (auto j : arr[i]) {
			if (num[j] != num[i]) {
				sccarr[num[i]].push_back(num[j]);
				indegree[num[j]]++;
			}
		}
	}

	queue <int> q;
	for (int i = 1; i < scc; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto j : result[curr - 1]) {
			if (value[j] == -1) {
				value[j] = 0;
				if (j <= 10000) {
					value[j + 10000] = 1;
				}
				else {
					value[j - 10000] = 1;
				}
			}
		}

		for (auto i : sccarr[curr]) {
			indegree[i]--;
			if (!indegree[i]) {
				q.push(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << value[i] << " ";
	}

	return 0;
}


