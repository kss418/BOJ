#include <iostream>
#include <algorithm>
using namespace std;
int arr[500][500] = {};
int num;

void dfs(int n) {

    for (int i = 0; i <= 2 * n;i++) {
        arr[250 - 2 * n][250 - i] = 1;
        arr[250 + 2 * n][250 - i] = 1;
        arr[250 - 2 * n][250 + i] = 1;
        arr[250 + 2 * n][250 + i] = 1;
        arr[250 + i][250 + 2 * n] = 1;
        arr[250 - i][250 + 2 * n] = 1;
        arr[250 + i][250 - 2 * n] = 1;
        arr[250 - i][250 - 2 * n] = 1;
    }

    
    if (n != 0) {
        dfs(n - 1);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> num;
    dfs(num - 1);

    for (int i = 250 - 2 * num + 2; i < 250 + 2 * num - 1; i++) {
        for (int j = 250 - 2 * num + 2; j < 250 + 2 * num - 1; j++) {
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

