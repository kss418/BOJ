#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, num, st, en, mid, result;
vector <int> orig, comp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> num;
		orig.push_back(num);
	}
	sort(orig.begin(), orig.end());
	
	cin >> m;
	while (m--) {
		cin >> num;
		comp.push_back(num);
	}

	for (auto i : comp) {
		st = -1;
		en = orig.size() - 1;
		result = 0;

		while (en > st) {
			mid = (st + en + 1) / 2;
			if (orig[mid] > i) {
				en = mid - 1;
			}
			else if (orig[mid] < i) {
				st = mid;
			}
			else {
				result = 1;
				break;
			}
		}

		cout << result << " ";
	}
	

	return 0;
}
