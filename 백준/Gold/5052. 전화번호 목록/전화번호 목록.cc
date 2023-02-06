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
const int MAX = 11 * 10101;
int seq, arr[MAX][12], chk[MAX], flag;
string st[10101];


void insert(string a) {
	int cur = 1;
	for (auto st : a) {
		if (chk[cur]) {
			flag = 1;
		}

		if (arr[cur][st - '0'] == -1) {
			arr[cur][st - '0'] = seq++;
		}
		cur = arr[cur][st - '0'];
	}
	chk[cur] = 1;
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


bool cmp(string a, string b) {
	return a.size() < b.size();
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		memset(arr, -1, sizeof(arr));
		memset(chk, 0, sizeof(chk));
		seq = 2;
		flag = 0;

		for (int i = 1; i <= n; i++) {
			cin >> st[i];
		}
		sort(st + 1, st + n + 1, cmp);
		for(int i = 1; i <= n;i++){
			insert(st[i]);
		}

		if (flag) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}


	return 0;
}