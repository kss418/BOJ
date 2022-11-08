#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[6][6];
int visit[6][6];
int result[6];
int cnt = 0;
bool flag = true;

void dfs(int x, int y, int cur, int dir) {
	if (x < 0 || x > 5 || y < 0 || y > 5) {
		return;
	}

	if (!arr[y][x] || visit[y][x]) {
		return;
	}

	if (result[cur] != -1) {
		flag = false;
		return;
	}
	visit[y][x] = 1;
	result[cur] = arr[y][x];

	if (dir == 0) {
		dfs(x - 1, y, 2, 1);
		dfs(x + 1, y, 4, 1);
		dfs(x, y - 1, 1, -3);
		dfs(x, y + 1, 3, 3);
		return;
	}

	else if (dir == 1) {
		/* 0 4 5 2 */
		if (cur == 0) {
			dfs(x - 1, y, 2, 1);
			dfs(x + 1, y, 4, 1);
			dfs(x, y - 1, 1, -3);
			dfs(x, y + 1, 3, 3);
		}

		else if (cur == 4) {
			dfs(x - 1, y, 0, 1);
			dfs(x + 1, y, 5, 1);
			dfs(x, y - 1, 1, 2);
			dfs(x, y + 1, 3, -2);
		}

		else if (cur == 5) {
			dfs(x - 1, y, 4, 1);
			dfs(x + 1, y, 2, 1);
			dfs(x, y - 1, 1, 3);
			dfs(x, y + 1, 3, -3);
		}

		else {
			dfs(x - 1, y, 5, 1);
			dfs(x + 1, y, 0, 1);
			dfs(x, y - 1, 1, -2);
			dfs(x, y + 1, 3, 2);
		}
		return;
	}

	else if (dir == -1) {
		/* 0 2 5 4 */
		if (cur == 0) {
			dfs(x - 1, y, 4, -1);
			dfs(x + 1, y, 2, -1);
			dfs(x, y - 1, 3, -3);
			dfs(x, y + 1, 1, 3);
		}

		else if (cur == 2) {
			dfs(x - 1, y, 0, -1);
			dfs(x + 1, y, 5, -1);
			dfs(x, y - 1, 3, -2);
			dfs(x, y + 1, 1, 2);
		}

		else if (cur == 5) {
			dfs(x - 1, y, 2, -1);
			dfs(x + 1, y, 4, -1);
			dfs(x, y - 1, 3, 3);
			dfs(x, y + 1, 1, -3);
		}

		else {
			dfs(x - 1, y, 5, -1);
			dfs(x + 1, y, 0, -1);
			dfs(x, y - 1, 3, 2);
			dfs(x, y + 1, 1, -2);
		}
		return;
	}

	else if (dir == 2) {
		/* 0 1 5 3 */
		if (cur == 0) {
			dfs(x - 1, y, 3, 2);
			dfs(x + 1, y, 1, 2);
			dfs(x, y - 1, 2, -3);
			dfs(x, y + 1, 4, 3);
		}

		else if (cur == 1) {
			dfs(x - 1, y, 0, 2);
			dfs(x + 1, y, 5, 2);
			dfs(x, y - 1, 2, -1);
			dfs(x, y + 1, 4, 1);
		}

		else if (cur == 5) {
			dfs(x - 1, y, 1, 2);
			dfs(x + 1, y, 3, 2);
			dfs(x, y - 1, 2, 3);
			dfs(x, y + 1, 4, -3);
		}

		else {
			dfs(x - 1, y, 5, 2);
			dfs(x + 1, y, 0, 2);
			dfs(x, y - 1, 2, 1);
			dfs(x, y + 1, 4, -1);
		}
		return;
	}

	else if (dir == -2) {
		/* 0 3 5 1 */
		if (cur == 0) {
			dfs(x - 1, y, 3, -2);
			dfs(x + 1, y, 1, -2);
			dfs(x, y - 1, 4, -3);
			dfs(x, y + 1, 2, 3);
		}

		else if (cur == 1) {
			dfs(x - 1, y, 5, -2);
			dfs(x + 1, y, 0, -2);
			dfs(x, y - 1, 4, -1);
			dfs(x, y + 1, 2, 1);
		}

		else if (cur == 5) {
			dfs(x - 1, y, 3, -2);
			dfs(x + 1, y, 1, -2);
			dfs(x, y - 1, 4, 3);
			dfs(x, y + 1, 2, -3);
		}

		else {
			dfs(x - 1, y, 0, -2);
			dfs(x + 1, y, 5, -2);
			dfs(x, y - 1, 4, 1);
			dfs(x, y + 1, 2, -1);
		}
		return;
	}

	else if (dir == 3) {
		/* 1 2 3 4 */
		if (cur == 1) {
			dfs(x - 1, y, 4, 3);
			dfs(x + 1, y, 2, 3);
			dfs(x, y - 1, 0, -1);
			dfs(x, y + 1, 5, 1);
		}

		else if (cur == 2) {
			dfs(x - 1, y, 1, 3);
			dfs(x + 1, y, 3, 3);
			dfs(x, y - 1, 0, -2);
			dfs(x, y + 1, 5, 2);
		}

		else if (cur == 3) {
			dfs(x - 1, y, 2, 3);
			dfs(x + 1, y, 4, 3);
			dfs(x, y - 1, 0, 1);
			dfs(x, y + 1, 5, -1);
		}

		else {
			dfs(x - 1, y, 3, 3);
			dfs(x + 1, y, 1, 3);
			dfs(x, y - 1, 0, -2);
			dfs(x, y + 1, 5, 2);
		}
		return;
	}

	else if (dir == -3) {
		/* 4 3 2 1 */
		if (cur == 1) {
			dfs(x - 1, y, 2, -3);
			dfs(x + 1, y, 4, -3);
			dfs(x, y - 1, 5, -1);
			dfs(x, y + 1, 0, 1);
		}

		else if (cur == 2) {
			dfs(x - 1, y, 3, -3);
			dfs(x + 1, y, 1, -3);
			dfs(x, y - 1, 5, -2);
			dfs(x, y + 1, 0, 2);
		}

		else if (cur == 3) {
			dfs(x - 1, y, 4, -3);
			dfs(x + 1, y, 2, -3);
			dfs(x, y - 1, 5, 1);
			dfs(x, y + 1, 0, -1);
		}

		else {
			dfs(x - 1, y, 1, -3);
			dfs(x + 1, y, 3, -3);
			dfs(x, y - 1, 5, -2);
			dfs(x, y + 1, 0, 2);
		}
	}
	return;

}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	int stx, sty;
	fill(result, result + 6, -1);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				sty = i;
				stx = j;
			}
		}
	}

	dfs(stx, sty, 0, 0);
	for (int i = 0; i < 6; i++) {
		if (result[i] != -1) {
			cnt++;
		}
	}

	if (cnt == 6) {
		cout << result[5];
	}
	else if (cnt != 6 || !flag) {
		cout << 0;
	}

	return 0;
}
