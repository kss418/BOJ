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
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 33;
int arr[MAX], cnt, cur;
vector <int> result;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		cnt = n;
		result.clear();
		for (int i = 1; i <= n; i++) cin >> arr[i];

		while (cnt != 1) {
			for (int i = 1; i <= n; i++) {
				if (arr[i] == cnt) {
					cur = i;
					break;
				}
			}

			if (cnt != cur && cur != 1) {
				reverse(arr + 1, arr + cur + 1);
				reverse(arr + 1, arr + cnt + 1);
				result.push_back(cur);
				result.push_back(cnt);
			}
			else if (cur == 1) {
				reverse(arr + 1, arr + cnt + 1);
				result.push_back(cnt);
			}
			cnt--;
		}

		cout << result.size() << " ";
		for (auto i : result) {
			cout << i << " ";
		}
		cout << "\n";
	}



	return 0;
}