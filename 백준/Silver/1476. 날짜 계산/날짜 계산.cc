#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;

int main() {
    fastio;

    cin >> n >> m >> k;
    n--; m--; k--;

    ll cnt = 0;
    while (1) {
        ll nm, mm, km;
        nm = cnt % 15; mm = cnt % 28; km = cnt % 19;

        if (n == nm && m == mm && k == km) {
            cout << cnt + 1; break;
        }
        cnt++;
    }


    return 0;
}