#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long cnt;
vector <pair<int,int>> arr;
vector <pair<int,int>> result;


void mer(int st, int en) {
	int l = st;
	int mid = (st + en) / 2;
	int r = mid + 1;
	int cur = st;

	while (l <= mid && r <= en) {
		if (arr[l].first > arr[r].first) {
			result[cur++] = { arr[r].first, arr[r].second };
			r++;
		}
		else {
			result[cur++] = { arr[l].first, arr[l].second };
			l++;
		}
	}

	while (r <= en) {
		result[cur++] = { arr[r].first,arr[r].second };
		r++;
		}
	
	while (l <= mid) {
		result[cur++] = { arr[l].first,arr[l].second };
		l++;
	}
	for (int i = st; i <= en; i++) {
		if (result[i].second > i) {
			cnt += abs(result[i].second - i);
		}
		arr[i] = { result[i].first,i};
	}
}

void part(int st, int en) {
	int mid = (st + en) / 2;
	if (st < en) {
		part(st, mid);
		part(mid + 1, en);
		mer(st, en);
	}
	else if (st == en) {
		mer(st, en);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int num;
		cin >> num;
		arr.push_back({ num,i });
	}


	
	result.resize(500001);
	part(0, n - 1);

	cout << cnt << "\n";

	return 0;
}
