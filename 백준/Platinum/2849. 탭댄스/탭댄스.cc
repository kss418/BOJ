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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll lr, rr, mr, lv, rv, len;
        node() : node(1, 1, 1, 0, 0, 1){}
        node(ll lr, ll rr, ll mr, ll lv, ll rv, ll len) : 
        lr(lr), rr(rr), mr(mr), lv(lv), rv(rv), len(len) {}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return max({lr, rr, mr});
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(node l, node r){
        node ret; 
        ret.lr = l.lr; ret.rr = r.rr;
        ret.mr = max({l.mr, r.mr, l.rr, r.lr});
        if(r.lv != l.rv) {
            ret.mr = max(ret.mr, r.lr + l.rr);
            if(l.lr == l.len) ret.lr = max(ret.lr, l.lr + r.lr);
            if(r.rr == r.len) ret.rr = max(ret.rr, r.rr + l.rr);
        }
        ret.lv = l.lv; ret.rv = r.rv; ret.len = l.len + r.len;

        return ret;
    }

    T query(ll st, ll en) { return query(st, en, 1, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    node update(ll idx, ll val) { return update(idx, val, 1, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) {
            seg[node].lv = val;
            seg[node].rv = val;
            return seg[node];
        }
        ll mid = (l + r) >> 1;
        return seg[node] = merge(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));;
    }

    void clear(){ seg.clear(); seg.assign(4 * n + 1, node()); }
};


void run(){
    cin >> n >> m; _seg seg(n);
    for(int i = 1;i <= m;i++) seg.update(i, 0);
    while(m--){
        ll idx; cin >> idx;
        a[idx] ^= 1; seg.update(idx, a[idx]);
        cout << seg.query(1, n) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}