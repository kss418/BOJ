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



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> s;

	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j && s[i] != s[j]) j = fail[j - 1];
		if (s[i] == s[j]) fail[i] = ++j;
	}

	cout << n - fail[n - 1];
	

	return 0;
}