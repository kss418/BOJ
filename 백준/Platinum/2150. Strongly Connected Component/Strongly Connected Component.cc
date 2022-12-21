#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
int n, m;
vector <int> arr[10001];
int ord[10001];
int finish[10001];
int seq = 1;
stack <int> list;
vector <vector <int>> result;
vector <int> cur;

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
			cur.push_back(top);
			finish[top] = 1;
			if (top == node) {
				sort(cur.begin(), cur.end());
				result.push_back(cur);
				cur.clear();
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

	cin >> n >> m;
	int st, en;
	for (int i = 0; i < m; i++) {
		cin >> st >> en;
		arr[st].push_back(en);
	}

	for (int i = 1; i <= n; i++) {
		if (ord[i] == 0) {
			dfs(i);
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (auto i : result) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << -1 << "\n";
	}
	




	return 0;
}


