#include <iostream>
#include <vector>
using namespace std;

int x, y, t, num;
int xa[4] = { 0,0,1,-1 };
int ya[4] = { 1,-1,0,0 };
int arr[51][51];
int loc;
int curx, cury;
void fl(int n);

void fl(int n) {
	while (n--) {
		int sum_arr[51][51] = {};
		int num_arr[51][51] = {};
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (arr[i][j] == 0 || arr[i][j] == -1) {
					continue;
				}
				for (int k = 0; k < 4; k++) {
					curx = xa[k] + j;
					cury = ya[k] + i;
					if (arr[cury][curx] == -1 || curx >= x || curx < 0 || cury >= y || cury < 0) {
						continue;
					}
					sum_arr[cury][curx] += (int)(arr[i][j]/5);
					num_arr[i][j] += 1;
				}
			}
		}
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				arr[i][j] = arr[i][j] - (num_arr[i][j]* (int)(arr[i][j] / 5));
				arr[i][j] += sum_arr[i][j];
			}
		}

		for (int i = 0; i < y; i++) {
			if (arr[i][0] == -1) {
				loc = i;
				break;
			}
		}
		for (int i = loc-1; i >= 1; i--) {
			arr[i][0] = arr[i - 1][0];
		}
		for (int i = 0; i < x - 1; i++) {
			arr[0][i] = arr[0][i + 1];
		}
		for (int i = 0; i < loc; i++) {
			arr[i][x - 1] = arr[i + 1][x - 1];
		}
		for (int i = x - 1; i > 1; i--) {
			arr[loc][i] = arr[loc][i - 1];
		}
		for (int i = loc + 2; i < y-1; i++) {
			arr[i][0] = arr[i + 1][0];
		}
		for (int i = 0; i < x - 1; i++) {
			arr[y-1][i] = arr[y-1][i + 1];
		}
		for (int i = y-1; i > loc+1; i--) {
			arr[i][x - 1] = arr[i - 1][x - 1];
		}
		for (int i = x - 1; i > 1; i--) {
			arr[loc+1][i] = arr[loc+1][i - 1];
		}
		arr[loc][1] = 0;
		arr[loc+1][1] = 0;
	}
}


int main() {
	cin >> y >> x >> t;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> num;
			arr[i][j] = num;
		}
	}
	fl(t);
	int result = 0;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			result += arr[i][j];
		}
	}
	cout << result + 2 << endl;
	return 0;
}