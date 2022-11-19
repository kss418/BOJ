#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
vector <tuple <double, int, int, int>> arr;

bool cmp(tuple <double, int, int, int> i, tuple <double, int, int, int> j) {
	double prior1, prior2;
	int a1, a2, b1, b2, n1, n2;
	tie(prior1,a1,b1,n1) = i;
	tie(prior2, a2, b2, n2) = j;
	if (prior1 != prior2) {
		return prior1 > prior2;
	}
	else {
		return n1 < n2;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n;i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ (double)b / (double)a,a,b,i });
	}
	sort(arr.begin(), arr.end(), cmp);

	for (auto i : arr) {
		double prior;
		int a, b, n;
		tie(prior,a, b, n) = i;
		cout << n << " ";
	}

	
	return 0;
}
