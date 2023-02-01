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
const int MAX = 50101;
vector <int> result;
int fail[MAX];
string a, b, table;
int code[300];


void f(string s) {
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = fail[j - 1];
		}

		if (s[i] == s[j]) {
			fail[i] = ++j;
		}
	}
}

bool kmp(string s, string t) {
	int ret = 0;
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != t[j]) {
			j = fail[j - 1];
		}

		if (s[i] == t[j]) {
			j++;
		}

		if (j == t.size()) {
			ret++;
			j = fail[j - 1];
			if (ret >= 2) {
				return 0;
			}
		}
	}

	if (ret) {
		return 1;
	}
	return 0;
}

string init(string s) {
	for (int i = 0; i < s.size(); i++) {
		s[i] = table[(code[(int)s[i]] + 1) % table.size()];
	}

	return s;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> t;
	while (t--) {
		result.clear();
		cin >> table >> a >> b;
		for (int i = 0; i < table.size(); i++) {
			code[(int)table[i]] = i;
		}

		f(a);
		for (int i = 1; i <= table.size(); i++) {
			a = init(a);
			if (kmp(b, a)) {
				result.push_back(i % table.size());
			}
		}

		if (!result.size()) {
			cout << "no solution\n";
		}
		else if (result.size() == 1) {
			cout << "unique: " << result[0] << "\n";
		}
		else {
			sort(result.begin(), result.end());
			cout << "ambiguous: ";
			for (auto i : result) {
				cout << i << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}