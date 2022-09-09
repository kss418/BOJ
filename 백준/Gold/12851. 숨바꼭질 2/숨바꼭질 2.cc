#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int result = 0;
int st, en, cur, tmp;
int v[100001] = {};
int d[100001] = {};
deque <int> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> st >> en;
	q.push_back(st);
	d[st] = 0;
	v[st] = 1;
	if (st == en) {
		cout << 0 << "\n";
		cout << 1;
		return 0;
	}

	while (!q.empty()) {
		tmp = q.front();
		q.pop_front();
		for (int cur : {tmp - 1, tmp + 1, 2 * tmp}) {
			if (cur < 0 || cur > 100000) {
				continue; 
			}
			if (v[cur] == 1 && d[cur] != d[tmp] + 1) {
				continue;
			}
			v[cur] = 1;
			d[cur] = d[tmp] + 1;
			if (cur == en) {
				result++;
			}
			else {
				q.push_back(cur);
			}
		}
	}


	cout << d[en] << "\n";
	cout << result;

	return 0;
}