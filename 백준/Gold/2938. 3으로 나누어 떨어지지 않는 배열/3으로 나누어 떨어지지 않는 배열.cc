#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 10101;
int arr[MAX], mod[3];
bool flag = 1; vector <int> result;
deque <int> modarr[3];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		mod[arr[i] % 3]++;
		modarr[arr[i] % 3].push_back(arr[i]);
	}

	if (mod[0] >= 2) {
		result.push_back(0);
		mod[0]--;
	}
	else if (mod[1]) {
		result.push_back(1);
		mod[1]--;
	}
	else if (mod[2]) {
		result.push_back(2);
		mod[2]--;
	}
	else {
		result.push_back(0);
		mod[0]--;
	}

	for (int i = 1; i < n; i++) {
		if (result[i - 1] == 0) {
			if (mod[1]) {
				result.push_back(1);
				mod[1]--;
			}
			else if(mod[2]) {
				result.push_back(2);
				mod[2]--;
			}
			else {
				flag = 0;
				break;
			}
		}
		else if (result[i - 1] == 1) {
			if (mod[0] >= 2) {
				result.push_back(0);
				mod[0]--;
			}
			else if (mod[1]) {
				result.push_back(1);
				mod[1]--;
			}
			else if (mod[0]) {
				result.push_back(0);
				mod[0]--;
			}
			else {
				flag = 0;
				break;
			}
		}
		else{
			if (mod[0] >= 2) {
				result.push_back(0);
				mod[0]--;
			}
			else if (mod[2]) {
				result.push_back(2);
				mod[2]--;
			}
			else if (mod[0]) {
				result.push_back(0);
				mod[0]--;
			}
			else {
				flag = 0;
				break;
			}
		}
	}


	if (!flag) {
		cout << -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << modarr[result[i]].front() << " ";
			modarr[result[i]].pop_front();
		}
	}


	return 0;
}