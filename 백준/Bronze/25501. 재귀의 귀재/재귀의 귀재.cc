#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, cnt, result;
bool ispel;
string ch;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> ch;
		cnt = 0;
		ispel = true;
		for (int i = 0; i < ch.size(); i++) {
			cnt++;
			if (ch[i] != ch[ch.size() - i - 1]) {
				ispel = false;
				break;
			}
			
			if (i >= ch.size() - i - 1) {
				break;
			}
		}

		if (ispel) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
		cout << cnt << "\n";
	}

	return 0;
}
