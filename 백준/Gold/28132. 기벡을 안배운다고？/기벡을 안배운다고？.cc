#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
map <pll, ll> cnt;
pll a[MAX];

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

    cin >> n; _gcd gcd; ll zero = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        if(!a[i].x && !a[i].y) zero++;
        else{
            ll g = abs(gcd.ret(a[i].x, a[i].y));
            a[i].x /= g; a[i].y /= g;
            cnt[a[i]]++;
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        if(!a[i].x && !a[i].y) continue;
        else {
            result += cnt[{-a[i].y, a[i].x}];
            result += cnt[{a[i].y, -a[i].x}];
        }
    }

    result >>= 1; result += zero * (zero - 1) / 2;
    result += zero * (n - zero);
    cout << result;


    return 0;
}

