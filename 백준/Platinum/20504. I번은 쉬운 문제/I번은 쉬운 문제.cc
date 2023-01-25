#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
ll ord[MAX], seq = 1, scc = 1, num[MAX], indegree[MAX], cnt[MAX], ret;
bool finish[MAX];
stack <ll> list;
vector <ll> arr[MAX], cur, sccarr[MAX];
vector <vector <ll>> result;



ll dfs(int node) {
	ord[node] = seq++;
	list.push(node);
	ll ret = ord[node];
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
			ll top = list.top();
			list.pop();
			cur.push_back(top);
			finish[top] = 1;
			num[top] = scc;

			if (top == node) {
				sort(cur.begin(), cur.end());
				result.push_back(cur);
				cur.clear();
				break;
			}
		}

		scc++;
	}

	return ret;
}


void call(ll cur) {
	if (cnt[cur]) {
		return;
	}
	cnt[cur] = 1;

	for (auto nxt : sccarr[cur]) {
		call(nxt);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	ll st, en;
	while(m--) {
		cin >> st >> en;
		arr[st].push_back(en);
	}

	for (int i = 1; i <= n; i++) {
		if (!ord[i]) {
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (auto j : arr[i]) {
			if (num[j] != num[i]) {
				sccarr[num[i]].push_back(num[j]);
				indegree[num[j]]++;
			}
		}
	}

	cin >> k;
	while (k--) {
		int l;
		cin >> l;

		if (!cnt[num[l]] && !indegree[num[l]]) {
			call(num[l]);
			ret++;
		}
	}

	for (int i = 1; i < scc; i++) {
		if (!cnt[i]) {
			cout << -1;
			return 0;
		}
	}


	cout << ret;


	return 0;
}