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
const int MAX = 1010;
ll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	ll cur = arr[1], idx = 2, result = 1;

	while (1) {
		if (idx > n) {
			break;
		}

		if (cur + m <= arr[idx]) {
			cur = arr[idx];
			result++;
		}

		idx++;
	}

	cout << result;
	

	return 0;
}