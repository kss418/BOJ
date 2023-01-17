#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;
vector <pi> arr;
bool v[MAX];

bool cmp(pi a, pi b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

bool flag;
int cnt;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;
		arr.push_back({ st,en });
	}
	sort(arr.begin(), arr.end(), cmp);

	int en = 0;
	for (auto i : arr) {
		if (i.first >= en) {
			en = i.second;
			cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}