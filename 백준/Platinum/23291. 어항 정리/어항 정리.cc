#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
int arr[102][102];
int cpyarr[102][102];
int plusarr[102][102];
int n, k;

void stack1() {
	int end = 0, toparr = 0, top = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[1][i] == 0) {
			end = i - 1;
			break;
		}
		if (arr[2][i] != 0) {
			toparr = i;
		}
	}

	if (!toparr) {
		cpyarr[2][1] = arr[1][1];
		for (int i = 1; i < n; i++) {
			cpyarr[1][i] = arr[1][i + 1];
		}
		cpyarr[1][n] = 0;
		top = 1;
	}
	else {
		int cur = 0;
		while (1) {
			cur++;
			if (arr[cur][1] != 0) {
				top = cur;
			}
			else {
				break;
			}
		}

		if (end - toparr < top) {
			return;
		}

		for (int i = 1; i <= toparr; i++) {
			for (int j = 1; j <= top; j++) {
				cpyarr[toparr - i + 2][j] = arr[j][i];
			}
		}

		for (int i = toparr + 1; i <= n; i++) {
			cpyarr[1][i - toparr] = arr[1][i];
		}
	}

	for (int i = 1; i <= top + 1; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = cpyarr[i][j];
			cpyarr[i][j] = 0;
		}
	}

	stack1();
}

void stack2() {
	int t = 2;
	while (t--) {
		int end = 1;
		while (arr[1][end] != 0) {
			end++;
		}
		end--;

		int top = 1;
		while (arr[top][1] != 0) {
			top++;
		}
		top--;


		for (int i = top * 2; i >= top + 1; i--) {
			for (int j = end / 2; j >= 1; j--) {
				cpyarr[i][j] = arr[top * 2 - i + 1][end / 2 - j + 1];
			}
		}

		for (int i = 1; i <= top; i++) {
			for (int j = end / 2 + 1; j <= n; j++) {
				cpyarr[i][j - end / 2] = arr[i][j];
			}
		}

		for (int i = 1; i <= top * 2; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = cpyarr[i][j];
				cpyarr[i][j] = 0;
			}
		}
	}
}

void fish() {
	deque <pair<int,int>> q;
	q.push_back({ 1,1 });
	int visit[102][102] = {};
	while (!q.empty()) {
		pair <int, int> cur = q.front();
		q.pop_front();
		if (visit[cur.second][cur.first]) {
			continue;
		}
		visit[cur.second][cur.first] = 1;


		if (arr[cur.second][cur.first + 1] != 0) {
			if (!visit[cur.second][cur.first + 1]) {
				q.push_back({ cur.first + 1, cur.second });
			}

			if (arr[cur.second][cur.first] < arr[cur.second][cur.first + 1]) {
				int diff = (arr[cur.second][cur.first + 1] - arr[cur.second][cur.first]) / 5;
				plusarr[cur.second][cur.first] += diff;
				plusarr[cur.second][cur.first + 1] -= diff;
			}
			else {
				int diff = (arr[cur.second][cur.first] - arr[cur.second][cur.first + 1]) / 5;
				plusarr[cur.second][cur.first] -= diff;
				plusarr[cur.second][cur.first + 1] += diff;

			}
		}
		
		if (arr[cur.second + 1][cur.first] != 0) {
			if (!visit[cur.second + 1][cur.first]) {
				q.push_back({ cur.first, cur.second + 1 });
			}
			if (arr[cur.second][cur.first] < arr[cur.second + 1][cur.first]) {
				int diff = (arr[cur.second + 1][cur.first] - arr[cur.second][cur.first]) / 5;
				plusarr[cur.second][cur.first] += diff;
				plusarr[cur.second + 1][cur.first] -= diff;
			}
			else {
				int diff = (arr[cur.second][cur.first] - arr[cur.second + 1][cur.first]) / 5;
				plusarr[cur.second][cur.first] -= diff;
				plusarr[cur.second + 1][cur.first] += diff;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += plusarr[i][j];
			plusarr[i][j] = 0;
		}
	}
}

void sort() {
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		while (arr[cnt][i] != 0) {
			cpyarr[1][cur] = arr[cnt][i];
			cur++;
			cnt++;
		}
	}

	for(int i = 2; i <= 100;i++){
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		arr[1][i] = cpyarr[1][i];
		cpyarr[1][i] = 0;
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[1][i];
	}



	while (1) {
		int mi = 10001, ma = 0;
		for (int i = 1; i <= n; i++) {
			mi = min(mi, arr[1][i]);
			ma = max(ma, arr[1][i]);
		}

		if (ma - mi <= k) {
			break;
		}

		for (int i = 1; i <= n; i++) {
			if (arr[1][i] == mi) {
				arr[1][i]++;
			}
		}
		
		cnt++;

		stack1();
		fish();
		sort();
		stack2();
		fish();
		sort();
	}

	cout << cnt;
	

	return 0;
}


