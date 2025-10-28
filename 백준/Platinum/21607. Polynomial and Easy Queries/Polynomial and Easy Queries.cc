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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 1e5 + 3;
ll a[MAX];

ll f(ll x){
    return (2 * x * x - 1) % MOD;
}

ll g(ll x){
    return (4 * x * x * x - 3 * x) % MOD;
}

class _st { // 1-base index
public:
    ll n, m; vector <vector<ll>> num;
    _st(ll n, ll m) { //n 개수 m 깊이
        this->n = n; this->m = m;
        num.resize(log2(m + 1) + 1, vector<ll>(n + 1, 0));
    }

    void add(ll st, ll en) {
        num[0][st] = en;
    }

    void init() {
        for (int i = 1; i <= log2(m + 1); i++) {
            for (int j = 0; j <= n; j++) num[i][j] = num[i - 1][num[i - 1][j]];
        }
    }

    ll ret(ll n, ll d) { //n 노드 d 깊이
        for (int i = log2(m + 1); i >= 0; i--) {
            if (d & (1ll << i)) n = num[i][n];
        }

        return n;
    }
};

template <typename T = pll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n, sz;
    class node{
    public:
        ll a, b;
        node() : node(0, 0){} // identity
        node(ll a, ll b) : a(a), b(b) {}
        
        node operator += (node ot){ // add
            a += ot.a; b += ot.b;
            return *this;
        }

        operator T(){ // query
            return {a, b};
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
            l.a + r.a,
            l.b + r.b
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
    cin >> n >> m; _seg seg(n + 1); 
    _st st1(MOD + 1, MAX), st2(MOD + 1, MAX);
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i < MOD;i++){
        st1.add(i, f(i));
        st2.add(i, g(i));
    }

    st1.add(0, MOD); st1.add(MOD, 1);
    st2.add(0, g(0));
    st1.init(); st2.init();

    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll l, r; cin >> l >> r;
            seg.add(l, {1, 0});
            seg.add(r + 1, {-1, 0});
        }
        else if(op == 2){
            ll l, r; cin >> l >> r;
            seg.add(l, {0, 1});
            seg.add(r + 1, {0, -1});
        }
        else{
            ll idx; cin >> idx;
            pll q = seg.query(1, idx);

            ll now = a[idx];
            now = st1.ret(now, q.x);
            now = st2.ret(now, q.y);
            cout << now << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}