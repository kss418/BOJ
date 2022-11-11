#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result[1000001];
int cnt;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);


	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (i == 0) {
			result[1] = num;
			cnt++;
		}
		else {
			if (result[cnt] < num) {
				cnt++;
				result[cnt] = num;
			}
			else {
				result[lower_bound(result + 1, result + cnt + 1, num) - result] = num;
			}
		}
	}
	
	
	cout << cnt;


	


	return 0;
}
