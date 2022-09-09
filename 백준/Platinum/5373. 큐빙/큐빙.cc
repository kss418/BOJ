#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string cubic[3][2][3][3];
string temp[3][2][3][3];
int n, num;
string command;


void cubing(string com) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					temp[i][j][k][l] = cubic[i][j][k][l];
				}
			}
		}
	}
	if (com == "U+") {
		for (int j = 0; j < 3; j++) {
			temp[2][0][0][j] = cubic[1][0][0][j];
			temp[1][1][0][j] = cubic[2][0][0][j];
			temp[2][1][0][j] = cubic[1][1][0][j];
			temp[1][0][0][j] = cubic[2][1][0][j];
		}
		temp[0][0][0][2] = cubic[0][0][0][0];
		temp[0][0][1][2] = cubic[0][0][0][1];
		temp[0][0][2][2] = cubic[0][0][0][2];
		temp[0][0][2][1] = cubic[0][0][1][2];
		temp[0][0][2][0] = cubic[0][0][2][2];
		temp[0][0][1][0] = cubic[0][0][2][1];
		temp[0][0][0][0] = cubic[0][0][2][0];
		temp[0][0][0][1] = cubic[0][0][1][0];
	}
	else if (com == "U-") {
		 for (int j = 0; j < 3; j++) {
			temp[1][0][0][j] = cubic[2][0][0][j];
			temp[2][0][0][j] = cubic[1][1][0][j];
			temp[1][1][0][j] = cubic[2][1][0][j];
			temp[2][1][0][j] = cubic[1][0][0][j];
		}
		 temp[0][0][0][0] = cubic[0][0][0][2];
		 temp[0][0][0][1] = cubic[0][0][1][2];
		 temp[0][0][0][2] = cubic[0][0][2][2];
		 temp[0][0][1][2] = cubic[0][0][2][1];
		 temp[0][0][2][2] = cubic[0][0][2][0];
		 temp[0][0][2][1] = cubic[0][0][1][0];
		 temp[0][0][2][0] = cubic[0][0][0][0];
		 temp[0][0][1][0] = cubic[0][0][0][1];
	}
	else if (com == "D-") {
		for (int j = 0; j < 3; j++) {
			temp[2][0][2][j] = cubic[1][0][2][j];
			temp[1][1][2][j] = cubic[2][0][2][j];
			temp[2][1][2][j] = cubic[1][1][2][j];
			temp[1][0][2][j] = cubic[2][1][2][j];
		}
		temp[0][1][0][0] = cubic[0][1][0][2];
		temp[0][1][0][1] = cubic[0][1][1][2];
		temp[0][1][0][2] = cubic[0][1][2][2];
		temp[0][1][1][2] = cubic[0][1][2][1];
		temp[0][1][2][2] = cubic[0][1][2][0];
		temp[0][1][2][1] = cubic[0][1][1][0];
		temp[0][1][2][0] = cubic[0][1][0][0];
		temp[0][1][1][0] = cubic[0][1][0][1];
	}
	else if (com == "D+") {
		for (int j = 0; j < 3; j++) {
			temp[1][0][2][j] = cubic[2][0][2][j];
			temp[2][0][2][j] = cubic[1][1][2][j];
			temp[1][1][2][j] = cubic[2][1][2][j];
			temp[2][1][2][j] = cubic[1][0][2][j];
		}
		temp[0][1][0][2] = cubic[0][1][0][0];
		temp[0][1][1][2] = cubic[0][1][0][1];
		temp[0][1][2][2] = cubic[0][1][0][2];
		temp[0][1][2][1] = cubic[0][1][1][2];
		temp[0][1][2][0] = cubic[0][1][2][2];
		temp[0][1][1][0] = cubic[0][1][2][1];
		temp[0][1][0][0] = cubic[0][1][2][0];
		temp[0][1][0][1] = cubic[0][1][1][0];
	}
	else if (com == "F+") {
		for (int i = 0; i < 3; i++) {
			temp[2][1][i][0] = cubic[0][0][2][i];
			temp[2][0][i][2] = cubic[0][1][0][i];
		}
		temp[0][1][0][0] = cubic[2][1][2][0];
		temp[0][1][0][1] = cubic[2][1][1][0];
		temp[0][1][0][2] = cubic[2][1][0][0];
		temp[0][0][2][0] = cubic[2][0][2][2];
		temp[0][0][2][1] = cubic[2][0][1][2];
		temp[0][0][2][2] = cubic[2][0][0][2];

		temp[1][0][0][2] = cubic[1][0][0][0];
		temp[1][0][1][2] = cubic[1][0][0][1];
		temp[1][0][2][2] = cubic[1][0][0][2];
		temp[1][0][2][1] = cubic[1][0][1][2];
		temp[1][0][2][0] = cubic[1][0][2][2];
		temp[1][0][1][0] = cubic[1][0][2][1];
		temp[1][0][0][0] = cubic[1][0][2][0];
		temp[1][0][0][1] = cubic[1][0][1][0];
	}
	else if (com == "F-") {
		for (int i = 0; i < 3; i++) {
			temp[0][0][2][i] = cubic[2][1][i][0];
			temp[0][1][0][i] = cubic[2][0][i][2];
		}
		temp[2][1][2][0] = cubic[0][1][0][0];
		temp[2][1][1][0] = cubic[0][1][0][1];
		temp[2][1][0][0] = cubic[0][1][0][2];
		temp[2][0][2][2] = cubic[0][0][2][0];
		temp[2][0][1][2] = cubic[0][0][2][1];
		temp[2][0][0][2] = cubic[0][0][2][2];

		temp[1][0][0][0] = cubic[1][0][0][2];
		temp[1][0][0][1] = cubic[1][0][1][2];
		temp[1][0][0][2] = cubic[1][0][2][2];
		temp[1][0][1][2] = cubic[1][0][2][1];
		temp[1][0][2][2] = cubic[1][0][2][0];
		temp[1][0][2][1] = cubic[1][0][1][0];
		temp[1][0][2][0] = cubic[1][0][0][0];
		temp[1][0][1][0] = cubic[1][0][0][1];
	}
	else if (com == "B-") {
		for (int i = 0; i < 3; i++) {
			temp[2][1][i][2] = cubic[0][0][0][i];
			temp[2][0][i][0] = cubic[0][1][2][i];
		}
		temp[0][1][2][0] = cubic[2][1][2][2];
		temp[0][1][2][1] = cubic[2][1][1][2];
		temp[0][1][2][2] = cubic[2][1][0][2];
		temp[0][0][0][0] = cubic[2][0][2][0];
		temp[0][0][0][1] = cubic[2][0][1][0];
		temp[0][0][0][2] = cubic[2][0][0][0];

		temp[1][1][0][0] = cubic[1][1][0][2];
		temp[1][1][0][1] = cubic[1][1][1][2];
		temp[1][1][0][2] = cubic[1][1][2][2];
		temp[1][1][1][2] = cubic[1][1][2][1];
		temp[1][1][2][2] = cubic[1][1][2][0];
		temp[1][1][2][1] = cubic[1][1][1][0];
		temp[1][1][2][0] = cubic[1][1][0][0];
		temp[1][1][1][0] = cubic[1][1][0][1];
	}
	else if (com == "B+") {
		for (int i = 0; i < 3; i++) {
			temp[0][0][0][i] = cubic[2][1][i][2];
			temp[0][1][2][i] = cubic[2][0][i][0];
		}
		temp[2][1][2][2] = cubic[0][1][2][0];
		temp[2][1][1][2] = cubic[0][1][2][1];
		temp[2][1][0][2] = cubic[0][1][2][2];
		temp[2][0][2][0] = cubic[0][0][0][0];
		temp[2][0][1][0] = cubic[0][0][0][1];
		temp[2][0][0][0] = cubic[0][0][0][2];

		temp[1][1][0][2] = cubic[1][1][0][0];
		temp[1][1][1][2] = cubic[1][1][0][1];
		temp[1][1][2][2] = cubic[1][1][0][2];
		temp[1][1][2][1] = cubic[1][1][1][2];
		temp[1][1][2][0] = cubic[1][1][2][2];
		temp[1][1][1][0] = cubic[1][1][2][1];
		temp[1][1][0][0] = cubic[1][1][2][0];
		temp[1][1][0][1] = cubic[1][1][1][0];
	}
	else if (com == "L-") {
		for (int i = 0; i < 3; i++) {
			temp[0][0][i][0] = cubic[1][0][i][0];
			temp[1][0][i][0] = cubic[0][1][i][0];
		}
		temp[1][1][0][2] = cubic[0][0][2][0];
		temp[1][1][1][2] = cubic[0][0][1][0];
		temp[1][1][2][2] = cubic[0][0][0][0];
		temp[0][1][0][0] = cubic[1][1][2][2];
		temp[0][1][1][0] = cubic[1][1][1][2];
		temp[0][1][2][0] = cubic[1][1][0][2];

		temp[2][0][0][0] = cubic[2][0][0][2];
		temp[2][0][0][1] = cubic[2][0][1][2];
		temp[2][0][0][2] = cubic[2][0][2][2];
		temp[2][0][1][2] = cubic[2][0][2][1];
		temp[2][0][2][2] = cubic[2][0][2][0];
		temp[2][0][2][1] = cubic[2][0][1][0];
		temp[2][0][2][0] = cubic[2][0][0][0];
		temp[2][0][1][0] = cubic[2][0][0][1];
	}
	else if (com == "L+") {
		for (int i = 0; i < 3; i++) {
			temp[1][0][i][0] = cubic[0][0][i][0];
			temp[0][1][i][0] = cubic[1][0][i][0];
		}
		temp[0][0][2][0] = cubic[1][1][0][2];
		temp[0][0][1][0] = cubic[1][1][1][2];
		temp[0][0][0][0] = cubic[1][1][2][2];
		temp[1][1][2][2] = cubic[0][1][0][0];
		temp[1][1][1][2] = cubic[0][1][1][0];
		temp[1][1][0][2] = cubic[0][1][2][0];

		temp[2][0][0][2] = cubic[2][0][0][0];
		temp[2][0][1][2] = cubic[2][0][0][1];
		temp[2][0][2][2] = cubic[2][0][0][2];
		temp[2][0][2][1] = cubic[2][0][1][2];
		temp[2][0][2][0] = cubic[2][0][2][2];
		temp[2][0][1][0] = cubic[2][0][2][1];
		temp[2][0][0][0] = cubic[2][0][2][0];
		temp[2][0][0][1] = cubic[2][0][1][0];
	}
	else if (com == "R+") {
	for (int i = 0; i < 3; i++) {
		temp[0][0][i][2] = cubic[1][0][i][2];
		temp[1][0][i][2] = cubic[0][1][i][2];
		}
		temp[1][1][0][0] = cubic[0][0][2][2];
		temp[1][1][1][0] = cubic[0][0][1][2];
		temp[1][1][2][0] = cubic[0][0][0][2];
		temp[0][1][0][2] = cubic[1][1][2][0];
		temp[0][1][1][2] = cubic[1][1][1][0];
		temp[0][1][2][2] = cubic[1][1][0][0];

		temp[2][1][0][2] = cubic[2][1][0][0];
		temp[2][1][1][2] = cubic[2][1][0][1];
		temp[2][1][2][2] = cubic[2][1][0][2];
		temp[2][1][2][1] = cubic[2][1][1][2];
		temp[2][1][2][0] = cubic[2][1][2][2];
		temp[2][1][1][0] = cubic[2][1][2][1];
		temp[2][1][0][0] = cubic[2][1][2][0];
		temp[2][1][0][1] = cubic[2][1][1][0];
		}
	else if (com == "R-") {
		for (int i = 0; i < 3; i++) {
			temp[1][0][i][2] = cubic[0][0][i][2];
			temp[0][1][i][2] = cubic[1][0][i][2];
		}
		temp[0][0][2][2] = cubic[1][1][0][0];
		temp[0][0][1][2] = cubic[1][1][1][0];
		temp[0][0][0][2] = cubic[1][1][2][0];
		temp[1][1][2][0] = cubic[0][1][0][2];
		temp[1][1][1][0] = cubic[0][1][1][2];
		temp[1][1][0][0] = cubic[0][1][2][2];

		temp[2][1][0][0] = cubic[2][1][0][2];
		temp[2][1][0][1] = cubic[2][1][1][2];
		temp[2][1][0][2] = cubic[2][1][2][2];
		temp[2][1][1][2] = cubic[2][1][2][1];
		temp[2][1][2][2] = cubic[2][1][2][0];
		temp[2][1][2][1] = cubic[2][1][1][0];
		temp[2][1][2][0] = cubic[2][1][0][0];
		temp[2][1][1][0] = cubic[2][1][0][1];
	}
}

/*
cubic[0][0] = up
cubic[0][1] = down
cubic[1][0] = front
cubic[1][1] = back
cubic[2][0] = left
cubic[2][1] = right
*/

void apply() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					cubic[i][j][k][l] = temp[i][j][k][l];
				}
			}
		}
	}
}

void reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cubic[0][0][i][j] = "w";
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cubic[0][1][i][j] = "y";
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cubic[1][0][i][j] = "r";
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cubic[1][1][i][j] = "o";
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cubic[2][0][i][j] = "g";
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cubic[2][1][i][j] = "b";
		}
	}
}

void print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cubic[0][0][i][j];
		}
		cout << "\n";
	}
}


int main(){
	cin >> n;
	while (n--) {
		reset();
		cin >> num;
		while (num--) {
			cin >> command;
			cubing(command);
			apply();
		}
		print();
	}


	return 0;
}