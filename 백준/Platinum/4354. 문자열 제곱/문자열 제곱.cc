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
const int MAX = 1010101;
int fail[MAX];

void f(string s) {
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j && s[i] != s[j]) j = fail[j - 1];
		if (s[i] == s[j]) fail[i] = ++j;
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> s;
		if (s[0] == '.') {
			break;
		}

		memset(fail, 0, sizeof(fail));
		f(s);
		if (!(s.size() % (s.size() - fail[s.size() - 1]))) {
			cout << s.size() / (s.size() - fail[s.size() - 1]) << "\n";
		}
		else {
			cout << 1 << "\n";
		}
	}

	return 0;
}