#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
vector <pair <int, int>> check_arr, heater_arr;
int temp[22][22], arr[22][22], block[22][22];
int x, y, k;

struct heater {
	int x;
	int y;
	int tem;
};

void heat(int curx, int cury, int dir) {
	int pl[22][22] = {};
	int visit[22][22] = {};
	deque <heater> q;


	if (dir == 1) {
		heater first = { curx + 1, cury ,5 };
		q.push_back(first);
		while (!q.empty()) {
			heater cur = q.front();
			q.pop_front();

			if (visit[cur.y][cur.x]) {
				continue;
			}

			pl[cur.y][cur.x] = cur.tem;
			visit[cur.y][cur.x] = 1;

			for (int i = -1; i <= 1; i++) {
				heater next = { cur.x + 1,cur.y + i,cur.tem - 1 };

				if (next.x < 1 || next.x > x || next.y < 1 || next.y > y) {
					continue;
				}

				if (next.tem <= 0) {
					break;
				}

				if (visit[next.y][next.x]) {
					continue;
				}

				if (block[next.y][next.x - 1] & 2) {
					continue;
				}
				
				else if (i == -1 && block[cur.y][cur.x] & 1) {
					continue;
				}
				else if (i == 1 && block[cur.y + 1][cur.x] & 1) {
					continue;
				}

				q.push_back(next);
			}
		}
	}
	else if (dir == 2) {
		heater first = { curx - 1, cury ,5 };
		q.push_back(first);
		while (!q.empty()) {
			heater cur = q.front();
			q.pop_front();

			if (visit[cur.y][cur.x]) {
				continue;
			}

			pl[cur.y][cur.x] = cur.tem;
			visit[cur.y][cur.x] = 1;

			for (int i = -1; i <= 1; i++) {
				heater next = { cur.x - 1,cur.y + i,cur.tem - 1 };

				if (next.x < 1 || next.x > x || next.y < 1 || next.y > y) {
					continue;
				}

				if (next.tem <= 0) {
					break;
				}

				if (visit[next.y][next.x]) {
					continue;
				}

				if (block[next.y][next.x] & 2) {
					continue;
				}

				else if (i == -1 && block[cur.y][cur.x] & 1) {
					continue;
				}
				else if (i == 1 && block[cur.y + 1][cur.x] & 1) {
					continue;
				}

				q.push_back(next);
			}
		}
	}
	else if (dir == 3) {
		heater first = { curx , cury - 1,5 };
		q.push_back(first);
		while (!q.empty()) {
			heater cur = q.front();
			q.pop_front();

			if (visit[cur.y][cur.x]) {
				continue;
			}

			pl[cur.y][cur.x] = cur.tem;
			visit[cur.y][cur.x] = 1;

			for (int i = -1; i <= 1; i++) {
				heater next = { cur.x + i,cur.y - 1,cur.tem - 1 };

				if (next.x < 1 || next.x > x || next.y < 1 || next.y > y) {
					continue;
				}

				if (next.tem <= 0) {
					break;
				}

				if (visit[next.y][next.x]) {
					continue;
				}

				if (block[next.y + 1][next.x] & 1) {
					continue;
				}

				else if (i == -1 && block[cur.y][cur.x - 1] & 2) {
					continue;
				}
				else if (i == 1 && block[cur.y][cur.x] & 2) {
					continue;
				}

				q.push_back(next);
			}
		}
	}
	else {
	heater first = { curx , cury + 1,5 };
	q.push_back(first);
	while (!q.empty()) {
		heater cur = q.front();
		q.pop_front();

		if (visit[cur.y][cur.x]) {
			continue;
		}

		pl[cur.y][cur.x] = cur.tem;
		visit[cur.y][cur.x] = 1;

		for (int i = -1; i <= 1; i++) {
			heater next = { cur.x + i,cur.y + 1,cur.tem - 1 };

			if (next.x < 1 || next.x > x || next.y < 1 || next.y > y) {
				continue;
			}

			if (next.tem <= 0) {
				break;
			}

			if (visit[next.y][next.x]) {
				continue;
			}

			if (block[next.y][next.x] & 1) {
				continue;
			}

			else if (i == -1 && block[cur.y][cur.x - 1] & 2) {
				continue;
			}
			else if (i == 1 && block[cur.y][cur.x] & 2) {
				continue;
			}

			q.push_back(next);
			}
		}
	}

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			temp[i][j] += pl[i][j];
		}
	}
}

void wind() {
	for (auto i : heater_arr) {
		heat(i.first, i.second, arr[i.second][i.first]);
	}
}

void tem() {
	int diff[21][21] = {};
	int cur;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (i <= y - 1 && !(block[i + 1][j] & 1)) {
				cur = abs(temp[i + 1][j] - temp[i][j]) / 4;
				if (temp[i][j] < temp[i + 1][j]) {
					diff[i][j] += cur;
					diff[i + 1][j] -= cur;
				}
				else {
					diff[i][j] -= cur;
					diff[i + 1][j] += cur;
				}
			}

			if (j <= x - 1 && !(block[i][j] & 2)) {
				cur = abs(temp[i][j + 1] - temp[i][j]) / 4;
				if (temp[i][j] < temp[i][j + 1]) {
					diff[i][j] += cur;
					diff[i][j + 1] -= cur;
				}
				else {
					diff[i][j] -= cur;
					diff[i][j + 1] += cur;
				}
			}
		}
	}

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			temp[i][j] += diff[i][j];
		}
	}
}

void outer() {
	for (int i = 1; i <= x; i++) {
		if (temp[y][i]) {
			temp[y][i]--;
		}
		if (temp[1][i]) {
			temp[1][i]--;
		}
	}

	for (int i = 2; i < y; i++) {
		if (temp[i][x]) {
			temp[i][x]--;
		}
		if (temp[i][1]) {
			temp[i][1]--;
		}
	}
}

int check() {
	int ret = 1;
	for (auto i : check_arr) {
		if (temp[i.second][i.first] < k) {
			ret = 0;
		}
	}

	return ret;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int result = 0;

	cin >> y >> x >> k;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> arr[i][j];
			if (!arr[i][j]) {
				continue;
			}
			else if (arr[i][j] == 5) {
				check_arr.push_back({ j,i });
			}
			else {
				heater_arr.push_back({ j,i });
			}
		}
	}

	int n, dir, ny, nx;
	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> ny >> nx >> dir;
		if (block[ny][nx] == 0) {
			block[ny][nx] = dir + 1;
		}
		else {
			block[ny][nx] |= dir + 1;
		}
	}
	
	
	while (1) {
		wind();
		tem();
		outer();
		result++;

		if (check() || result >= 101) {
			break;
		}
	}


	cout << min(result, 101);

	return 0;
}

