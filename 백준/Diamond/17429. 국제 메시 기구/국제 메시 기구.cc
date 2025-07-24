#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
using ull = unsigned ll;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 1ll << 32;

template <typename T = ll> // query type
class _prop { // 구간 예외 처리하기
public:
    class node{
    public:
        ull v, len;
        node() : node(0, 0){}
        node(ull v, ull len) : v(v), len(len){}
        
        node& operator += (node ot){ // add
            return *this;
        }

        operator T(){ // node -> query
            return v;
        }
    };

    class lazy_type{
    public:
        ull a, b;
        lazy_type() : lazy_type(1, 0){}
        lazy_type(ull a, ull b) : a(a), b(b){}

        lazy_type& operator += (lazy_type ot){ // add
            a *= ot.a; b *= ot.a;
            b += ot.b;
            a %= MOD; b %= MOD;

            return *this;
        }
    };

    vector<node> seg, tmp; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { (l.v + r.v) % MOD, l.len + r.len };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return lazy.a == 1 && lazy.b == 0;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s += p;
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v *= lazy.a; seg.v %= MOD;
        seg.v += seg.len * lazy.b;
        seg.v %= MOD;
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = {1, 0};
    }

    _prop() {}
    _prop(ll n) {
        this->n = n; seg.resize(4 * n + 1, node()); 
        lazy.resize(4 * n + 1, lazy_type());
        tmp.resize(4 * n + 1, node()); 
    }

    void propagate(ll l, ll r, ll node) {
        if (empty(lazy[node])) return;
        if (l != r) {
            prop(lazy[node * 2], lazy[node]);
            prop(lazy[node * 2 + 1], lazy[node]);
        }
        cal(lazy[node], seg[node]);
        erase(lazy[node]);
    }

    void add(ll st, ll en, ull val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ull val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].b += val; 
            lazy[node].b %= MOD;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void mul(ll st, ll en, ull val) { mul(st, en, val, 0, n); }
    void mul(ll st, ll en, ull val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].a *= val; lazy[node].a %= MOD;
            lazy[node].b *= val; lazy[node].b %= MOD;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        mul(st, en, val, l, mid, node * 2);
        mul(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return _prop::node();
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }
    
    void set(ll idx, node val){
        tmp[idx] = val;
    }

    void init(){ init(0, n); }
    void init(ll l, ll r, ll node = 1){
        if(l == r){
            seg[node] = tmp[l];
            return;
        }

        ll mid = (l + r) >> 1ll;
        init(l, mid, node * 2);
        init(mid + 1, r, node * 2 + 1);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }
}; _prop seg;

template <typename T = ll> //query type
class _hld { // m = 0 정점, m = 1 간선
public:
    vector <vector <ll>> adj;
    vector <ll> sz, top, d, in, out, p;
    ll n, m, cnt = 0;

    _hld() {}
    _hld(ll n, ll m = 0){
        this->n = n; this->m = m;
        adj.resize(n + 1); sz.resize(n + 1);
        in.resize(n + 1); out.resize(n + 1);
        d.resize(n + 1); p.resize(n + 1);
        top.resize(n + 1); 
    }

    void add(ll s, ll e){
        addsol(s, e); addsol(e, s);
    }   
    void addsol(ll s, ll e, ll c = 1){ adj[s].push_back(e); }

    void dfs1(ll cur, ll pre){
        sz[cur] = 1;
        for(auto& nxt : adj[cur]){
            if(nxt == pre) continue;
            d[nxt] = d[cur] + 1; p[nxt] = cur;
            dfs1(nxt, cur); sz[cur] += sz[nxt];
            if(sz[nxt] > sz[adj[cur][0]]) swap(nxt, adj[cur][0]);
        }
    }

    void dfs2(ll cur, ll pre){
        in[cur] = ++cnt;
        for(auto& nxt : adj[cur]){
            if(nxt == pre) continue;
            top[nxt] = (nxt == adj[cur][0] ? top[cur] : nxt);
            dfs2(nxt, cur);
        }
        out[cur] = cnt;
    }

    void init(){
        for(int i = 1;i <= n;i++){
            if(sz[i]) continue;
            dfs1(i, -1); dfs2(i, -1);
        }
    }

    T query(ll st, ll en) { 
        //_seg<>::node ret;
        _prop<>::node ret;
        while(top[st] != top[en]){
            if(d[top[st]] < d[top[en]]) swap(st, en);
            ll cur = top[st];
            ret = seg.merge(ret, seg.query(in[cur], in[st], 0, n));
            st = p[cur];
        }

        if(d[st] > d[en]) swap(st, en);
        ret = seg.merge(ret, seg.query(in[st] + m, in[en], 0, n));
        return ret; 
    }

    void add_lazy(ll st, ll en, ull val){
        while(top[st] != top[en]){
            if(d[top[st]] < d[top[en]]) swap(st, en);
            ll cur = top[st];
            seg.add(in[cur], in[st], val);
            st = p[cur];
        }

        if(d[st] > d[en]) swap(st, en);
        seg.add(in[st] + m, in[en], val);
    }

    void mul_lazy(ll st, ll en, ull val){
        while(top[st] != top[en]){
            if(d[top[st]] < d[top[en]]) swap(st, en);
            ll cur = top[st];
            seg.mul(in[cur], in[st], val);
            st = p[cur];
        }

        if(d[st] > d[en]) swap(st, en);
        seg.mul(in[st] + m, in[en], val);
    }
}; 

void run(){
    cin >> n >> m; _hld hld(n); seg = {n};
    for(int i = 1;i <= n;i++) seg.set(i, {0, 1}); seg.init();
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        hld.add(s, e);
    }
    hld.init();

    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll idx, v; cin >> idx >> v;
            seg.add(hld.in[idx], hld.out[idx], v);
        }
        else if(op == 2){
            ll s, e, v; cin >> s >> e >> v;
            hld.add_lazy(s, e, v);
        }
        else if(op == 3){
            ll idx, v; cin >> idx >> v;
            seg.mul(hld.in[idx], hld.out[idx], v);
        }
        else if(op == 4){
            ll s, e, v; cin >> s >> e >> v;
            hld.mul_lazy(s, e, v);
        }
        else if(op == 5){
            ll idx; cin >> idx;
            cout << seg.query(hld.in[idx], hld.out[idx]) << "\n";
        }
        else{
            ll s, e; cin >> s >> e;
            cout << hld.query(s, e) << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}