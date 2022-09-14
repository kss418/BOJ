#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int fibo(int n) {
	if (n == 0) {
		return 0;
	}

	else if (n == 1) {
		return 1;
	}

	else {
		return fibo(n - 1) + fibo(n - 2);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cout << fibo(n);

	return 0;
}
