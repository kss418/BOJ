#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 31;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX][MAX], dp[MAX][MAX];


int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> arr[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) * 2 + arr[i][j];
        }
    }
    
    cout << dp[n][n];

   
    return 0;
}