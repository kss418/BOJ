#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 102;
int orig[MAX], ord[MAX];bool use[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		fill(use, use + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> ord[i];
		}
		
		int flag = 0;
		for (int i = n; i >= 1; i--) {
			int cnt = 0;
			flag = 0;
			for (int j = 1; j <= n; j++) {
				if (!use[j] && cnt == ord[i]) {
					orig[i] = j;
					flag = 1;
					use[j] = 1;
					break;
				}
				else if(!use[j]) {
					cnt++;
				}
			}

			if (!flag) {
				cout << "IMPOSSIBLE" << "\n";
				break;
			}
		}

		if (!flag) {
			continue;
		}
		else {
			for (int i = 1; i <= n; i++) {
				cout << orig[i] << " ";
			}
			cout << "\n";
		}
	}
	
	
	return 0;
}

