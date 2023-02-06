#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 55;
vector <ll> arr[MAX];
ll result, del;


void dfs(ll cur) {
	if (cur == del) {
		return;
	}

	for (auto nxt : arr[cur]) {
		dfs(nxt);
	}

	if (!arr[cur].size() || (arr[cur].size() == 1 && arr[cur][0] == del)) {
		result++;
	}
}


int main() {
	cin.tie(0); 
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	ll r = -1;
	for (int i = 0; i < n; i++) {
		ll st;
		cin >> st;
		if (st == -1) {
			r = i; 
			continue;
		}
		arr[st].push_back(i);
	}
	cin >> del;

	dfs(r);
	cout << result;
	

	return 0;
}