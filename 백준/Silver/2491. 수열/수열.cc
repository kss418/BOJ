#include <iostream>
#include <algorithm>
using namespace std;
int n;
int asc[100001], arr[100001],dsc[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	asc[0] = 1, dsc[0] = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) {
			asc[i] = asc[i - 1] + 1;
		}

		else{
			asc[i] = 1;
		}
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[i - 1]) {
			dsc[i] = dsc[i - 1] + 1;
		}

		else {
			dsc[i] = 1;
		}
	}

	cout << max(*max_element(dsc, dsc + n), *max_element(asc, asc + n));

	return 0;
}
