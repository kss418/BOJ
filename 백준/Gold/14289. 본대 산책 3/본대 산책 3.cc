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
const ll MOD = 1000000007;
const int MAX = 51;
ll result[MAX][MAX], cal[MAX][MAX], arr[MAX][MAX];
vector <ll> ord;


void pow() {
	memset(cal, 0, sizeof(cal));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cal[i][j] += (result[i][k] % MOD * result[k][j] % MOD) % MOD;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			result[i][j] = cal[i][j] % MOD;
		}
	}
}

void mul() {
	memset(cal, 0, sizeof(cal));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cal[i][j] += (result[i][k] % MOD * arr[k][j] % MOD) % MOD;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			result[i][j] = cal[i][j] % MOD;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
		result[a][b] = 1;
		result[b][a] = 1;
	}
	cin >> k;


	while (k != 1) {
		if (k % 2 == 1) {
			k--;
			ord.push_back(1);
		}
		else {
			k /= 2;
			ord.push_back(0);
		}
	}

	reverse(ord.begin(), ord.end());
	for (auto i : ord) {
		if (i) {
			mul();
		}
		else {
			pow();
		}
	}

	cout << result[1][1] % MOD;



	return 0;
}