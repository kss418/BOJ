#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010101;
int sum[MAX][22][2], arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		for (int j = 0; j < 22; j++) {
			ll cur = 1 << j;
			int bit = (arr[i] & cur) >> j;
			sum[i][j][bit] = sum[i - 1][j][bit] + 1;
			sum[i][j][bit ^ 1] = sum[i - 1][j][bit ^ 1];
		}
	}

	ll result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 22; j++) {
			ll cur = 1 << j;
			int bit = (arr[i] & cur) >> j;
			result += cur * (ll)(sum[n][j][bit ^ 1] - sum[i][j][bit ^ 1]);
		}
	}

	
	cout << result;

	return 0;
}