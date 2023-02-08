#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101;
ll arr[MAX], num[MAX];
multiset <ll> result;
set <ll> output;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for (int i = 2; i <= n; i++) arr[i] -= arr[1];

	for (int i = 2; i <= n; i++) {
		ll cur = arr[i];
		result.insert(arr[i]);
		for (int j = 2; j * j <= arr[i]; j++) {
			if (arr[i] % j) continue;
			if (j * j == arr[i]) {
				result.insert(j);
				continue;
			}

			result.insert(arr[i] / j);
			result.insert(j);
		}
	}

	for (auto i : result) {
		if (result.count(i) == n - 1) output.insert(i);
	}
	
	for (auto i : output) cout << i << " ";
	

	return 0;
}