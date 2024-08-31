#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], g[101][101], able[101];

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
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) g[i][j] = gcd.ret(i, j);
    }

    while (1) {
        cin >> n; if (!n) break;
        memset(able, 0, sizeof(able));
        ll mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i]; mx = max(arr[i], mx);
            able[arr[i]] = 1;
        }

        for (ll cur = 1; cur <= mx; cur++) {
            if (able[cur]) continue;

            ll flag = 0;    
            ll num = arr[1];
            for (int i = 2; i <= n; i++) {
                num = g[num][arr[i]];
                if (num == cur) { flag = 1; break; }
                else if (num % cur) num = arr[i];
            }

            if (flag) able[cur] = 1;
        }

        ll result = 0;
        for (int i = 1; i <= mx; i++) result += able[i];

        cout << result << '\n';
    }

    return 0;
}