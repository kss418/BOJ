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
const int MAX = 201010;
pll arr[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr + 1, arr + n + 1);
	
	ll result = 0;
	for (int i = 1; i <= n; i++) {
		while (!pq.empty() && pq.top() <= arr[i].first) {
			pq.pop();
		}
		pq.push(arr[i].second);
		result = max(result, (ll)pq.size());
	}

	cout << result;


	return 0;
}