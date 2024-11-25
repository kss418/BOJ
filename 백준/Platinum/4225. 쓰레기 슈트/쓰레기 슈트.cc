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

class _ch{
public:
    _ch() {}
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

    void init(){
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

    vector <pll> ret(){ return point; } // 좌표 반환
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

ld dist(pld a, pld b){
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    return sqrtl(dx * dx + dy * dy);
}

int main() {
    fastio;

    ll cnt = 0;
    while(++cnt){
        cin >> n; if(!n) break; _ch ch;
        for(int i = 1;i <= n;i++) {
            cin >> a[i].x >> a[i].y;
            ch.add(a[i]);
        }
        ch.init();

        vector <pll> ret = ch.ret();
        ld result = 1e12; ll sz = ret.size();

        for(int i = 0;i < sz;i++){
            pll cur = ret[i], nxt = ret[(i + 1) % sz];
            _line l1(cur, nxt); ld now = 0;

            for(int j = 0;j < sz;j++){
                pll p = ret[j]; 
                ld slope = l1.a ? -1 / l1.a : 1e12 + 1;
                _line l2(slope, p);
                pld inter = l1.intersect(l2);
                now = max(now, dist(inter, p));
            }
            result = min(result, now);
        }

        cout << fixed << setprecision(2);
        result *= (ld)100;
        if(result - (ll)result > 1e-12){
            result += 1; result = (ll)result;
        }
        result /= (ld)100;

        cout << "Case " << cnt << ": " << result << "\n";
    }
    
     
    return 0;
}