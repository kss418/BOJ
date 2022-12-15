#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


bool cmp(string ch1, string ch2) {
	int i = 0;
	string m;

	if (ch1.size() > ch2.size()) {
		m = ch1;
	}
	else {
		m = ch2;
	}

	for (i = 0; i < min(ch1.size(), ch2.size()); i++) {
		if (ch1[i] == ch2[i]) {
			continue;
		}
		else {
			return ch1[i] > ch2[i];
		}
	}

	for (int cur = i; cur < max(ch1.size(), ch2.size()); cur++) {
		if (m[cur] > m[cur - i]) {
			return ch1.size() > ch2.size();
		}
		else if (m[cur] == m[cur - i]) {
			continue;
		}
		else {
			return ch1.size() < ch2.size();
		}
	}

	if (ch1.size() == ch2.size()) {
		return true;
	}

	int diff, cur = 0;
	for (int i = max(ch1.size(), ch2.size()) - min(ch1.size(), ch2.size()); i < max(ch1.size(), ch2.size()); i++) {
		if (m[i] < m[cur]) {
			return ch1.size() > ch2.size();
		}
		else if (m[i] == m[cur]) {
			continue;
		}
		else {
			return ch1.size() < ch2.size();
		}

		cur++;
	}
	return ch1.size() < ch2.size();
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	ll cnt = 0;
	cin >> n;
	vector <string> arr;
	for (int i = 0; i < n; i++) {
		string ch;
		cin >> ch;
		arr.push_back(ch);
		if (ch == "0") {
			cnt++;
		}
	}

	if (cnt == n) {
		cout << 0;
		return 0;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (auto i : arr) {
		cout << i;
	}


	return 0;
}

