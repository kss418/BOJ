#include <iostream>
#include <algorithm>
using namespace std;
long long n, a;

long long gcd(long long a, long long b) {
	long long r, s, t, q;
	long long t1 = 0, t2 = 1;
	long long orig = a;
	while (b != 0) {
		q = a / b;
		r = a % b;
		a = b;
		b = r;


		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	if (a == 1) {
		if (t1 < 0) {
			return t1 + orig;
		}
		else {
			return t1;
		}
	}
	else {
		return -1;
	}
}

long long result = -1;

int main() {
	cin >> n >> a;

	cout << n - a << " ";



	cout << gcd(n, a);


	return 0;
}