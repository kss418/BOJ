#include <iostream>
using namespace std;
int n, result;
int arr[100001], d[100001], s[100001];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	arr[0] = 0;
	s[0] = 0;
	result = -1000000000;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + arr[i];
	}

	d[0] = 1000;
	for (int i = 1; i <= n; i++) {
		d[i] = min(s[i - 1], d[i - 1]);
	}

	for (int i = 1; i <= n; i++) {
		result = max(result, s[i] - d[i]);
	}

	cout << result;

	return 0;
}
