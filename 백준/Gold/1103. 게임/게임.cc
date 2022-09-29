#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[51][51];
int cnt[51][51];
char arr[51][51];
int x, y;
string ch;
bool br = 0;


void dfs(int curx, int cury, int value) {
    if (curx < 0 || curx >= x || cury < 0 || cury >= y) {
        return;
    }

    if (arr[cury][curx] == 'H') {
        return;
    }

    if (cnt[cury][curx] || br) {
        br = 1;
        return;
    }

    cnt[cury][curx] = 1;
    if (dp[cury][curx] < value) {
        dp[cury][curx] = value;
        dfs(curx + (int)(arr[cury][curx] - '0'), cury, value + 1);
        dfs(curx - (int)(arr[cury][curx] - '0'), cury, value + 1);
        dfs(curx, cury + (int)(arr[cury][curx] - '0'), value + 1);
        dfs(curx, cury - (int)(arr[cury][curx] - '0'), value + 1);
    }
    cnt[cury][curx] = 0;

    return;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> y >> x;
    for (int i = 0; i < y; i++) {
        cin >> ch;
        for (int j = 0; j < ch.size(); j++) {
            arr[i][j] = ch[j];
        }
    }
    
    fill(&dp[0][0], &dp[50][51], 0);
    dfs(0, 0, 1);
    int result = *max_element(&dp[0][0], &dp[50][51]);

    if (br) {
        cout << -1;
    }
    else {
        cout << result;
    }


    return 0;
}

