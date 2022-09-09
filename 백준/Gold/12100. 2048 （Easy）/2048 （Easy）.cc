#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, num;
int arr[21][21];
int st[21][21];
int result = -1;
vector <int> command;

void re(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = st[i][j];
        }
    }
}



void up(int n) {
    for (int k = 0; k < n/2 + 1; k++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) {
                    int y = i;
                    while (y != n) {
                        arr[y][j] = arr[y + 1][j];
                        arr[y + 1][j] = 0;
                        y += 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == arr[i + 1][j]) {
                arr[i][j] *= 2;
                arr[i + 1][j] = 0;
                int y = i + 1;
                while (y != n) {
                    arr[y][j] = arr[y + 1][j];
                    arr[y + 1][j] = 0;
                    y += 1;
                }
            }
        }
    }
}
    
void down(int n) {
    for (int k = 0; k < n / 2 + 1; k++) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) {
                    int y = i;
                    while (y != 0) {
                        arr[y][j] = arr[y - 1][j];
                        arr[y - 1][j] = 0;
                        y -= 1;
                    }
                }
            }
        }
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == arr[i - 1][j]) {
                arr[i][j] *= 2;
                arr[i - 1][j] = 0;
                int y = i - 1;
                while (y != 0) {
                    arr[y][j] = arr[y - 1][j];
                    arr[y - 1][j] = 0;
                    y -= 1;
                }
            }
        }
    }
}

void left(int n) {
    for (int k = 0; k < n / 2 + 1; k++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[j][i] == 0) {
                    int x = i;
                    while (x != n) {
                        arr[j][x] = arr[j][x + 1];
                        arr[j][x + 1] = 0;
                        x += 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == arr[j][i + 1]) {
                arr[j][i] *= 2;
                arr[j][i + 1] = 0;
                int x = i + 1;
                while (x != n) {
                    arr[j][x] = arr[j][x + 1];
                    arr[j][x + 1] = 0;
                    x += 1;
                }
            }
        }
    }
}

void right(int n) {
    for (int k = 0; k < n / 2 + 1; k++) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < n; j++) {
                if (arr[j][i] == 0) {
                    int x = i;
                    while (x != 0) {
                        arr[j][x] = arr[j][x - 1];
                        arr[j][x - 1] = 0;
                        x -= 1;
                    }
                }
            }
        }
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == arr[j][i - 1]) {
                arr[j][i] *= 2;
                arr[j][i - 1] = 0;
                int x = i - 1;
                while (x != 0) {
                    arr[j][x] = arr[j][x - 1];
                    arr[j][x - 1] = 0;
                    x -= 1;
                }
            }
        }
    }
}


void bt() {
    if (command.size() == 5) {
        for (auto c : command) {
            if (c == 0) {
                up(n);
            }
            else if (c == 1) {
                down(n);
            }
            else if (c == 2) {
                left(n);
            }
            else {
                right(n);
            }
        }
        result = max(result, *max_element(&arr[0][0], &arr[20][21]));
        re(n);
        return;
    }
    for (int i = 0; i < 4; i++) {
        command.push_back(i);
        bt();
        command.pop_back();
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            arr[i][j] = num;
            st[i][j] = num;
        }
    }
    
    bt();

    cout << result;

    return 0;
}