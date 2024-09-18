#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
constexpr ll MOD = 1e9 + 7;
ll dp[MAX][MAX];

int main() {
    fastio;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }

    cout << dp[n][m];
    

    return 0;
}