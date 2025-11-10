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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX]; ll co[MAX];

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n, sz;
    class node{
    public:
        ll v;
        node() : node(0){} // identity
        node(ll v) : v(v) {}
        
        node operator += (node ot){ // add
            v += ot.v;
            return *this;
        }

        operator T(){ // query
            return v;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) : n(n){ 
        sz = 1; while(sz < n + 1) sz <<= 1ll;
        seg.assign(2 * sz, node());
    }

    node merge(node l, node r){
        return{
            l.v + r.v
        };
    }

    node query(ll st, ll en) {
        st = max(0ll, st); en = min(n, en);
        if(st > en) return node();

        node l = node(), r = node();
        st += sz; en += sz;
        while(st <= en){
            if(st & 1) l = merge(l, seg[st++]);
            if(!(en & 1)) r = merge(seg[en--], r);
            st >>= 1; en >>= 1; 
        }

        return merge(l, r);
    }

    void set(ll idx, node val){
        if(idx < 0 || idx > n) return;
        ll p = idx + sz;
        seg[p] = val;
        for(p >>= 1ll; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void add(ll idx, node val){
        if(idx < 0 || idx > n) return;
        ll p = idx + sz;
        seg[p] += val;
        for(p >>= 1; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void clear(){ fill(all(seg), node()); }
};

vector <ll> xv, yv;
vector <pll> arr[MAX];
map <ll, ll> xc, yc;
void comp(vector<ll>& v, map <ll, ll>& c){
    sort(all(v)); ll cnt = 0;
    for(auto& i : v){
        if(!c.count(i)) c[i] = ++cnt;
    }
}   

void run(){
    cin >> n >> m >> k; _seg seg(n);
    for(int i = 1;i <= n;i++) {
        ll num; cin >> num;
        seg.set(i, num);
    } 

    for(int i = 1;i <= m + k;i++){
        ll op, idx, v; cin >> op >> idx >> v;
        if(op == 1) seg.set(idx, v);
        else cout << seg.query(idx, v) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

