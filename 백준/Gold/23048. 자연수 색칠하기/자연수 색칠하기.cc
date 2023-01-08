#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 501010;
int dp[MAX];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n; 

    dp[1] = 1;
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (dp[i]) {
            continue;
        }

        cnt++;
        for (int j = i; j <= n; j += i) {
            dp[j] = cnt;
        }
    }

    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }

    return 0;
}