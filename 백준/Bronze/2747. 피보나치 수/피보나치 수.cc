#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
constexpr ll MOD = 1e9 + 7;
ll dp[MAX];

ll solve(ll n) {
    ll &ret = dp[n];
    if (ret != -1) return ret;
    ret = solve(n - 1) + solve(n - 2);
    return ret;
}

int main() {
    fastio;

    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0; dp[1] = 1;

    cout << solve(n);

    return 0;
}