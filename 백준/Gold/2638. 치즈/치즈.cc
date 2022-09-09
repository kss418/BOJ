#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
int x, y, num, curx, cury;
int t = 1;
int arr[102][102];
int xa[4] = { 0,0,1,-1 };
int ya[4] = { 1,-1,0,0 };
deque <pair <int, int>> q;
vector <pair <int, int>> loc;
vector <pair<int, int>> del;
pair <int, int> cur;
void cheese();
void air();


void air() {
	if (t != 1) {
		for (int i = 0; i < y + 2; i++) {
			for (int j = 0; j < x + 2; j++) {
				if (arr[i][j] == -1) {
					q.push_back({ j,i });
				}
			}
		}
	}

	while (!q.empty()) {
		cur = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			curx = cur.first + xa[i];
			cury = cur.second + ya[i];
			if (curx < 0 || curx > x + 2 || cury < 0 || cury > y + 2) {
				continue;
			}
			if (arr[cury][curx] != 0) {
				continue;
			}
			arr[cury][curx] = -1;
			q.push_back({ curx,cury });
		}
	}
	cheese();
	return;
}

void cheese() {
	for (int i = 1; i < y + 1; i++) {
		for (int j = 1; j < x + 1; j++) {
			if (arr[i][j] == 1) {
				loc.push_back({ j,i });
			}
		}
	}
	
	while (!loc.empty()) {
		cur = loc.back();
		loc.pop_back();
		int check = 0;
		for (int i = 0; i < 4; i++) {
			curx = cur.first + xa[i];
			cury = cur.second + ya[i];
			if (curx < 1 || curx > x + 1 || cury < 1 || cury > y + 1) {
				continue;
			}
			if (arr[cury][curx] == -1) {
				check += 1;
			}
		}
		if (check >= 2) {
			del.push_back({cur.first,cur.second});
		}
	}
	
	while(!del.empty()) {
		cur = del.back();
		del.pop_back();
		arr[cur.second][cur.first] = 0;
	}
	
	if (count(&arr[0][0], &arr[101][102], 1) != 0) {
		t += 1;
		air();
	}

	return;
	
}



int main() {
	cin >> y >> x;
	for (int i = 0; i < x + 2; i++) {
		arr[0][i] = -1;
		q.push_back({ i,0 });
	}
	for (int i = 1; i < y + 2; i++) {
		arr[i][0] = -1;
		q.push_back({ 0,i });
	}
	for (int i = 0; i < x + 2; i++) {
		arr[y+1][i] = -1;
		q.push_back({ i,y+1 });
	}
	for (int i = 1; i < y + 2; i++) {
		arr[i][x+1] = -1;
		q.push_back({ x+1,i });
	}
	for (int i = 1; i < y + 1; i++) {
		for (int j = 1; j < x + 1; j++) {
			cin >> num;
			arr[i][j] = num;
		}
	}
	air();

	cout << t;
	return 0;
}