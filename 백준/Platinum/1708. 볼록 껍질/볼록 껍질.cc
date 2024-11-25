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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
pll a[MAX];

class _ch{
public:
    _ch() {}
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
    };
    vector <node> arr, st;

    ll dist(pll v1, pll v2){
        ll dx = v1.x - v2.x, dy = v1.y - v2.y;
        return dx * dx + dy * dy;
    }

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
        swap(arr[0], *min_element(all(arr), [&](pll a, pll b){
            if(a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        }));

        sort(arr.begin() + 1, arr.end(), [&](pll a, pll b){
            ll dir = ccw(arr[0], {a.x, a.y}, {b.x, b.y});
            if(dir) return dir > 0;
            return dist(arr[0], {a.x, a.y}) < dist(arr[0], {b.x, b.y});
        });

        for(auto& i : arr){
            while(st.size() >= 2 && ccw(st[st.size() - 2], st.back(), i) <= 0) st.pop_back();
            st.push_back(i);
        }
        for(auto& i : st) p.push_back(i);
    }

    vector <pll> ret(){ return p; } // 좌표 반환
    vector <node> idx(){ return st; } 
};
int main() {
    fastio;

    cin >> n; _ch ch;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        ch.add(a[i]);
    }
    ch.init();

    cout << ch.ret().size() << "\n";


    return 0;
}

