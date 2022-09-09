#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int arr[8][8];
int copy_arr[8][8];
int visited[8][8] = {};
int x, y, num;
vector<pair <int,int>> nums;
int max = 65;
int xq, yq;
int xa[4] = { 0,0,1,-1 };
int ya[4] = { 1,-1,0,0 };
int curx, cury;
int check = 0;
int result = -1;
deque <pair <int,int>> q;
void bt();
void bfs();

void bt() {
	if (nums.size() == 3) {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (arr[i][j] != 2) {
					continue;
				}
				q.push_back(make_pair(i, j));
			}
		}
		for (int k = 0; k < y; k++) {
			for (int l = 0; l < x; l++) {
				copy_arr[k][l] = arr[k][l];
			}
		}
		bfs();
		return;
	}
	else if(nums.size() == 0) {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (visited[i][j] || arr[i][j] != 0) {
					continue;
				}
				nums.push_back(make_pair(i, j));
				arr[i][j] = 1;
				visited[i][j] = 1;
				bt();
				visited[i][j] = 0;
				arr[i][j] = 0;
				nums.pop_back();
			}
		}
	}
	else if (nums.size() == 1) {
		for (int i = nums[0].first; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (visited[i][j] || arr[i][j] != 0) {
					continue;
				}
				nums.push_back(make_pair(i, j));
				arr[i][j] = 1;
				visited[i][j] = 1;
				bt();
				visited[i][j] = 0;
				arr[i][j] = 0;
				nums.pop_back();
			}
		}
	}
	else if (nums.size() == 2) {
		for (int i = nums[1].first; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (visited[i][j] || arr[i][j] != 0) {
					continue;
				}
				nums.push_back(make_pair(i, j));
				arr[i][j] = 1;
				visited[i][j] = 1;
				bt();
				visited[i][j] = 0;
				arr[i][j] = 0;
				nums.pop_back();
			}
		}
	}
}

void bfs() {
	while (q.size() > 0) {
		xq = q.front().second;
		yq = q.front().first;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			curx = xq + xa[i];
			cury = yq + ya[i];
			if (curx >= x || curx < 0 || cury >= y || cury < 0) {
				continue;
			}
			if (copy_arr[cury][curx] != 0) {
				continue;
			}
			copy_arr[cury][curx] = 2;
			q.push_back(make_pair(cury, curx));
		}
	}
	int count = 0;
	for (int a = 0; a < y; a++) {
		for (int b = 0; b < x; b++) {
			if (copy_arr[a][b] == 0) {
				count += 1;
			}
		}
	}
	if (count > result) {
		result = count;
	}
}

int main() {
	cin >> y >> x;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> num;
			arr[i][j] = num;
		}
	}
	bt();
	cout << result << endl;
	return 0;
}