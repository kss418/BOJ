#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll x[3], y[3], mx, mn = INF;

class _area{
public:
    _area() {}
    ll ret(vector <pll>& v){ // div by 2
        ll num = 0;
        for(int i = 0;i < v.size();i++){
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[(i + 1) % v.size()];
            num += x1 * y2 - x2 * y1;
        }

        return abs(num);
    }
}; _area area;

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
}; _gcd g;

class line{
public:
    ll dx, dy, s, e, y1, y2;
    line(){}
    line(ll x1, ll y1, ll x2, ll y2){
        if(x1 > x2) swap(x1, x2), swap(y1, y2);
        s = x1; e = x2; 
        this->y1 = y1; this->y2 = y2;
        dx = x2 - x1; dy = y2 - y1;
        if(!dx) return;
        ll num = abs(g.ret(dx, dy));
        dx /= num; dy /= num;
    }

    vector <pll> mid(){
        if(!dx){
            ll m = (y1 + y2) / 2;
            ll pre = m, nxt = m + 1;
            ll x1 = (pre <= y1 || pre >= y2 ? INF : s);
            ll x2 = (nxt <= y1 || nxt >= y2 ? INF : s);
            return { {x1, pre} , {x2, nxt}};
        }

        ll num = (s % dx + dx) % dx;
        ll m = (s + e) / 2, mod = m % dx;
        ll pre = m - (mod - num), nxt = m + dx - (mod - num);
        pre = (pre <= s || pre >= e ? INF : pre);
        nxt = (nxt <= s || nxt >= e ? INF : nxt);

        return { {pre, (pre != INF ? f(pre) : INF)}, {nxt, (nxt != INF ? f(nxt) : INF)} };
    }
    
    vector <pll> last(){
        if(!dx){
            ll mn = min(y1, y2), mx = max(y1, y2);
            ll pre = mn + 1, nxt = mx - 1;
            ll x1 = (pre <= mn || pre >= mx ? INF : s);
            ll x2 = (nxt <= mn || nxt >= mx ? INF : s);
            return { {x1, pre} , {x2, nxt}};
        }

        ll pre = s + dx, nxt = e - dx;
        pre = (pre <= s || pre >= e ? INF : pre);
        nxt = (nxt <= s || nxt >= e ? INF : nxt);
        return { {pre, (pre != INF ? f(pre) : INF)}, {nxt, (nxt != INF ? f(nxt) : INF)} };
    }

    ll f(ll x){
        return ((x - s) / dx) * dy + y1; 
    }
}; line l[3];

void run(){
    for(int i = 0;i < 3;i++) cin >> x[i] >> y[i];
    for(int i = 0;i < 3;i++){
        l[i] = { x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3]};
    }

    for(auto& i : l[0].mid()){
        for(auto& j : l[1].mid()){
            for(auto& k : l[2].mid()){
                if(i.x == INF || j.x == INF || k.x == INF) continue;
                vector <pll> now = {i, j, k};
                ll a = area.ret(now);
                mx = max(mx, a); mn = min(mn, a);
            }
        }
    }

    for(auto& i : l[0].last()){
        for(auto& j : l[1].last()){
            for(auto& k : l[2].last()){
                if(i.x == INF || j.x == INF || k.x == INF) continue;
                vector <pll> now = {i, j, k};
                ll a = area.ret(now);
                mx = max(mx, a); mn = min(mn, a);
            }
        }
    }


    if(mn == INF) cout << -1;
    else cout << mx << " " << mn;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
