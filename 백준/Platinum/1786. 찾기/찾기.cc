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
vector <int> result;
int fail[MAX];


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


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string a;
	getline(cin, a);
	getline(cin, s);
	f(s);

	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		while (j > 0 && a[i] != s[j]) {
			j = fail[j - 1];
		}

		if (a[i] == s[j]) {
			j++;
		}

		if (j == s.size()) {
			result.push_back(i - j + 1);
			j = fail[j - 1];
		}
	}

	cout << result.size() << "\n";
	for (auto i : result) {
		cout << i + 1 << " ";
	}
	
	return 0;
}