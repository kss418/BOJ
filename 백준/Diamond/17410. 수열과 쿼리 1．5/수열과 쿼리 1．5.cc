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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sq;

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
}; _seg <ll> seg[404];

ll query(ll s, ll e, ll v){
    ll ret = 0;
    if(s / sq == e / sq){
        for(int i = s;i <= e;i++) ret += a[i] > v;
        return ret;
    }

    ll l = s / sq + 1, r = e / sq - 1;
    for(int i = l;i <= r;i++) ret += seg[i].query(v + 1, 10100);

    ll idx = l * sq - 1;
    while(idx >= s) ret += a[idx] > v, idx--;

    idx = (r + 1) * sq;
    while(idx <= e) ret += a[idx] > v, idx++;

    return ret;
}

void update(ll idx, ll v){
    seg[idx / sq].add(a[idx], -1);
    a[idx] = v;
    seg[idx / sq].add(a[idx], 1);
}

void run(){
    cin >> n; sq = 800;
    for(int i = 0;i < n / sq + 1;i++) seg[i] = {10101};
    for(int i = 0;i < n;i++) cin >> a[i], seg[i / sq].add(a[i], 1);

    cin >> m;
    while(m--){
        ll op, v; cin >> op;
        if(op == 2){
            ll s, e; cin >> s >> e >> v;
            cout << query(s - 1, e - 1, v) << "\n";
        }
        else{
            ll idx; cin >> idx >> v;
            update(idx - 1, v);
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}