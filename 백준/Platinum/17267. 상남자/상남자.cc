#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
int x, y, l, r;
int result = 0;
bool visit[1001][1001];
string s[1001];

struct pos {
	int x;
	int y;
	int l;
	int r;
};


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int stx, sty;
	cin >> y >> x >> l >> r;
	for (int i = 0; i < y; i++) {
		cin >> s[i];
		for (int j = 0; j < x;j++) {
			if (s[i][j] == '2') {
				stx = j;
				sty = i;
			}
		}	
	}

	deque <pos> q;
	pos st = { stx,sty,l,r };
	q.push_back(st);

	while (!q.empty()) {
		pos cur = q.front();
		q.pop_front();

		if (cur.y >= y || cur.y < 0 || cur.x >= x || cur.x < 0) {
			continue;
		}

		if (visit[cur.y][cur.x] || s[cur.y][cur.x] == '1') {
			continue;
		}
		visit[cur.y][cur.x] = 1;
		result++;
		int pl = 1, mi = 1;


		while (cur.y + pl < y && s[cur.y + pl][cur.x] != '1' && !visit[cur.y + pl][cur.x]) {
			pos next = { cur.x ,cur.y + pl,cur.l,cur.r };
			q.push_back(next);
			pl++;
		}

		while (cur.y - mi >= 0 && s[cur.y - mi][cur.x] != '1' && !visit[cur.y - mi][cur.x]) {
			pos next = { cur.x ,cur.y - mi,cur.l,cur.r };
			q.push_back(next);
			mi++;
		}

		if (cur.l) {
			pos next = { cur.x - 1,cur.y,cur.l - 1,cur.r };
			q.push_back(next);
		}

		if (cur.r) {
			pos next = { cur.x + 1,cur.y,cur.l,cur.r - 1 };
			q.push_back(next);
		}
	}
	

	
	
	cout << result;


	return 0;
}

