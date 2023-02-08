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
const int MAX = 1010101;
ll result, chk[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (ll i = 2; i * i <= m; i++) {
		for (ll j = (n / (i * i) + (bool)(n % (i * i))) * i * i; j <= m; j += i * i) chk[j - n + 1] = 1;
	}
	
	for (int i = 1; i <= m - n + 1; i++) if (!chk[i]) result++;
	cout << result;

	return 0;
}