#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;

    cin >> n >> m;
    ll x, y;
    cin >> y >> x >> k;

    ll nm = (k + y) % (2 * n);
    ll mm = (k + x) % (2 * m);

    if (nm >= n) cout << 2 * n - nm;
    else cout << nm;
    cout << " ";

    if (mm >= m) cout << 2 * m - mm;
    else cout << mm;
  





    return 0;
}