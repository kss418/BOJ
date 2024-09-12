#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 1e9 + 7;
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
ll arr[MAX];

int main() {
    fastio;
   
    cin >> n >> m;
    _gcd gcd;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ll g = 360; for (int i = 1; i <= n; i++) g = gcd.ret(arr[i], g);

    for (int i = 1; i <= m; i++) {
        cin >> k;
        if (k % g) cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}