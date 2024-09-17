#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
ll joy[MAX], l[MAX], dp[MAX][20 * MAX];

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> joy[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 99; j++) {
            if (j >= l[i]) dp[i][j] = dp[i - 1][j - l[i]] + joy[i];
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    ll result = 0;
    for (int i = 0; i < 100; i++) {
        if (!dp[n][i]) continue;
        result = max(result, dp[n][i]);
    }

    cout << result;


    return 0;
}