#include <iostream>
#include <algorithm>
using namespace std;
int arr[7000][7000];
int n;
    
void dfs(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        arr[y][i] = 1;
        arr[y + n - 1][i] = 1;
    }

    for (int i = y; i < y + n; i++) {
        arr[i][x] = 1;
        arr[i][x + n - 1] = 1;
    }

    if (n != 3) {
        for(int i = 0; i <= 2;i++){
            for (int j = 0; j <= 2; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                dfs(x + (n / 3) * i, y + (n / 3) * j, n / 3);
            }
        }
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    dfs(0, 0, n);
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}

