#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 5000011;
const int MOD = 1000000007;
ll arr[2][2], result[2][2], cal[2][2];

void init() {
	memset(arr, 0, sizeof(arr));
	memset(result, 0, sizeof(arr));
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 0;
	result[0][0] = 1;
	result[0][1] = 1;
	result[1][0] = 1;
	result[1][1] = 0;
}

void pow() {
	memset(cal, 0, sizeof(cal));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cal[i][j] += result[i][k] * result[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = cal[i][j] % MOD;
		}
	}
}

void mul() {
	memset(cal, 0, sizeof(cal));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cal[i][j] += result[i][k] * arr[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = cal[i][j] % MOD;
		}
	}
}

ll fib(ll a) {
	init();
	vector <bool> ord;
	while (a != 1) {
		if (a % 2 == 0) {
			ord.push_back(0);
			a >>= 1;
		}
		else {
			ord.push_back(1);
			a--;
		}
	}
	reverse(ord.begin(), ord.end());

	for (auto i : ord) {
		if (i == 0) {
			pow();
		}
		else {
			mul();
		}
	}

	return result[1][0] % MOD;
}

tuple <ll, ll, ll> gcd(ll a, ll b) {
	if (!b) return { a,1,0 };
	ll g, x, y;
	tie(g, x, y) = gcd(b, a % b);
	return { g,y,x - a / b * y };
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	n = 2;
	cin >> m >> k;
	cout << fib(get<0>(gcd(m, k))) % MOD;


	return 0;
}