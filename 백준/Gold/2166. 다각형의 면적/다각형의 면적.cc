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
const int MAX = 10101;
ll x[MAX], y[MAX];


ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) { 
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1); 
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	double result = 0;
	for (int i = 2; i <= n - 1; i++) {
		ll cur = ccw(x[1], y[1], x[i], y[i], x[i + 1], y[i + 1]);
		result += cur;
	}
	cout << fixed;
	cout.precision(1);

	cout << abs(result) / 2;

	return 0;
}