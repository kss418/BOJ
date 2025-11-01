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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt, l[2 * MAX], r[2 * MAX];
ll num[2 * MAX], idx;
pll line[2 * MAX]; 
bool v[2 * MAX];
class node{
public:
    ll op, a, b;
}; vector <node> q;

void dfs(ll cur){
    v[cur] = 1;
    if(!l[cur] && !r[cur]){
        ++idx;
        line[cur] = {idx, idx};
        return; 
    }

    line[cur] = {INF, MINF};
    if(l[cur]){
        dfs(l[cur]);
        line[cur].x = min(line[cur].x, line[l[cur]].x);
        line[cur].y = max(line[cur].y, line[l[cur]].y);
    }

    if(r[cur]){
        dfs(r[cur]);
        line[cur].x = min(line[cur].x, line[r[cur]].x);
        line[cur].y = max(line[cur].y, line[r[cur]].y);
    }
}

class _uf { 
public:
    ll n; vector <ll> p, sz;
    
    _uf(){}
    _uf(ll n) {  
        this->n = n;
        p.resize(n + 1, -1); sz.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a < b) swap(a, b);
        p[b] = a, sz[a] += sz[b];
    }

    ll size(ll num){ return sz[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void clear(){ p.assign(n + 1, -1); sz.assign(n + 1, 1); }
}; 

class _lca { // 1-based index
public:
    ll n, m; vector <ll> d;
    vector <vector<ll>> p;
    vector <vector<pll>> adj;

    class node{
    public:
        ll v;
        node() : node(0) {}
        node(ll v) : v(v) {}

        operator ll(){ // query
            return v;
        }
    };
    vector <vector<node>> arr;

    _lca() {}
    _lca(ll n, bool m = 0) { //n 개수
        this->n = n; this->m = m; 
        p.resize(log2(n + 1) + 1, vector<ll>(n + 1, -1));
        d.resize(n + 1); adj.resize(n + 1);
        fill(d.begin(), d.end(), -1);

        if(m) arr.resize(log2(n + 1) + 1, vector<node>(n + 1, node()));
    }

    void add(ll a, ll b, ll c = 1) { // 양방향
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    void addsol(ll a, ll b, ll c = 1) { // 단방향
        adj[a].push_back({b, c});
    }

    node merge(const node& a, const node& b){
        return {
            max(a.v, b.v)
        };
    }

    node merge(ll a, const node& b){
        return{
            max(a, b.v)
        };
    }

    void mktree(ll cur) {
        for (auto& [nxt, co] : adj[cur]) {
            if (d[nxt] != -1) continue;
            p[0][nxt] = cur;
            d[nxt] = d[cur] + 1;

            if(m) arr[0][nxt] = co;
            mktree(nxt);
        }
    }

    void init() {
        for(int i = n;i >= 1;i--){
            if(d[i] != -1) continue;
            d[i] = 0; mktree(i);
        }

        for (int i = 1; i <= log2(n); i++) {
            for (int j = 1; j <= n; j++) {
                if (p[i - 1][j] == -1) continue;
                p[i][j] = p[i - 1][p[i - 1][j]];
                if(m) arr[i][j] = merge(arr[i - 1][p[i - 1][j]], arr[i - 1][j]);
            }
        }
    }

    ll shift(ll a, ll diff){
        if(diff <= 0) return a;
        for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)) a = p[i][a];
        }

        return a;
    }

    ll ret(ll a, ll b) {
        if (d[a] < d[b]) swap(a, b);

        a = shift(a, d[a] - d[b]);
        if (a == b) return a;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[i][a] == -1) continue;
            if (p[i][a] == p[i][b]) continue;

            a = p[i][a]; b = p[i][b];
        }

        return p[0][a];
    }

    ll num(ll a, ll b){
        if(!m) return MINF;

        node ret = node();
        if (d[a] < d[b]) swap(a, b);

        ll diff = d[a] - d[b];
        if (diff) for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)){
                ret = merge(ret, arr[i][a]);
                a = p[i][a];
            }
        }
        if (a == b) return ret;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[i][a] == -1) continue;
            if (p[i][a] == p[i][b]) continue;

            ret = merge(ret, arr[i][a]);
            ret = merge(ret, arr[i][b]);
            a = p[i][a]; b = p[i][b];
        }

        ret = merge(ret, arr[0][a]);
        ret = merge(ret, arr[0][b]);
        return ret;
    }
};

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
        sz = 1; while(sz < n) sz <<= 1ll;
        seg.assign(2 * sz, _seg::node());
    }

    node merge(node l, node r){
        return{
            l.v + r.v
        };
    }

    node query(ll st, ll en) {
        st = max(1ll, st); en = min(n, en);
        if(st > en) return _seg::node();

        node l = _seg::node(), r = _seg::node();
        st += sz - 1; en += sz - 1;
        while(st <= en){
            if(st & 1) l = merge(l, seg[st++]);
            if(!(en & 1)) r = merge(seg[en--], r);
            st >>= 1; en >>= 1; 
        }

        return merge(l, r);
    }

    void set(ll idx, node val){
        if(idx < 1 || idx > n) return;
        ll p = idx + sz - 1;
        seg[p] = val;
        for(p >>= 1ll; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void add(ll idx, node val){
        if(idx < 1 || idx > n) return;
        ll p = idx + sz - 1;
        seg[p] += val;
        for(p >>= 1; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void clear(){ fill(all(seg), node()); }
};

void run(){
    cin >> n >> m; cnt = n; 
    _lca lca(n + m); _uf uf(n + m); _seg seg(n);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) num[i] = i;

    while(m--){
        ll op, a, b; cin >> op >> a >> b;
        if(op == 3 && !uf.same(a, b)){
            cnt++;
            l[cnt] = uf.find(a); r[cnt] = uf.find(b);
            lca.addsol(cnt, l[cnt]); lca.addsol(cnt, r[cnt]);
            uf.merge(a, b); uf.merge(a, cnt);
        }
        
        q.push_back({op, a, b});
    }

    lca.init(); uf.clear();
    for(int i = cnt;i >= 1;i--){
        if(!v[i]) dfs(i);
    }

    for(int i = 1;i <= n;i++) seg.set(line[i].x, a[i]);
    for(auto& [op, a, b] : q){
        if(op == 4){
            ll l = lca.ret(a, b);
            if(!uf.same(a, b)) cout << -1 << "\n";
            else cout << seg.query(line[l].x, line[l].y) << "\n";
        }
        else if(op == 3) uf.merge(a, b);
        else seg.add(line[a].x, b * (op == 1 ? 1 : -1));
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}