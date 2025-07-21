#include <bits/stdc++.h>
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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[MAX];

template <typename T = ll> // query type
class _prop { // 구간 예외 처리하기
public:
    class node{
    public:
        ll v, len;
        node() : node(0, 0){}
        node(ll v, ll len) : v(v), len(len){}
        
        node& operator += (node ot){ // add
            return *this;
        }

        operator T(){ // node -> query
            return v;
        }
    };

    class lazy_type{
    public:
        ll v;
        lazy_type() : lazy_type(2){}
        lazy_type(ll v) : v(v){}

        lazy_type& operator += (lazy_type ot){ // add
            v = ot.v;
            return *this;
        }
    };

    vector<node> seg, tmp; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { l.v + r.v, l.len + r.len };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return lazy.v == 2;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s += p;
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v = seg.len * lazy.v;
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = 2;
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

    void add(ll st, ll en, lazy_type val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, lazy_type val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] += val; propagate(l, r, node);
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

vector <ll> adj[MAX];
ll cnt, in[MAX], out[MAX];
void dfs(ll cur = 1){
    in[cur] = ++cnt;
    for(auto& nxt : adj[cur]) dfs(nxt);
    out[cur] = cnt;
}

void run(){
    cin >> n; seg = {n};
    for(int i = 1;i <= n;i++){
        cin >> p[i]; if(!p[i]) continue;
        adj[p[i]].push_back(i);
    }
    for(int i = 1;i <= n;i++) seg.set(i, {1, 1}); seg.init();

    cin >> m; dfs();
    while(m--){
        ll op, idx; cin >> op >> idx;
        if(op == 1) seg.add(in[idx] + 1, out[idx], 1);
        else if(op == 2) seg.add(in[idx] + 1, out[idx], 0);
        else cout << seg.query(in[idx] + 1, out[idx]) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}