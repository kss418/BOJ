#include <iostream>
#include <vector>
using namespace std;
int n, k;
long long result = 1;
vector <int> arr;


int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = k; i >= 1; i--) {
		arr.push_back(n / i);
		n -= n / i;
	}

	for (auto i : arr) {
		result *= i;
	}

	cout << result;

	return 0;
}
