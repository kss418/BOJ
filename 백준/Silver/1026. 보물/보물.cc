#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, num, result = 0;
vector <int> a, b;


int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}


	cout << result;

	return 0;
}
