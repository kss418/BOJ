#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> arr;
int n, m, k, num;
string map[10];
pair <int, int> red, blue, origred, origblue;
int result = -1;
int code = 1;
vector <string> order;

void up() {
    map[red.second][red.first] = '.';

    while (red.second + 1 < n && map[red.second + 1][red.first] == '.') {
        red.second++;
    }
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = '.';

    while (blue.second + 1 < n && map[blue.second + 1][blue.first] == '.') {
        blue.second++;
    }
    map[blue.second][blue.first] = 'B';
    map[red.second][red.first] = '.';

    while (red.second + 1 < n && map[red.second + 1][red.first] == '.') {
        red.second++;
    }
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = '.';

    while (blue.second + 1 < n && map[blue.second + 1][blue.first] == '.') {
        blue.second++;
    }
    map[blue.second][blue.first] = 'B';

    if (red.second + 1 < n && map[red.second + 1][red.first] == 'O') {
        result = 1;
    }


    if (blue.second + 1 < n && map[blue.second + 1][blue.first] == 'O') {
        code = 0;
        result = -1;
        return;
    }

    if (blue.second + 2 < n && map[blue.second + 2][blue.first] == 'O' && map[blue.second + 1][blue.first] == 'R') {
        code = 0;
        result = -1;
    }
}

void down() {
    map[red.second][red.first] = '.';

    while (red.second - 1 >= 0 && map[red.second - 1][red.first] == '.') {
        red.second--;
    }
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = '.';

    while (blue.second - 1 >= 0 && map[blue.second - 1][blue.first] == '.') {
        blue.second--;
    }
    map[red.second][red.first] = '.';
    map[blue.second][blue.first] = 'B';

    while (red.second - 1 >= 0 && map[red.second - 1][red.first] == '.') {
        red.second--;
    }
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = '.';

    while (blue.second - 1 >= 0 && map[blue.second - 1][blue.first] == '.') {
        blue.second--;
    }
    map[blue.second][blue.first] = 'B';


    if (red.second - 1 >= 0 && map[red.second - 1][red.first] == 'O') {
        result = 1;

    }

    if (blue.second - 1 >= 0 && map[blue.second - 1][blue.first] == 'O') {
        code = 0;
        result = -1;
        return;
    }


    if (blue.second - 2 >= 0 && map[blue.second - 2][blue.first] == 'O' && map[blue.second - 1][blue.first] == 'R') {
        code = 0;
        result = -1;
    }
}

void left() {
    map[red.second][red.first] = '.';

    while (red.first - 1 >= 0 && map[red.second][red.first - 1] == '.') {
        red.first--;
    }
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = '.';

    while (blue.first - 1 >= 0 && map[blue.second][blue.first - 1] == '.') {
        blue.first--;
    }
    map[blue.second][blue.first] = 'B';
    map[red.second][red.first] = '.';

    while (red.first - 1 >= 0 && map[red.second][red.first - 1] == '.') {
        red.first--;
    }
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = '.';

    while (blue.first - 1 >= 0 && map[blue.second][blue.first - 1] == '.') {
        blue.first--;
    }

    map[blue.second][blue.first] = 'B';

    if (red.first - 1 >= 0 && map[red.second][red.first - 1] == 'O') {
        result = 1;
    }


    if (blue.first - 1 >= 0 && map[blue.second][blue.first - 1] == 'O') {
        code = 0;
        result = -1;
        return;
    }


    if (blue.first >= 2 && map[blue.second][blue.first - 2] == 'O' && map[blue.second][blue.first - 1] == 'R') {
        code = 0;
        result = -1;
    }
}

void right() {
    map[red.second][red.first] = '.';

    while (red.first + 1 < m && map[red.second][red.first + 1] == '.') {
        red.first++;
    }
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = '.';

    while (blue.first + 1 < m && map[blue.second][blue.first + 1] == '.') {
        blue.first++;
    }
    map[red.second][red.first] = '.';
    map[blue.second][blue.first] = 'B';

    while (red.first + 1 < m && map[red.second][red.first + 1] == '.') {
        red.first++;
    }
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = '.';

    while (blue.first + 1 < m && map[blue.second][blue.first + 1] == '.') {
        blue.first++;
    }
    map[blue.second][blue.first] = 'B';

    if (red.first + 1 < m && map[red.second][red.first + 1] == 'O') {
        result = 1;
    }

    while (blue.first + 1 < m && map[blue.second][blue.first + 1] == '.') {
        blue.first++;
    }

    if (blue.first + 1 < m && map[blue.second][blue.first + 1] == 'O') {
        code = 0;
        result = -1;
        return;
    }


    if (blue.first + 2 < m && map[blue.second][blue.first + 2] == 'O' && map[blue.second][blue.first + 1] == 'R') {
        code = 0;
        result = -1;
    }
}

void bt(int n) {
    if (result != -1) {
        return;
    }
    order.clear();
    red = { origred.first,origred.second };
    blue = { origblue.first,origblue.second };
    map[red.second][red.first] = 'R';
    map[blue.second][blue.first] = 'B';
    code = 1;
    if (arr.size() == n) {
        for (auto j : arr) {
            if (code == 0 || result == 1) {
                break;
            }
            if (j == 0) {
                order.push_back("D");
                up();
            }
            else if (j == 1) {
                order.push_back("U");
                down();
            }
            else if (j == 2) {
                order.push_back("L");
                left();
            }
            else {
                order.push_back("R");
                right();
            }
        }
        map[red.second][red.first] = '.';
        map[blue.second][blue.first] = '.';
        return;
    }



    for (int i = 0; i < 4; i++) {
        if (!arr.empty() && arr.back() == i) {
            continue;
        }

        arr.push_back(i);
        bt(n);
        arr.pop_back();


    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == 'R') {
                red = { j,i };
            }
            else if (map[i][j] == 'B') {
                blue = { j,i };
            }
        }
    }
    origred = { red.first, red.second };
    origblue = { blue.first, blue.second };
    red = { origred.first,origred.second };
    blue = { origblue.first,origblue.second };


    for (int i = 1; i <= 10; i++) {
        bt(i);
        if (result == 1) {
            break;
        }
    }
    
    if (result == -1) {
        result = 0;
    }

    cout << result;

    return 0;
}