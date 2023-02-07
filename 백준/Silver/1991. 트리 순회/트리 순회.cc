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
const int MAX = 27;
ll fi[MAX], se[MAX];

void pre(ll cur) {
	cout << (char)(cur + 'A' - 1);
	if (fi[cur]) {
		pre(fi[cur]);
	}

	if (se[cur]) {
		pre(se[cur]);
	}
}

void in(ll cur) {
	if (fi[cur]) {
		in(fi[cur]);
	}

	cout << (char)(cur + 'A' - 1);
	if (se[cur]) {
		in(se[cur]);
	}
}

void post(ll cur) {
	if (fi[cur]) {
		post(fi[cur]);
	}

	if (se[cur]) {
		post(se[cur]);
	}
	cout << (char)(cur + 'A' - 1);
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string st, en1, en2;
		cin >> st >> en1 >> en2;
		if (en1[0] != '.') {
			fi[st[0] - 'A' + 1] = en1[0] - 'A' + 1;
		}
		
		if (en2[0] != '.') {
			se[st[0] - 'A' + 1] = en2[0] - 'A' + 1;
		}
	}


	pre(1);
	cout << "\n";
	in(1);
	cout << "\n";
	post(1);


	return 0;
}