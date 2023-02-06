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
ll arr[MAX], sum[MAX];
map <ll, ll> q;
vector <ll> pro;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	q[0] = 1;
	pro.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] -= m;
		sum[i] = sum[i - 1] + arr[i];

		if (q.find(sum[i]) == q.end()) {
			q[sum[i]] = 1;
			pro.push_back(sum[i]);
		}
		else {
			q[sum[i]]++;
		}
	}
	
	ll result = 0;
	for (auto i : pro) {
		result += (q[i] * (q[i] - 1)) / 2;
	}

	cout << result;

	return 0;
}