#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 2010;
constexpr ll MOD = 1e9 + 7;
ll dp[MAX][15];


int main() {
    fastio;

    cin >> n;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 15; j++) {
            dp[i + 1][(10 * j + 1) % 15] += dp[i][j % 15];
            dp[i + 1][(10 * j + 1) % 15] %= MOD;
            dp[i + 1][(10 * j + 5) % 15] += dp[i][j % 15];
            dp[i + 1][(10 * j + 5) % 15] %= MOD;
        }
    }

    cout << dp[n][0] % MOD;

    return 0;
}