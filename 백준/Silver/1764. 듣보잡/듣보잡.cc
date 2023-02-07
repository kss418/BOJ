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
const int MAX = 12;
map <string, ll> arr;
vector <string> result;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (n--) {
		cin >> s;
		arr[s] = 1;
	}

	while (m--) {
		cin >> s;
		if (arr.find(s) != arr.end()) {
			result.push_back(s);
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (auto i : result) {
		cout << i << "\n";
	}
	

	return 0;
}