#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101;
vector <int> result;
set <int> able;
int ma = 0;


void bt(int n) {
	if (result.size() == n - 1) {	
		int cur = 0;
		int cnt = 1;
		for (int i = n - 2; i >= 0; i--) {
			cur += (s[i + 1] - '0') * cnt;
			if (result[i] == 0) {
				cnt = 1;
			}
			else {
				cnt *= 10;
			}
		}
		cur += (s[0] - '0') * cnt;
		able.insert(cur);
		ma = max(ma, cur);
		return;
	}

	for (int i = 0; i <= 1; i++) {
		result.push_back(i);
		bt(n);
		result.pop_back();
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> s;
		able.clear();
		result.clear();
		ma = 0;

		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1' || s[i] == '0') {
				cnt++;
			}
		}

		if (cnt == s.size()) {
			cout << "Hello, BOJ 2023!" << "\n";
			continue;
		}
		
		bt(s.size());

		int result = 1;
		int cur = 2;
		while (1) {
			int value = 0;
			for (int i = 0; i < s.size(); i++) {
				int curr = 1;
				for (int j = 1; j <= cur; j++) {
					curr *= s[i] - '0';
				}
				value += curr;
			}
			
			if (able.find(value) != able.end()) {
				result++;
			}

			if (value > ma) {
				break;
			}
			cur++;
		}
		cout << result << "\n";
	}


	return 0;
}