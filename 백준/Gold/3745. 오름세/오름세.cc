#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result[1000001];
int arr[1000001];
int ord[1000001];
int ret[1000001];
int cnt;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		cnt = 0;
		fill(result, result + 1000001, 0);
		fill(arr, arr + 1000001, 0);
		fill(ord, ord + 1000001, 0);
		fill(ret, ret + 1000001, 0);
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr[i] = num;

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
					int cur = lower_bound(result + 1, result + cnt + 1, num) - result;
					result[cur] = num;
				}
			}
		}
		cout << cnt << "\n";
	}





	return 0;
}
