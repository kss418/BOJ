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
        lazy_type() : lazy_type(0){}
        lazy_type(ll v) : v(v){}

        lazy_type& operator += (lazy_type ot){ // add
            v += ot.v;
            return *this;
        }
    };

    vector<node> seg, tmp; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { l.v + r.v, l.len + r.len };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return !lazy.v;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s += p;
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v += seg.len * lazy.v;
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = 0;
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
}; _prop seg1, seg2;

vector <ll> adj[MAX];
ll cnt, in[MAX], out[MAX];
bool dir;
void dfs(ll cur = 1){
    in[cur] = ++cnt;
    for(auto& nxt : adj[cur]) dfs(nxt);
    out[cur] = cnt;
}

void run(){
    cin >> n >> m; seg1 = seg2 = {n};
    for(int i = 1;i <= n;i++){
        cin >> p[i]; if(p[i] == -1) continue;
        adj[p[i]].push_back(i);
    }

    for(int i = 1;i <= n;i++){
        seg1.set(i, {0, 1});
        seg2.set(i, {0, 1});
    } 
    dfs(); seg1.init(); seg2.init();

    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll idx, v; cin >> idx >> v;
            if(!dir) seg1.add(in[idx], out[idx], v);
            else seg2.add(in[idx], in[idx], v);
        }
        else if(op == 2){
            ll idx; cin >> idx;
            ll a = seg1.query(in[idx], in[idx]);
            ll b = seg2.query(in[idx], out[idx]);
            cout << a + b << "\n";
        }
        else dir ^= 1;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}