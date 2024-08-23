#include <iostream>
using namespace std;
long long a, b, c;
long long pow(long long a, long long b, long long c) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a % c;
	}
	long long tmp = pow(a, b / 2, c);
	tmp = tmp * tmp % c;
	if (b%2==0){
		return tmp;
	}
	else {
		return tmp * a % c;
	}
}

int main() {
	cin >> a >> b >> c;
	cout << pow(a, b, c) << endl;
	return 0;
}