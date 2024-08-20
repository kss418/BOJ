#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 511;
constexpr ll MOD = 1e9 + 7;
long double dp[10101][MAX];


int main()
{
    fastio;
    cin >> n >> m;

    ll st, en;
    cin >> st >> en;

    dp[0][st] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) dp[i][j] += dp[i - 1][j - 1];
            if (j < n) dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] += dp[i - 1][j] * (n - 3 + (j == 1 || j == n ? 1 : 0));
            dp[i][j] /= static_cast<long double>(n - 1);
        }
    }

    cout.precision(10);
    cout << dp[m][en];


    return 0;
}