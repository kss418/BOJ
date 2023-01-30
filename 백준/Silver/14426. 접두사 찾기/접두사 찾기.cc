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
const int MAX = 501 * 10001;
int seq = 2, arr[MAX][26];


void insert(string a) {
	int cur = 1;
	for (auto st : a) {
		if (arr[cur][st - 'a'] == -1) {
			arr[cur][st - 'a'] = seq++;
		}
		cur = arr[cur][st - 'a'];
	}
}


bool find(string a) {
	int cur = 1;
	for (auto st : a) {
		if (arr[cur][st - 'a'] == -1) {
			return 0;
		}
		cur = arr[cur][st - 'a'];
	}

	return 1;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	memset(arr, -1, sizeof(arr));
	while (n--) {
		cin >> s;
		insert(s);
	}

	ll result = 0;
	while (m--) {
		cin >> s;
		result += find(s);
	}
	
	cout << result;

	return 0;
}