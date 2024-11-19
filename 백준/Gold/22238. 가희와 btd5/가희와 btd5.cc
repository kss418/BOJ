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
ll a[MAX];

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
map <pll, vector<ll>> num;
map <pll, ll> dmg, cnt;

int main() {
    fastio;

    cin >> n >> m; _gcd gcd;
    for(int i = 1;i <= n;i++){
        ll x, y, h; cin >> x >> y >> h;
        ll g = abs(gcd.ret(x, y));
        x /= g; y /= g;

        num[{x, y}].push_back(h);
        cnt[{x, y}]++;
    }

    ll all = n;
    for(auto& i : num) sort(all(i.y));
    while(m--){
        ll x, y, h; cin >> x >> y >> h;
        ll g = abs(gcd.ret(x, y));
        x /= g; y /= g; dmg[{x, y}] += h;

        ll& pre = cnt[{x, y}], cur = num[{x, y}].size();
        cur -= upper_bound(num[{x, y}].begin(), num[{x, y}].end(), dmg[{x, y}]) - num[{x, y}].begin();

        all -= pre - cur; pre = cur;
        cout << all << "\n";
    }


    return 0;
}

