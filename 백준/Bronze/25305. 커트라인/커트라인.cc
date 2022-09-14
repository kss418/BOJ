#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, num;
vector <int> arr;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	while (n--) {
		cin >> num;
		arr.push_back(num);
	}
	
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	cout << arr[k - 1];


	return 0;
}
