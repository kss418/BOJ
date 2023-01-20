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
const int MAX = 11;
vector <int> arr; 
int cnt;

void bt(int num) {
	if (cnt == n) {
		return;
	}

	if (arr.size() == num) {
		cnt++;

		if (cnt == n) {
			for (auto i : arr) {
				cout << i;
			}
			cout << "\n";	
		}
		return;
	}


	for (int i = 0; i <= 9; i++) {
		if (!i && arr.empty()) {
			continue;
		}

		if (arr.size() >= 1 && arr[arr.size() - 1] <= i) {
			break;
		}
		arr.push_back(i);
		bt(num);
		arr.pop_back();
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= 10;i++){
		bt(i);
	}

	if (n != cnt) {
		cout << -1;
	}
	else if (n == 0) {
		cout << 0;
	}


	return 0;
}