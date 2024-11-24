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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

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

class _inter{ 
public:
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

    _inter(){}
    bool ret(vector<pll>& p, pll now){
        ll cnt = 0, flag = 0, sz = p.size();
        if(sz < 3) return 0;
        pll nxt = {1e12, now.y + 1};

        for(int i = 0;i < sz;i++){
            cnt += li.ret({p[i], p[(i + 1) % sz]}, {now, nxt});
        }

        for(int i = 0;i < sz;i++){
            flag += li.ret({p[i], p[(i + 1) % sz]}, {now, now});
        }

        return (cnt % 2 | flag);
    }
}; 


int main() {
    fastio;

    cin >> t; _inter inter;
    while(t--){
        cin >> n >> m; _ch b, w;
        for(int i = 1;i <= n;i++){
            pll a; cin >> a.x >> a.y;
            b.add(a);
        }
        b.init();

        for(int i = 1;i <= m;i++){
            pll a; cin >> a.x >> a.y;
            w.add(a);
        }
        w.init();

        vector <pll> bv = b.ret();
        vector <pll> wv = w.ret();

        bool result = 0;
        for(auto& i : bv) result |= inter.ret(wv, i);
        for(auto& i : wv) result |= inter.ret(bv, i);

        bv.push_back(bv[0]); wv.push_back(wv[0]);
        for(int i = 0;i < bv.size() - 1;i++){
            pair <pll, pll> cur = {bv[i], bv[i + 1]};
            for(int j = 0;j < wv.size() - 1;j++){
                pair <pll, pll> nxt = {wv[j], wv[j + 1]};
                result |= inter.li.ret(cur, nxt);
            }
        }

        if(result) cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}

