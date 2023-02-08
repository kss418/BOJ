#include <iostream>
using namespace std; typedef long long ll;
const int MAX = 1010101; ll result, chk[MAX], n, m;
int main() {
	cin >> n >> m;
	for (ll i = 2; i * i <= m; i++) for (ll j = (n / (i * i) + (bool)(n % (i * i))) * i * i; j <= m; j += i * i) chk[j - n + 1] = 1;
	for (int i = 1; i <= m - n + 1; i++) if (!chk[i]) result++;
	cout << result;
	return 0;
}