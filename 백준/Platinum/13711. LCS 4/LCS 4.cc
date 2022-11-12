#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result[1000001];
int arr[1000001];
int seq[1000001];
int num[1000001];
int cnt;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);


	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		num[seq[i]] = i + 1;
	}




	for (int i = 0; i < n; i++) {
		int curn = num[arr[i]];
		

		if (i == 0) {
			result[1] = curn;
			cnt++;
		}
		else {
			if (result[cnt] < curn) {
				cnt++;
				result[cnt] = curn;
			}
			else {
				int cur = lower_bound(result + 1, result + cnt + 1, curn) - result;
				result[cur] = curn;
			}
		}
	}


	cout << cnt << "\n";
	



	return 0;
}
