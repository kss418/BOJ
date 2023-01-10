#include <iostream> 
#include <algorithm>
#include <vector> 
#include <cstring>
#include <deque> 
#include <set>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 51;
int dp[MAX][MAX][MAX];

void dfs(int a, int b, int c) {
    if (dp[a][b][c] != 0) {
        return;
    }

    if (a == 0 || b == 0 || c == 0) {
        dp[a][b][c] = 1;
        return;
    }

    if (a < b && b < c) {
        dfs(a, b, c - 1);
        dfs(a, b - 1, c - 1);
        dfs(a, b - 1, c);
        dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
        return;
    }
   
    dfs(a - 1, b, c);
    dfs(a - 1, b - 1, c);
    dfs(a - 1, b, c - 1);
    dfs(a - 1, b - 1, c - 1);
    dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c;
    int oa, ob, oc;

    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            return 0;
        }

        oa = a; ob = b; oc = c;
        if (a <= 0 || b <= 0 || c <= 0) {
            a = b = c = 0;
        }

        else if (a > 20 || b > 20 || c > 20) {
            a = b = c = 20;
        }


        dfs(a, b, c);
        cout << "w(" << oa << ", " << ob << ", " << oc << ") = ";
        cout << dp[a][b][c] << "\n";
    }

    return 0;
}