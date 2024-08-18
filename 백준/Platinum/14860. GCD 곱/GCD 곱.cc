#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 15010101;
constexpr ll MOD = 1e9 + 7;
vector <ll> p;
short num[MAX];
ll result = 1;

ll powm(ll n, ll m, ll k = MOD) {
    if (m == 0) return 1;
    else if (m == 1) return n % k;

    ll ret = powm(n, m / 2, k) % k;
    ret *= ret % k; ret %= k;
    if (m & 1) ret *= n; ret %= k;

    return ret % k;
}


int main()
{
    fastio;
    cin >> n >> m;
    memset(num, -1, sizeof(num));

    for (int i = 2; i <= max(n, m); i++) {
        if (num[i] != -1) continue; num[i] = 1; p.push_back(i);
        for (int j = 2 * i; j <= max(n, m); j += i) num[j] = 0;
    }

    for (auto& i : p) {
        ll cur = powm(i, floor(n / i) * floor(m / i)) % MOD;
        ll cnt = i;
        for (int j = i * i; j <= max(n, m); j *= i) {
            cur *= powm(i, floor(n / (i * cnt)) * floor(m / (i * cnt)));
            cnt *= i; cur %= MOD;
        }

        result *= cur % MOD;
        result %= MOD;
    }

    cout << result % MOD;

 
    return 0;
}