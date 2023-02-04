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
const int MAX = 101;
deque <ll> arr[MAX];
ll use[MAX], num[MAX], cnt;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		arr[num[i]].push_back(i);
	}

	ll result = 0;
	for (int i = 1; i <= n; i++) {
		arr[num[i]].pop_front();
		if (use[num[i]]) continue;

		if (cnt == m) {
			ll M = 0, idx = 0;
			for (int j = 1; j <= n; j++) {
				if (!use[j]) {
					continue;
				}

				if (arr[j].empty()) {
					idx = j;
					break;
				}

				if (arr[j].front() > M) {
					M = arr[j].front();
					idx = j;
				}
			}

			result++;
			use[num[i]] = 1;
			use[idx] = 0;
		}		
		else {
			use[num[i]] = 1;
			cnt++;
		}
	}

	cout << result;
	

	return 0;
}