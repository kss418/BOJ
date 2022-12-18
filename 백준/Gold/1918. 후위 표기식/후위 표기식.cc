#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string ch;
	cin >> ch;

	stack <char> list;
	for (int i = 0; i < ch.size(); i++) {
		if (ch[i] == '(') {
			list.push(ch[i]);
		}
		else if (ch[i] == ')') {
			while (list.top() != '(') {
				cout << list.top();
				list.pop();
			}
			list.pop();
		}
		else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
			if (list.empty() || list.top() == '(') {
				list.push(ch[i]);
			}
			else if (ch[i] == '*' || ch[i] == '/') {
				while (1) {
					if (list.empty() || list.top() == '+' || list.top() == '-' || list.top() == '(') {
						list.push(ch[i]);
						break;
					}
					else {
						cout << list.top();
						list.pop();
					}
				}
			}

			else {
				while (1) {
					if (list.empty() || list.top() == '(') {
						list.push(ch[i]);
						break;
					}
					else {
						cout << list.top();
						list.pop();
					}
				}
			}
		}
		else {
			cout << ch[i];
		}
		


	}

	while (!list.empty()) {
		char cur = list.top();
		list.pop();
		cout << cur;
	}


	return 0;
}
