#include <iostream>
using namespace std;
int num, cur;
int orig_first, orig_second;
int first, second;
int cnt = 0;

void cycle(int x) {
	second = x % 10;
	first = (x - second) / 10;
	cur = second * 10 + (second + first) % 10;
	cnt++;
	if (cur != num) {
		cycle(cur);
	}
	else {
		cout << cnt;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> num;
	orig_second = num % 10;
	orig_first = (num - orig_second) / 10;
	cycle(num);

	return 0;
}
