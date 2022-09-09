#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int x, y, n;
int a, b, s, d, si;
pair <pair<int, int>, int> arr[101][101] = {};
int fisher = 1;
int result = 0;
pair<pair<int, int>, int> tmparr[101][101] = {};
pair <int, int> temp;

void fish() {
    for (int i = 1; i < y + 1; i++) {
        if (arr[i][fisher].second != 0) {
            result += arr[i][fisher].second;
            arr[i][fisher].first.first = 0;
            arr[i][fisher].first.second = 0;
            arr[i][fisher].second = 0;
            break;
        }
    }
    fisher += 1;
    return;
}

void direction(int i, int j) {
    if (temp.first == 1 && arr[i][j].first.second == 4) {
        arr[i][j].first.second = 3;
    }
    else if (temp.first == x && arr[i][j].first.second == 3) {
        arr[i][j].first.second = 4;
    }
    else if (temp.second == y && arr[i][j].first.second == 2) {
        arr[i][j].first.second = 1;
    }
    else if (temp.second == 1 && arr[i][j].first.second == 1) {
        arr[i][j].first.second = 2;
    }
    return;
}

void apply() {
    for (int i = 1; i < y + 1; i++) {
        for (int j = 1; j < x + 1; j++) {
            arr[i][j] = tmparr[i][j];
            tmparr[i][j] = { {0,0},0 };
        }
    }
    return;
}

void move() {
    for (int i = 1; i < y + 1; i++) {
        for (int j = 1; j < x + 1; j++) {
            if (arr[i][j].second == 0) {
                continue;
            }

            temp.first = j;
            temp.second = i;
            int speed = 0;
            if (arr[i][j].first.second == 1 || arr[i][j].first.second == 2) {
                speed = (y - 1) * 2;
            }
            else {
                speed = (x - 1) * 2;
            }
            for (int k = 0; k < arr[i][j].first.first % speed; k++) {
                direction(i, j);
                if (arr[i][j].first.second == 1) {
                    temp.second -= 1;
                }
                else if (arr[i][j].first.second == 2) {
                    temp.second += 1;
                }
                else if (arr[i][j].first.second == 3) {
                    temp.first += 1;
                }
                else if (arr[i][j].first.second == 4) {
                    temp.first -= 1;
                }
            }

            if (tmparr[temp.second][temp.first].second == 0) {
                tmparr[temp.second][temp.first].first.first = arr[i][j].first.first;
                tmparr[temp.second][temp.first].first.second = arr[i][j].first.second;
                tmparr[temp.second][temp.first].second = arr[i][j].second;
            }
            else {
                if (tmparr[temp.second][temp.first].second < arr[i][j].second) {
                    tmparr[temp.second][temp.first].first.first = arr[i][j].first.first;
                    tmparr[temp.second][temp.first].first.second = arr[i][j].first.second;
                    tmparr[temp.second][temp.first].second = arr[i][j].second;
                }
            }

            arr[i][j].first.first = 0;
            arr[i][j].first.second = 0;
            arr[i][j].second = 0;
        }
    }
    apply();
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> y >> x >> n;
    while (n--) {
        cin >> a >> b >> s >> d >> si;
        arr[a][b] = { {s,d},si };
    }

    while (fisher != x + 1) {
        fish();
        move();
    }

    cout << result;
    return 0;
}