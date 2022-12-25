#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
int x, y, st;
char arr[1501][1501][2];
int melt[1501][1501];
int bfs[1501][1501][2];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct pos {
	int x;
	int y;
	int num;
};

pos start[2];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> y >> x;
	deque <pos> ice, nextice;
	fill(&bfs[0][0][0], &bfs[1500][1501][2], -1);
	fill(&melt[0][0], &melt[1500][1501], -1);
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> arr[i][j][0];
			arr[i][j][1] = arr[i][j][0];
			if (arr[i][j][0] == 'L') {
				start[st] = { j,i,0 };
				st++;
				pos cur = { j,i,0 };
				ice.push_back(cur);
			}
			else if (arr[i][j][0] == '.') {
				pos cur = { j,i,0 };
				ice.push_back(cur);
			}
		}
	}

	while (1) {
		if (ice.empty()) {
			if (!nextice.empty()) {
				ice = nextice;
				nextice.clear();
			}
			else {
				break;
			}
		}
		pos front = ice.front();
		ice.pop_front();

		if (melt[front.y][front.x] != -1) {
			continue;
		}

		melt[front.y][front.x] = front.num;
		for (int i = 0; i < 4; i++) {
			pos next = { front.x + dx[i],front.y + dy[i],front.num };

			if (next.x > x || next.x < 1 || next.y > y || next.y < 1) {
				continue;
			}

			if (melt[next.y][next.x] != -1) {
				continue;
			}

			if (arr[next.y][next.x][0] == 'X') {
				next.num++;
				nextice.push_back(next);
			}
			else {
				ice.push_back(next);
			}
		}
	}

	for (int cur = 0; cur <= 1; cur++) {
		deque <pos> q, nextq;
		q.push_back(start[cur]);
		while (1) {
			if (q.empty()) {
				if (!nextq.empty()) {
					q = nextq;
					nextq.clear();
				}
				else {
					break;
				}
			}

			pos front = q.front();
			q.pop_front();

			if (bfs[front.y][front.x][cur] != -1) {
				continue;
			}

			bfs[front.y][front.x][cur] = front.num;
			for (int i = 0; i < 4; i++) {
				pos next = { front.x + dx[i],front.y + dy[i],front.num};

				if (next.x > x || next.x < 1 || next.y > y || next.y < 1) {
					continue;
				}

				if (bfs[next.y][next.x][cur] != -1) {
					continue;
				}

				if (arr[next.y][next.x][cur] == 'X' && melt[next.y][next.x] > bfs[front.y][front.x][cur]) {
					next.num++;
					nextq.push_back(next);
				}
				else {
					q.push_back(next);
				}
			}
		}
	}

	int result = 100000000;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			for (int k = 0; k < 4; k++) {
				int curx = j + dx[k];
				int cury = i + dy[k];
				if (curx > x || curx < 1 || cury > y || cury < 1) {
					continue;
				}

				result = min(result, max(bfs[cury][curx][0], bfs[i][j][1]));
			}
		}
	}
	
	cout << result;

	
	return 0;
}

