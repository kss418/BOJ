#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a, b;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		cin >> a >> b;

		if (a == b) {
			break;
		}
		
		if (a % b == 0) {
			cout << "multiple" << "\n";
		}

		else if (b % a == 0) {
			cout << "factor" << "\n";
		}
		
		else {
			cout << "neither" << "\n";
		}
	}
	

	return 0;
}
