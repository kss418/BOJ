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
const int MAX = 5;
ll x[MAX], y[MAX];


ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) { 
	ll cur = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1); 

	if (cur > 0) return 1;
	else if (cur == 0) return 0;
	else return -1;
}

ll line(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) > 0) return 0;
	if (ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) > 0) return 0;
	return 1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i <= 4; i++) cin >> x[i] >> y[i];
	if (line(x[1], y[1], x[2], y[2], x[3], y[3], x[4], y[4])) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	

	return 0;
}