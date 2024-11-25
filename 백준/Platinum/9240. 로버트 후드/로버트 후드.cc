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

class _rc{
public:
    _rc() {}
    vector <ll> num;
    vector <pll> point;
    ll cnt = 0;

    class node{
    public:
        ll x, y, dx, dy, idx;
        node(pll a, ll idx) : node(a.x, a.y, 1, 0, idx) {};
        node(ll x, ll y, ll dx, ll dy, ll idx){
            this->x = x; this->y = y;
            this->dx = dx; this->dy = dy;
            this->idx = idx;
        }

        bool operator <(node& ot){
            if(dy * ot.dx != dx * ot.dy) return dy * ot.dx < dx * ot.dy;
            if(y != ot.y) return y < ot.y;
            return x < ot.x;
        }
        operator pll(){ return { x, y }; }
    };
    vector <node> arr;

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

        ll area(ll a, ll b, ll c){ // div by 2
        ll num = 0;
        vector <pll> v = {point[a], point[b], point[c]};
        for(int i = 0;i < v.size();i++){
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[(i + 1) % v.size()];
            num += x1 * y2 - x2 * y1;
        }
        return abs(num);
    }

    ld dist(pld a, pld b) { 
        ld dx = a.x - b.x, dy = a.y - b.y;
        return sqrtl(dx * dx + dy * dy);
    }

    ld mx = 0; pair <pld, pld> result;
    void get(ll l, ll r){
        ll sz = point.size();
        for(int i = 0;i <= 1;i++){
            ll nxt = (r + i) % sz;
            ld now = dist(point[l], point[nxt]);
            if(mx > now) continue;
            mx = now; result = { point[l], point[nxt] };
        }
    }

    void init_rc(){
        ll sz = point.size();
        if(sz == 2) get(0, 1);
        else{
            ll l = 0, r = 1;
            while(area(sz - 1, l, r) < area(sz - 1, l, r + 1)) r++;
            while(r < sz){
                get(l, r);
                if(area(l, l + 1, r) < area(l, l + 1, (r + 1) % sz)) r++;
                else l++;
            }
        }
    }

    void init() { init_ch(); init_rc(); }
    pair <pld, pld> ret(){ return result; }
    ld dist(){ return mx; }
};


int main() {
    fastio;

    cin >> n; _rc rc;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        rc.add(a[i]);
    }
    rc.init();

    cout.precision(15);
    cout << rc.dist();
    
     
    return 0;
}