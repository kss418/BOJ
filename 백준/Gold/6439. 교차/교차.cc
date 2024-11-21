#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll s, e, a, b;

class _li{
public:
    _li() {}

    ll ccw(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; 
        else if(num < 0) return -1; 
        return 0;
    }

    bool ret(pair<pll, pll> a, pair<pll, pll> b) {
        return ret(a.x, a.y, b.x, b.y);
    }
    bool ret(pll av1, pll av2, pll bv1, pll bv2){
        ll ac = ccw(av1, av2, bv1) * ccw(av1, av2, bv2);
        ll bc = ccw(bv1, bv2, av1) * ccw(bv1, bv2, av2);

        if(!ac && !bc){
            if(av1 > av2) swap(av1, av2);
            if(bv1 > bv2) swap(bv1, bv2);
            return bv1 <= av2 && av1 <= bv2;
        }

        return ac <= 0 && bc <= 0;
    }
}; _li li;

class _line{
public:
    ld a, b;
    _line(){}
    _line(pld v1, pld v2){
        ld dx = v2.x - v1.x;
        ld dy = v2.y - v1.y;
        if(v2.x == v1.x) a = 1e12 + 1;
        else a = dy / dx;

        if(a >= 1e12) b = 0;
        else b = -a * v1.x + v1.y;
    }

    ld integral(ld s, ld e){ return integral(e) - integral(s); }
    ld integral(ld x){ return (a * x * x) / (ld)2 + b * x; }

    ld f(ld x) { return a * x + b; }
}; _line l;

bool intersect(){
    bool ret = 0;
    ret |= li.ret({s, e}, {{a.x, a.y}, {b.x, a.y}});
    ret |= li.ret({s, e}, {{a.x, a.y}, {a.x, b.y}});
    ret |= li.ret({s, e}, {{b.x, a.y}, {b.x, b.y}});
    ret |= li.ret({s, e}, {{a.x, b.y}, {b.x, b.y}});
    return ret;
}

bool in(){
    bool ret = 0;
    if(s.x == e.x){
        if(s.y >= a.y && s.y <= b.y) ret = 1;
        if(e.y >= a.y && e.y <= b.y) ret = 1;
    }
    else{
        if(l.f(s.x) <= b.y && l.f(s.x) >= a.y) {
            if(s.x >= a.x && s.x <= b.x) ret = 1;
        }
        if(l.f(e.x) <= b.y && l.f(e.x) >= a.y) {
            if(e.x >= a.x && e.x <= b.x) ret = 1;
        }
    }
    return ret;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> s.x >> s.y >> e.x >> e.y;
        cin >> a.x >> a.y >> b.x >> b.y;
        if(a.x > b.x) swap(a.x, b.x);
        if(a.y > b.y) swap(a.y, b.y);
        l = {s, e};

        bool ret = 0;
        ret |= (intersect() | in());
        if(ret) cout << "T\n";
        else cout << "F\n";
    }
    
     
    return 0;
}