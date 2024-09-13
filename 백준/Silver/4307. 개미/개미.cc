#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 1e9 + 7;

int main() {
    fastio;
    
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll mn = 0, mx = 0;
        for (int i = 1; i <= m; i++) {
            cin >> k;
            mn = max(mn, min(k, n - k));
            mx = max({ mx, k, n - k });
        }

        cout << mn << " " << mx << '\n';
    }
    

    return 0;
}