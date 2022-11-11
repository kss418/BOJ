#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result[1000001];
int arr[1000001];
int ord[1000001];
int ret[1000001];
int c[1000001];
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
		arr[i] = num;

		if (i == 0) {
			result[1] = num;
			c[i] = 1;
			cnt++;
		}
		else {
			if (result[cnt] < num) {
				cnt++;
				result[cnt] = num;
				c[i] = cnt;
			}
			else {
				int cur = lower_bound(result + 1, result + cnt + 1, num) - result;
				result[cur] = num;
				c[i] = cur;
			}
		}
	}


	cout << cnt << "\n";
	int cur = cnt;
	for (int i = n - 1; i >= 0; i--) {
		if (c[i] == cur) {
			ret[cur] = arr[i];
			cur--;
		}
	}
	
	for (int i = 1; i <= cnt; i++) {
		cout << ret[i] << " ";
	}




	return 0;
}
