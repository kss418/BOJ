#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

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

    ll cx, cy, nx, ny, dx, dy;
    cin >> cx >> cy;
    cin >> nx >> ny >> dx >> dy;
    _gcd gcd;

    ll diff = INF;
    pll result;
    ll g = gcd.ret(dx, dy);
    dx /= g; dy /= g;

    for(int i = 0;i <= 1000;i++){
        ll x = nx + dx * i;
        ll y = ny + dy * i; 
        ll cd = (x - cx) * (x - cx);
        cd += (y - cy) * (y - cy);


        if(cd >= diff) continue;
        diff = cd;
        result = {x, y};
    }

    cout << result.x << " " << result.y;


    return 0;
}