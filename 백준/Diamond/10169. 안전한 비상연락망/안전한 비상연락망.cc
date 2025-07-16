#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <tll> adj;
bool chk[MAX];

template <typename T = ll> // query type
class _prop { // 구간 예외 처리하기
public:
    class node{
    public:
        ll v;
        node() : node(INF){}
        node(ll v) : v(v){}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return v;
        }
    };

    class lazy_type{
    public:
        ll v;
        lazy_type() : lazy_type(INF){}
        lazy_type(ll v) : v(v){}
    };

    vector<node> seg; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { min(l.v, r.v) };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return lazy.v == INF;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s.v = min(s.v, p.v);
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v = min(lazy.v, seg.v);
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = INF;
    }

    _prop() {}
    _prop(ll n) {
        this->n = n; 
        seg.resize(4 * n + 1, node()); lazy.resize(4 * n + 1, lazy_type());
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


    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].v = min(lazy[node].v, val); propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

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
}; _prop seg;

template <typename T = ll> //query type
class _hld { // 구간 예외 처리하기
public:
    vector <vector <ll>> adj;
    vector <ll> sz, top, d, in, out, p;
    ll n, cnt = 0;

    _hld() {}
    _hld(ll n){
        this->n = n;
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

    void init(ll cur = 1){
        dfs1(cur, -1); dfs2(cur, -1);
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
        ret = seg.merge(ret, seg.query(in[st] + 1, in[en], 0, n));
        return ret; 
    }

    //void add_seg(ll idx, ll val) { seg.add(in[idx], val); }
    void add_lazy(ll st, ll en, ll val){
        while(top[st] != top[en]){
            if(d[top[st]] < d[top[en]]) swap(st, en);
            ll cur = top[st];
            seg.add(in[cur], in[st], val);
            st = p[cur];
        }

        if(d[st] > d[en]) swap(st, en);
        seg.add(in[st] + 1, in[en], val);
    }
}; _hld hld;

template <typename T = ll>
class _mst {
public:
    vector<ll> p, size; T result = 0;
    ll n, cnt = 0;
    class edge {
    public:
        ll s, e; T c, idx;
        bool operator>(const edge& ot) const {
            return c > ot.c;
        }

        bool operator<(const edge& ot) const {
            return c < ot.c;
        }
    };
    vector <edge> adj;

    _mst(ll n) {
        this->n = n;
        p.resize(n + 1, -1); size.resize(n + 1, 1);
    }

    ll find(ll num) {
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a > b) swap(a, b);
        p[b] = a, size[a] += size[b];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }

    void add(ll st, ll en, T c, ll idx) { // 양방향
        adj.push_back({ st, en, c, idx });
    }

    void init(ll num = 0) { // num 만큼 적게 간선 연결
        cnt = 0; result = 0;
        sort(all(adj));
        for(auto& i : adj) {
            auto [st, en, c, idx] = i;
            if (same(st, en)) continue; merge(st, en);
            result += c; cnt++; hld.add(st, en);
            chk[idx] = 1; 
            if (cnt == n - 1 - num) break;
        }

        if(cnt != n - 1 - num) result = MINF;
    }

    T ret() {
        return result;
    }
};

void run(){
    cin >> n >> m; _mst mst(n);
    seg = {n + 1}; hld = {n + 1};
    for(int i = 0;i < m;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj.push_back({s, e, c});
        mst.add(s, e, c, i);
    }

    mst.init(); hld.init();
    if(mst.ret() == MINF){
        for(int i = 0;i < m;i++) cout << -1 << "\n";
        return;
    }

    for(int i = 0;i < m;i++){
        if(chk[i]) continue;
        auto& [s, e, c] = adj[i];
        hld.add_lazy(s, e, c);
    }

    for(int i = 0;i < m;i++){
        ll ret = mst.ret();
        if(!chk[i]){
            cout << ret << "\n";
            continue;
        }

        auto& [s, e, c] = adj[i];
        ret -= c; ll q = hld.query(s, e);
        
        cout << (q >= INF ? -1 : ret + q) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

