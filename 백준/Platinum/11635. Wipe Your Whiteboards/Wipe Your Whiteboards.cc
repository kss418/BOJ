#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

class _gcd {
public:
    _gcd() {}
    tll init(ll a, ll b) {
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

    cin >> t; _gcd gcd;
    while(t--){
        cin >> n >> m >> k; m *= -1;
        ll g = gcd.ret(n, m);
        n /= g; m /= g; k /= g;

        auto[a, x, y] = gcd.init(n, m);
        x *= k; y *= k;

        ll l = n * m / a;
        ll nu = l / n, mu = l / m;
        ll cnt = (x - 1) / nu;
        if((x - 1) % nu) cnt++;
        x -= nu * cnt; y += mu * cnt;

        if(y >= 0){
            ll cnt = (y + 1) / mu;
            if((y + 1) % mu) cnt++;
            x += nu * cnt; y -= mu * cnt;
        }
        
        cout << x << " " << -y << "\n";
    }



    return 0;
}