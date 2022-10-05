#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[17][1 << 17], arr[17][17];
string ch;
int n, onst = 0, stvi = 0, en, result = 1e9;


int dfs(int cur, int visit, int onto) {
    int& ret = dp[cur][visit];
    if (ret != -1) {
        return ret;
    }
    
    if (onto >= en) {
        return 0;
    }

    dp[cur][visit] = 1e9;
    for (int i = 0; i < n; i++) {
        if (!(visit & (1 << i))) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (visit & (1 << j)) {
                continue;
            }
            dp[cur][visit] = min(dp[cur][visit], dfs(j, visit | (1 << j), onto + 1) + arr[i][j]);
        }
    }

    return dp[cur][visit];
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    fill(&dp[0][0], &dp[16][1 << 17], -1);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> ch;
    for (int i = 0; i < n; i++) {
        if (ch[i] == 'Y') {
            onst++;
            stvi |= (1 << i);
        }
    }
    cin >> en;

    if (onst == 0 && en != 0) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        result = min(result, dfs(i, stvi, onst));
    }

    cout << result;

    return 0;
}

