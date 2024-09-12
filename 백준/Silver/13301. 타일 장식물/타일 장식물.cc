#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
ll dp[MAX];

ll solve(ll cur) {
    if (cur < 0) return 0;
    ll& ret = dp[cur];
    if (ret != -1) return ret;
    ret = 0;

    ret = solve(cur - 1) + solve(cur - 2);
    return ret;
}

int main() {
    fastio;
   
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0; dp[1] = 1;
    ll ret[4] = { 0,4,6,10 };

    if (n < 4) cout << ret[n];
    else cout << 3 * solve(n) + 2 * solve(n - 1) + 2 * solve(n - 2) + solve(n - 3);


    return 0;
}