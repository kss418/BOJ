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
ll a[MAX];

class _crt{
public:
    _crt(){} vector <pll> arr;
    tll gcd(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto[g, x, y] = gcd(b, a % b);
        return { g, y, x - a / b * y };
    }

    void clear(){ arr.clear(); }
    void add(ll a, ll m){ arr.push_back({a, m}); }

    ll mod(ll a, ll m){
        a %= m; if(a >= 0) return a;
        return a + m;
    }

    pll crt(pll a, pll b){
        auto[g, cx, cy] = gcd(a.y, b.y);
        ll lcd = a.y / g * b.y;
        if((b.x - a.x) % g) return {-1, -1};
        ll r = mod((b.x - a.x) / g, b.y); 
        ll l = mod(cx * r, b.y); 
        ll ret = mod(a.x + l * a.y, lcd);

        return { ret, lcd };
    }

    pll ret(){
        pll cur = arr[0];
        for(int i = 1;i < arr.size();i++){
            cur = crt(cur, arr[i]);
            if(cur.x == -1) return {-1, -1};
        }
        return cur;
    }
};

int main() {
    fastio;

    ll a, b; cin >> a >> b;
    vector <ll> box;
    for(int i = 1;i <= 100;i++){
        if(a <= 2 * i || b <= 2 * i) break;
        box.push_back((a - (2 * i)) * (b - (2 * i)) * i);
    }
    sort(all(box)); reverse(all(box));

    ll c, d, e; cin >> c >> d >> e; _crt crt;
    crt.add(c, box[0]); crt.add(d, box[1]); crt.add(e, box[2]);

    auto[result, lcd] = crt.ret();
    ll f, g; cin >> f >> g;
    if(g > result){
        ll cnt = (g - result) / lcd;
        result += cnt * lcd;
    }

    cout << result;


    return 0;
}