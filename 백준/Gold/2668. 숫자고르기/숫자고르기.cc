#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 101;
int arr[MAX]; bool finish[MAX], v[MAX];
vector <int> result, path;

void dfs(int cur) {
	if (v[cur] && !finish[cur]) {
		while (path.back() != cur) {
			result.push_back(path.back());
			finish[path.back()] = 1;
			path.pop_back();
		}
		result.push_back(path.back());
		finish[path.back()] = 1;
		path.pop_back();

		for (auto i : path) {
			finish[i] = 1;
		}

		path.clear();
		return;
	}
	else if (finish[cur]) {
		path.clear();
		return;
	}

	v[cur] = 1;
	path.push_back(cur);
	dfs(arr[cur]);
	v[cur] = 0;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!finish[i]) {
			dfs(arr[i]);
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (auto i : result) {
		cout << i << "\n";
	}

	return 0;
}