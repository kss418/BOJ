#include <iostream>
using namespace std;
string word, orig;
int num, result = 0;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> orig;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> word;
		bool chk = false;
		for (int j = 0; j < word.size(); j++) {
			int cur = j;
			int cnt = 0;
			for (auto k : orig) {
				if (word[cur] == k) {
					cur++;
					cnt++;
					if (cur == word.size()) {
						cur = 0;
					}
				}
				else {
					break;
				}

				if (cnt == orig.size()) {
					chk = true;
				}
			}

			if (chk == true) {
				result++;
				break;
			}
		}
	}

	cout << result;

	return 0;
}
