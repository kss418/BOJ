#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
constexpr ll MOD = 1e9 + 7;
ll dp[MAX];

int main() {
    fastio;

    cin >> t;
    while (t--) {
        string a, b;
        memset(dp, 0x3f, sizeof(dp));
        cin >> a >> b;

        dp[0] = 0;
        for (int i = 1; i <= a.size(); i++) {
            dp[i] = min(dp[i - 1] + 1, dp[i]);
            if (i + b.size() > a.size() + 1) continue;
            if (b == a.substr(i - 1, b.size())) dp[i + b.size() - 1] = dp[i - 1] + 1;
        }

        cout << dp[a.size()] << "\n";
    }
    


    return 0;
}