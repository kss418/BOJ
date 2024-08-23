#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 1e9 + 7;
ll arr[4], dp[MAX][101][101][101];

ll comb(ll r, ll g, ll b) {
    ll sum = r + g + b;
    ll fac, fr, fg, fb;
    fac = fr = fg = fb = 1;

    for (int i = 1; i <= sum; i++) fac *= i;
    for (int i = 1; i <= r; i++) fr *= i;
    for (int i = 1; i <= g; i++) fg *= i;
    for (int i = 1; i <= b; i++) fb *= i;

    return fac / (fr * fg * fb);
}

ll solve(ll cur, ll r, ll g, ll b) {
    if (r < 0 || g < 0 || b < 0) return 0;
    if (cur == n) return 1;
    ll& ret = dp[cur][r][g][b];
    if (ret != -1) return ret; ret = 0;
    
    ll use = cur + 1;
    ret += solve(cur + 1, r - use, g, b);
    ret += solve(cur + 1, r , g - use, b);
    ret += solve(cur + 1, r , g, b - use);

    use = (cur + 1) / 2;
    if ((cur + 1) % 2 == 0) {
        ll fac = comb(use, use, 0);
        ret += solve(cur + 1, r - use, g - use, b) * fac;
        ret += solve(cur + 1, r, g - use, b - use) * fac;
        ret += solve(cur + 1, r - use, g, b - use) * fac;
    }

    use = (cur + 1) / 3;
    if ((cur + 1) % 3 == 0) {
        ll fac = comb(use, use, use);
        ret += solve(cur + 1, r - use, g - use, b - use) * fac;
    }
     

    return ret;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= 3; i++) cin >> arr[i];


    memset(dp, -1, sizeof(dp));
    cout << solve(0, arr[1], arr[2], arr[3]);

    return 0;
}