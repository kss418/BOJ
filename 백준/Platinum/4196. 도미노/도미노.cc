#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
stack <int> list;
vector <int> arr[100001];
int ord[100001];
int finish[100001];
int seq = 1;
int scc = 1;
int num[100001];
int indegree[100001];


int dfs(int node) {
	ord[node] = seq++;
	list.push(node);

	int ret = ord[node];

	for (int i : arr[node]) {
		if (!ord[i]) {
			ret = min(ret, dfs(i));
		}
		else if (!finish[i]) {
			ret = min(ret, ord[i]);
		}
	}

	if (ret == ord[node]) {
		while (1) {
			int top = list.top();
			list.pop();
			finish[top] = 1;
			num[top] = scc;
			if (top == node) {
				break;
			}
		}

		scc++;
	}

	return ret;
}

void init() {
	seq = 1;
	scc = 1;
	fill(finish, finish + 100000, 0);
	fill(num, num + 100000, 0);
	fill(ord, ord + 100000, 0);
	fill(indegree, indegree + 100000, 0);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	int st, en;
	int t;

	cin >> t;
	while (t--) {
		init();
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			arr[i].clear();
		}
		for (int i = 0; i < m; i++) {
			cin >> st >> en;
			arr[st].push_back(en);
		}

		for (int i = 1; i <= n; i++) {
			if (ord[i] == 0) {
				dfs(i);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j : arr[i]) {
				if (num[j] != num[i]) {
					indegree[num[j]]++;
				}
			}
		}

		int cnt = 0;
		for (int i = 1; i < scc; i++) {
			if (indegree[i] == 0) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}
