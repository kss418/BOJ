#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int x, y, k;
char arr[51][51];
int visit[51][51];
int result = 0;

void bfs(int curx, int cury, int l,int r) {
	if (curx < 0 || cury < 0 || curx >= x || cury >= y) {
		return;
	}

	if (visit[cury][curx] || result) {
		return;
	}

	if (curx == x - 1 && cury == y - 1) {
		result = 1;
		return;
	}

	visit[cury][curx] = 1;
	if (arr[cury][curx] == 'L') {
		bfs(curx - 1, cury, l, r);
		if (l) {
			bfs(curx, cury + 1, l - 1, r);
		}
		if (r) {
			bfs(curx, cury - 1, l, r - 1);
		}
	}
	else if (arr[cury][curx] == 'R') {
		bfs(curx + 1, cury, l, r);
		if (l) {
			bfs(curx, cury - 1, l - 1, r);
		}
		if (r) {
			bfs(curx, cury + 1, l, r - 1);
		}
	}
	else if (arr[cury][curx] == 'U') {
		bfs(curx, cury - 1, l, r);
		if (l) {
			bfs(curx - 1, cury, l - 1, r);
		}
		if (r) {
			bfs(curx + 1, cury, l, r - 1);
		}
	}
	else {
		bfs(curx, cury + 1, l, r);
		if (l) {
			bfs(curx + 1, cury, l - 1, r);
		}
		if (r) {
			bfs(curx - 1, cury, l, r - 1);
		}
	}

	visit[cury][curx] = 0;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> y >> x >> k;
	string ch;
	for (int i = 0; i < y; i++) {
		cin >> ch;
		for (int j = 0; j < x; j++) {
			arr[i][j] = ch[j];
		}
	}

	bfs(0, 0, k, k);

	if (result) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
