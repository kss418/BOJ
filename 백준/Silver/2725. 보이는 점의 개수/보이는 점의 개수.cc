#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 1e9 + 7;
ll dp[MAX][MAX], result[MAX];

class _gcd {
public:
    _gcd() {}

    tuple <ll, ll, ll> init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
};

int main() {
    fastio;

    _gcd gcd;

    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < i; j++) {
            if (gcd.ret(j, i) == 1) dp[j][i]++;
        }
    }

    for (int i = 1; i < MAX; i++) {
        result[i] = result[i - 1];
        for (int j = 1; j < i; j++) result[i] += dp[j][i];
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << 2 * result[n] + 3 << "\n";
    }
    

    return 0;
}
