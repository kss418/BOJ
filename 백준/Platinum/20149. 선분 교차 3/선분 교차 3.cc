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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 4; // SET MAX SIZE
constexpr ll MOD = 998244353;
pld a[MAX];

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
};

class _line{ // a >= 1e12 예외 처리 하기
public:
    ld a, b;
    _line(){}
    _line(pld v1, pld v2){
        ld dx = v2.x - v1.x;
        ld dy = v2.y - v1.y;
        if(v2.x == v1.x) a = 1e12 + 1;
        else a = dy / dx;

        if(a >= 1e12) b = v1.x;
        else b = -a * v1.x + v1.y;
    }
    _line(ld slope, pld v){ 
        a = slope; 
        b = (a >= 1e12) ? v.x : -a * v.x + v.y; 
    }

    ld integral(ld s, ld e){ return integral(e) - integral(s); }
    ld integral(ld x){ return (a * x * x) / (ld)2 + b * x; }
    ld f(ld x) { return a * x + b; }
    pld intersect(_line& ot){
        if(a == ot.a) return {1e12, 1e12};
        if(a == 1e12 + 1){ return {b, ot.f(b)}; }
        if(ot.a == 1e12 + 1){ return {ot.b, f(ot.b)}; }

        ld rx = (ot.b - b) / (a - ot.a), ry = f(rx);
        return {rx, ry};
    }
};

int main() {
    fastio;

    _li li;
    for(int i = 0;i < 4;i++) cin >> a[i].x >> a[i].y;
    bool inter = li.ret({a[0], a[1]}, {a[2], a[3]});

    cout << inter << "\n";
    if(!inter) return 0;

    _line l1(a[0], a[1]), l2(a[2],a[3]);
    pld p = l1.intersect(l2);

    cout.precision(20);
    if(l1.a == 1e12 + 1 && l2.a == 1e12 + 1){
        if(a[0].y > a[1].y) swap(a[0], a[1]);
        if(a[2].y > a[3].y) swap(a[2], a[3]);
        
        if(a[1].y == a[2].y) cout << a[1].x << " " << a[1].y;
        else if(a[0].y == a[3].y) cout << a[0].x << " " << a[0].y;
        return 0;
    }
    else if(p.x == 1e12) {
        if(a[0].x > a[1].x) swap(a[0], a[1]);
        if(a[2].x > a[3].x) swap(a[2], a[3]);

        if(a[1].x == a[2].x) cout << a[1].x << " " << a[1].y;
        else if(a[0].x == a[3].x) cout << a[0].x << " " << a[0].y;
        return 0; 
    }
    cout << p.x << " " << p.y;
    
     
    return 0;
}