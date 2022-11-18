#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
vector <tuple <double, int, int>> arr;


bool cmp(tuple<double, int, int> i, tuple<double, int, int> j) {
	double cmp1, cmp2;
	int a1, a2, b1, b2;
	tie(cmp1, a1, b1) = i;
	tie(cmp2, a2, b2) = j;
	if (cmp1 == cmp2) {
		return a1 > a2;
	}
	else {
		return cmp1 < cmp2;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a == 0) {
			arr.push_back({ 50000,a,b });
		}
		else {
			arr.push_back({ (double)b / (double)a,a,b });
		}
	}
	sort(arr.begin(), arr.end(), cmp);
	
	long long t = 0;
	for (auto i : arr) {
		double prior;
		int a, b;
		tie(prior,a,b) = i;
		t += a * t + b;
		t %= 40000;
	}


	cout << t;

	return 0;
}

