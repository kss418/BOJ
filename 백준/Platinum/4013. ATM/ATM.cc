#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
stack <int> list;
vector <int> arr[500001], sccarr[500001];
int ord[500001], finish[500001], num[500001], value[500001], visit[500001], res[500001], indegree[500001], able[500001], maxv[500001];
int seq = 1, scc = 1;



int dfs(int node) {
	ord[node] = seq++;
	list.push(node);
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



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m;i++){
		int st, en;
		cin >> st >> en;
		arr[st].push_back(en);
	}

	for (int i = 1; i <= n; i++) {
		if (!ord[i]) {
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		int number;
		cin >> number;
		value[num[i]] += number;
	}

	int start, k;
	cin >> start >> k;
	start = num[start];

	for(int i = 0;i < k;i++){
		int number;
		cin >> number;
		res[num[number]] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (auto j : arr[i]) {
			if (num[j] != num[i]) {
				sccarr[num[i]].push_back(num[j]);
				indegree[num[j]]++;
			}
		}
	}

	
	queue <int> q;
	for (int i = 1; i < scc; i++) {
		maxv[i] = value[i];
		if (i == start) {
			able[i] = 1;
		}

		if (!indegree[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : sccarr[cur]) {
			if (able[cur]) {
				maxv[i] = max(maxv[i], maxv[cur] + value[i]);
				able[i] = 1;
			}
			
			indegree[i]--;
			if (!indegree[i]) {
				q.push(i);
			}
		}
	}

	int re = 0;
	for (int i = 1; i < scc; i++) {
		if (res[i] && able[i]) {
			re = max(re, maxv[i]);
		}
	}

	cout << re;

	

	return 0;
}
