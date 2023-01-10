#include <iostream> #include <algorithm>
#include <vector> #include <cstring>
#include <deque> #include <set>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 51;
double dp[MAX][MAX][MAX];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int x, y, num;
    cin >> n >> x >> y >> num;
    dp[x][y][0] = 1;

    for (int k = 1; k <= num; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int l = 0; l < 8; l++) {
                    if (i - dx[l] <= 0 || i - dx[l] > n || j - dy[l] <= 0 || j - dy[l] > n) {
                        continue;
                    }
                    dp[i][j][k] += dp[i - dx[l]][j - dy[l]][k - 1];
                }
                dp[i][j][k] /= 8;
            }
        }
    }
    
    double result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            result += dp[i][j][num];
        }
    }

    cout.precision(30);
    cout << result;

    return 0;
}