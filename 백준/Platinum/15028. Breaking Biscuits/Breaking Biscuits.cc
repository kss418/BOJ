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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];

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

template <typename T = ll>
class _rc{
public:
    _rc() {}
    using ptl = pair<T, T>;
    vector <T> num;
    vector <ptl> point;
    ll cnt = 0;

    class node{
    public:
        T x, y, dx, dy; ll idx;
        node(ptl a, ll idx) : node(a.x, a.y, 1, 0, idx) {};
        node(T x, T y, T dx, T dy, ll idx){
            this->x = x; this->y = y;
            this->dx = dx; this->dy = dy;
            this->idx = idx;
        }

        bool operator <(node& ot){
            if(dy * ot.dx != dx * ot.dy) return dy * ot.dx < dx * ot.dy;
            if(y != ot.y) return y < ot.y;
            return x < ot.x;
        }
        operator ptl(){ return { x, y }; }
    };
    vector <node> arr;

    ll ccw(ptl v1, ptl v2, ptl v3){
        T num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1;
        else if(num < 0) return -1;
        return 0;
    }
    
    void add(T a, T b) { add({a, b}); }
    void add(ptl a){ arr.push_back({a, cnt++}); }

    void init_ch(){
        sort(all(arr));
        for(int i = 1;i < arr.size();i++){
            arr[i].dx = arr[i].x - arr[0].x;
            arr[i].dy = arr[i].y - arr[0].y;
        }
        sort(arr.begin() + 1, arr.end());

        num.push_back(0);
        if(arr.size() == 1) {
            point.push_back(arr[0]); return;
        }
        num.push_back(1);
        ll nxt = 2;

        while(nxt < arr.size()){
            while(num.size() >= 2){
                ll fi = num.back(); num.pop_back();
                ll se = num.back();
                ll chk = ccw(arr[se], arr[fi], arr[nxt]);
                if(chk > 0){ num.push_back(fi); break; }
            }
            num.push_back(nxt++);
        }

        for(auto& i : num) point.push_back(arr[i]);
    }

    T area(ll a, ll b, ll c){ // div by 2
        T num = 0; ll sz = point.size();
        a %= sz; b %= sz; c %= sz;
        vector <ptl> v = {point[a], point[b], point[c]};
        for(int i = 0;i < v.size();i++){
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[(i + 1) % v.size()];
            num += x1 * y2 - x2 * y1;
        }
        return abs(num);
    }

    T d(ptl a, ptl b) { // chk overflow
        T dx = a.x - b.x, dy = a.y - b.y;
        return dx * dx + dy * dy;
    }

    ld mx = 1e12; pair <ptl, ptl> result;
    ld get(ll l, ll r){
        ll sz = point.size(); ld ret = 0;
        l %= sz; r %= sz;
        _line l1 = {point[l], point[(l + 1) % sz]};

        for(int i = 0;i <= 1;i++){
            ll nxt = (r + i) % sz;
            ld slope = l1.a ? -1 / l1.a : 1e12 + 1;
            _line l2(slope, point[nxt]);
            pld inter = l1.intersect(l2);

            ret = max(ret, d(inter, point[nxt]));
        }

        return ret;
    }

    void init_rc(){
        ll sz = point.size();
        if(sz == 2) get(0, 1);
        else{
            ll l = 0, r = 1; ld now = 0;
            while(area(sz - 1, l, r) < area(sz - 1, l, r + 1)) r++;
            while(r < 2 * sz && l < sz){
                now = max(get(l, r), now);
                if(area(l, l + 1, r) < area(l, l + 1, r + 1)) r++;
                else {
                    l++;if(now != 0) mx = min(now, mx); now = 0;
                }
            }
            if(now != 0) mx = min(now, mx);
        }
    }

    void init() { init_ch(); init_rc(); }
    pair <ptl, ptl> ret(){ return result; }
    ld dist(){ return sqrtl(mx); }
};

int main() {
    fastio;

    cin >> n; _rc <ld> rc;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        rc.add(a[i]);
    }
    rc.init();

    cout.precision(20);
    cout << rc.dist();
    
     
    return 0;
}