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
const int MAX = 201010;
ll arr[MAX], result;


int gcd(int a, int b) {
	while (b) {
		int mod = a % b;
		a = b;
		b = mod;
	}
	
	return a;
}


ll dc(int st, int en) {
	if (st == en) {
		return arr[st];
	}

	int mid = (st + en - 1) / 2;
	int rl = arr[st], rr = arr[mid + 1];
	for (int i = st; i <= mid; i++) {
		rl = gcd(rl, arr[i]);
	}

	for (int i = mid + 1; i <= en; i++) {
		rr = gcd(rr, arr[i]);
	}

	return max(dc(st, mid) + rr, dc(mid + 1, en) + rl);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cout << dc(1, n);



	return 0;
}