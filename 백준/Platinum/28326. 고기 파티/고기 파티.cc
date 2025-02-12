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
constexpr ll MAX = 251010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> v;
pll q[MAX];
map <ll, ll> mp;
ll result[MAX];
class node{
public:
    ll s, e, c;
    bool operator < (const node& ot) const{
        if(s != ot.s) return s < ot.s;
        return e < ot.e;
    }
} a[MAX];

template <typename T = pll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v, idx;
        node() : node(-1, 0){}
        node(ll v, ll idx) : v(v), idx(idx) {}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return {v, idx};
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(node l, node r){
        return{
            max(l.v, r.v),
            (l.v > r.v ? l.idx : r.idx)
        };
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    node update(ll idx, pll val) { return update(idx, val, 0, n); }
    node update(ll idx, pll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) {
            seg[node] = _seg::node(val.x, val.y);
            return seg[node];
        }
        ll mid = (l + r) >> 1;
        return seg[node] = merge(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));;
    }

    void add(ll idx, ll val) { add(idx, val, 0, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);
    }

    void clear(){ seg.clear(); seg.assign(4 * n + 1, node()); }
}; _seg seg;

void comp(){
    sort(all(v)); ll cnt = 0;
    for(auto& i : v){
        if(!mp.count(i)) mp[i] = ++cnt;
    }
}

void f(ll v, ll e, ll cur, bool pl = 0){
    while(1){
        auto[mx, idx] = seg.query(1, v);
        if(mx <= e) return;
        seg.update(idx, {-1, 0});
        if(pl) result[cur] += a[idx].c;
    }
}

vector <ll> num;
void run(){
    cin >> n >> m; seg = {n};
    for(int i = 1;i <= n;i++){
        cin >> a[i].s >> a[i].e >> a[i].c;
        v.push_back(a[i].s); v.push_back(a[i].e);
    }
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= m;i++){
        ll l, r; cin >> l >> r; q[i] = {l, r};
        v.push_back(l); v.push_back(r);
    }
    comp();

    for(int i = 1;i <= n;i++){
        auto& [s, e, c] = a[i];
        s = mp[s]; e = mp[e];
        num.push_back(s);
        seg.update(i, {e, i});
    }

    for(int i = 1;i <= m;i++){
        auto[l, r] = q[i];
        l = mp[l]; r = mp[r];
        ll li = upper_bound(all(num), l) - num.begin();
        ll ri = upper_bound(all(num), r) - num.begin();
        f(li, r, i, 1);
        f(li, l, i); f(ri, r, i);

        cout << result[i] << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}