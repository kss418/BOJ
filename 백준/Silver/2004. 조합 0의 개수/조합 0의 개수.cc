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
    cin >> n >> m;

    ll two = 0, five = 0;
    for (ll i = 2; i <= n; i *= 2) {
        two += n / i; two -= m / i + (n - m) / i;
    }

    for (ll i = 5; i <= n; i *= 5) {
        five += n / i; five -= m / i + (n - m) / i;
    }

    cout << min(two, five);

    return 0;
}