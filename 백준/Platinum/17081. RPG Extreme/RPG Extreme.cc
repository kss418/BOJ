#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char arr[101][101];
int gridx, gridy, box, mon;
string mov;
string name[101][101];
int str[101][101], maxhp[101][101], sh[101][101], expr[101][101], curhp[101][101];
int pl_exp = 0, pl_level = 1, pl_hp = 20, pl_att = 0, pl_def = 0;
int turn = 0, ob_cnt = 0, hr = 0, re = 0, co = 0, ex = 0, dx = 0, hu = 0, cu = 0;
int cury, curx, sty, stx;;
string item[101][101];
int armor[101][101], weapon[101][101];
int ptr = 0, clear = 0, aturn = 0;

void moving() {
	if (mov[ptr] == 'L' && curx > 1 && arr[cury][curx - 1] != '#') {
		curx--;
	}
	else if (mov[ptr] == 'R' && curx < gridx && arr[cury][curx + 1] != '#') {
		curx++;
	}
	else if (mov[ptr] == 'U' && cury > 1 && arr[cury - 1][curx] != '#') {
		cury--;
	}
	else if (mov[ptr] == 'D' && cury < gridy  && arr[cury + 1][curx] != '#') {
		cury++;
	}
	ptr++;
	
	return;
}

void play() {
	if (arr[cury][curx] == '^') {
		if (dx) {
			pl_hp -= 1;
		}
		else {
			pl_hp -= 5;
		}
	}

	else if (arr[cury][curx] == 'B') {
		arr[cury][curx] = '.';
		if (item[cury][curx] == "W") {
			pl_att = weapon[cury][curx];
		}

		else if (item[cury][curx] == "A") {
			pl_def = armor[cury][curx];
		}

		else {
			if (ob_cnt < 4) {
				if (item[cury][curx] == "HR" && !hr) {
					hr = 1;
					ob_cnt++;
				}
				else if (item[cury][curx] == "RE" && !re) {
					re = 1;
					ob_cnt++;
				}
				else if (item[cury][curx] == "CO" && !co) {
					co = 1;
					ob_cnt++;
				}
				else if (item[cury][curx] == "EX" && !ex) {
					ex = 1;
					ob_cnt++;
				}
				else if (item[cury][curx] == "DX" && !dx) {
					dx = 1;
					ob_cnt++;
				}
				else if (item[cury][curx] == "HU" && !hu) {
					hu = 1;
					ob_cnt++;
				}
				else if (item[cury][curx] == "CU" && !cu) {
					cu = 1;
					ob_cnt++;
				}
			}
		}
	}

	else if (arr[cury][curx] == '&' || arr[cury][curx] == 'M') {
		aturn = 0;
		if (hu && arr[cury][curx] == 'M') {
			pl_hp = 15 + 5 * pl_level;
		}

		while (1) {
			aturn++;
			if (aturn == 1 && co && !dx) {
				curhp[cury][curx] -= max(1, 2 * (pl_att + 2 * pl_level) - sh[cury][curx]);
			}
			else if (aturn == 1 && co && dx) {
				curhp[cury][curx] -= max(1, 3 * (pl_att + 2 * pl_level) - sh[cury][curx]);
			}
			else {
				curhp[cury][curx] -= max(1, pl_att + 2 * pl_level - sh[cury][curx]);
			}

			
			if (curhp[cury][curx] <= 0) {
				if (ex) {
					pl_exp += (int)(expr[cury][curx] * 1.2);
				}
				else {
					pl_exp += expr[cury][curx];
				}

				if (arr[cury][curx] == 'M') {
					clear = 1;
				}
				arr[cury][curx] = '.';

				if (hr) {
					pl_hp = min(pl_hp + 3, 15 + 5 * pl_level);
				}

				break;
			}
			
			if (aturn != 1 || !hu || arr[cury][curx] == '&') {
				pl_hp -= max(1, str[cury][curx] - pl_def - 2 * pl_level);
			}
			
			if (pl_hp <= 0) {
				curhp[cury][curx] = maxhp[cury][curx];
				break;
			}
		}
	}

	return;
}

void result() {
	for (int i = 1; i <= gridy; i++) {
		for (int j = 1; j <= gridx; j++) {
			if (i == cury && j == curx && pl_hp > 0) {
				cout << '@';
			}
			else {
				cout << arr[i][j];
			}
		}
		cout << "\n";
	}

	printf("Passed Turns : %d\n", turn);
	printf("LV : %d\n", pl_level);
	printf("HP : %d/%d\n", pl_hp, 15 + pl_level * 5);
	printf("ATT : %d+%d\n", 2 * pl_level, pl_att);
	printf("DEF : %d+%d\n", 2 * pl_level, pl_def);
	printf("EXP : %d/%d\n", pl_exp, 5 * pl_level);

	return;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	

	cin >> gridy >> gridx;
	for (int i = 1; i <= gridy; i++) {
		for (int j = 1; j <= gridx; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '&' || arr[i][j] == 'M') {
				mon++;
			}
			else if (arr[i][j] == 'B') {
				box++;
			}
			else if (arr[i][j] == '@') {
				cury = i;
				curx = j;
				sty = i;
				stx = j;
				arr[i][j] = '.';
			}
		}
	}

	cin >> mov;
	int x, y, hp, a, b, e;
	string c;
	for (int i = 0; i < mon; i++) {
		cin >> y >> x >> c >> a >> b >> hp >> e;
		name[y][x] = c;
		str[y][x] = a;
		sh[y][x] = b;
		maxhp[y][x] = hp;
		curhp[y][x] = hp;
		expr[y][x] = e;
	}

	int n;
	string ob;
	for (int i = 0; i < box; i++) {
		cin >> y >> x >> c;
		if (c == "W") {
			cin >> n;
			item[y][x] = 'W';
			weapon[y][x] = n;
		}
		else if (c == "A") {
			cin >> n;
			item[y][x] = 'A';
			armor[y][x] = n;
		}
		else {
			cin >> ob;
			item[y][x] = ob;
		}
	}
	
	while (1) {
		if (ptr == mov.size()) {
			result();
			printf("Press any key to continue.");
			break;
		}
		moving();
		turn++;
		play();

		if (pl_exp >= 5 * pl_level) {
			pl_level++;
			pl_exp = 0;
			pl_hp = 15 + 5 * pl_level;
		}

		if (clear) {
			result();
			printf("YOU WIN!");
			break;
		}


		if (pl_hp <= 0 && re) {
			re = 0;
			ob_cnt--;
			cury = sty;
			curx = stx;
			pl_hp = 15 + 5 * pl_level;
		}

		if (pl_hp <= 0) {
			pl_hp = 0;
			result();
			if (arr[cury][curx] == '^') {
				printf("YOU HAVE BEEN KILLED BY SPIKE TRAP..");
			}
			else {
				printf("YOU HAVE BEEN KILLED BY %s..", name[cury][curx].c_str());
			}
			break;
		}
	}


	return 0;
}
