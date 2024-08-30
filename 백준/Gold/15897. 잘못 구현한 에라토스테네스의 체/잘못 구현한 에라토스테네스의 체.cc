#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;

int main() {
    fastio;
    cin >> n;

    ll result = 0;

    for (int i = 1; i * (i + 1) <= n; i++) {
        ll cur = n / i, nxt = n / (i + 1);
        result += (cur - nxt) * (i + 1);
        if (n % cur == 0) result--;
    }

    for (int i = 1; i * i <= n; i++) {
        if (n % i) result += n / i + 1;
        else result += n / i;
    }

    cout << result;

    return 0;
}