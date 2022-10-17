#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char arr[20][20];
int visit[30];
int x, y;
int result;

void dfs(int a, int b, int depth) {
	if (a < 0 || a >= x || b < 0 || b >= y) {
		return;
	}

	if (visit[arr[b][a] - 'A']) {
		return;
	}
	result = max(result, depth);

	visit[arr[b][a] - 'A'] = 1;
	dfs(a + 1, b, depth + 1);
	dfs(a - 1, b, depth + 1);
	dfs(a, b + 1, depth + 1);
	dfs(a, b - 1, depth + 1);
	visit[arr[b][a] - 'A'] = 0;
	return;
}



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
 
	cin >> y >> x;
	string ch;
	for (int i = 0; i < y; i++) {
		cin >> ch;
		for (int j = 0; j < x; j++) {
			arr[i][j] = ch[j];
		}
	}

	dfs(0, 0, 1);

	cout << result;
	
	return 0;
}
