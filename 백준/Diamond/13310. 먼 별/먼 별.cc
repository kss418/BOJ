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
constexpr ll MAX = 30101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], b[MAX]; ll idx;

class _rc{
public:
    _rc() {}
    vector <ll> num; vector <pll> p; ll cnt = 0;

    class node{
    public:
        ll x, y, idx;
        node(pll a, ll idx) : node(a.x, a.y, idx) {};
        node(ll x, ll y, ll idx){
            this->x = x; this->y = y;
            this->idx = idx;
        }
        operator pll(){ return { x, y }; }
        operator pld(){ return { x, y }; }
    };
    vector <node> arr, st;

    ll ccw(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1;
        else if(num < 0) return -1;
        return 0;
    }
    
    void add(ll a, ll b) { add({a, b}); }
    void add(pll a){ arr.push_back({a, cnt++}); }

    void init_ch(){    
        swap(arr[0], *min_element(all(arr), [&](pll a, pll b){
            if(a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        }));

        sort(arr.begin() + 1, arr.end(), [&](pll a, pll b){
            ll dir = ccw(arr[0], {a.x, a.y}, {b.x, b.y});
            if(dir) return dir > 0;
            return d(arr[0], {a.x, a.y}) < d(arr[0], {b.x, b.y});
        });

        for(auto& i : arr){
            while(st.size() >= 2 && ccw(st[st.size() - 2], st.back(), i) <= 0) st.pop_back();
            st.push_back(i);
        }
        for(auto& i : st) p.push_back(i);
    }

    ll area(ll a, ll b, ll c){ // div by 2
        ll num = 0;
        vector <pll> v = {p[a], p[b], p[c]};
        for(int i = 0;i < v.size();i++){
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[(i + 1) % v.size()];
            num += x1 * y2 - x2 * y1;
        }
        return abs(num);
    }

    ld d(pld a, pld b) { // chk overflow
        ld dx = a.x - b.x, dy = a.y - b.y;
        return dx * dx + dy * dy;
    }

    ll mx = 0; pair <pll, pll> result;
    void get(ll l, ll r){
        ll sz = p.size();
        for(int i = 0;i <= 1;i++){
            ll nxt = (r + i) % sz;
            ll now = d(p[l], p[nxt]);
            if(mx > now) continue;
            mx = now; result = { p[l], p[nxt] };
        }
    }

    void init_rc(){
        ll sz = p.size();
        if(sz == 2) get(0, 1);
        else{
            ll l = 0, r = 1; ld now = 0;
            while(area(sz - 1, l, r) < area(sz - 1, l, r + 1)) r++;
            while(r < 2 * sz && l < sz){
                get(l, r);
                if(area(l, l + 1, r) < area(l, l + 1, r + 1)) r++;
                else l++;
            }
        }
    }

    void init() { init_ch(); init_rc(); }
    pair <pll, pll> ret(){ return result; }
    ll dist(){ return mx; }
};

class _ts { // 0-based index
public:
    ll l, r;
    _ts(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        _rc rc;
        for(int i = 1;i <= n;i++){
            ll cx = a[i].x + cur * b[i].x;
            ll cy = a[i].y + cur * b[i].y;
            rc.add({cx, cy});
        }
        rc.init();

        return rc.dist();
    }

    ll ret() {
        while (r - l > 3) {
            ll st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) > f(en)) l = st;
            else r = en;
        }

        ll result = INF;
        for(ll cur = l; cur <= r;cur++) {
            if(result <= f(cur)) continue;
            result = f(cur); idx = cur;
        }

        return result;
    }
};


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;

    _ts ts(0, m); ll ret = ts.ret();
    cout << idx << "\n" << ret;
    
     
    return 0;
}