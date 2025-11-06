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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result[MAX];

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
        st = max(0ll, st); en = min(n - 1, en);
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
        if(idx < 0 || idx >= n) return;
        ll p = idx + sz - 1;
        seg[p] = val;
        for(p >>= 1ll; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void add(ll idx, node val){
        if(idx < 0 || idx >= n) return;
        ll p = idx + sz - 1;
        seg[p] += val;
        for(p >>= 1; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void clear(){ fill(all(seg), node()); }
}; _seg seg;


bool f(ll s, ll e, ll cnt){
    ll c = 0;
    if(s < n && e >= n) c += seg.query(s, n - 1) + seg.query(0, e - n);
    else c += seg.query(s % n, e % n);

    return c >= cnt;
}

ll lb(ll cur, ll cnt){
    ll lo = cur + 1, hi = cur + n;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(f(cur, mid, cnt)) hi = mid;
        else lo = mid + 1;
    }

    return lo % n;
}

void run(){
    cin >> n; seg = {n};
    for(int i = 0;i < n;i++) cin >> a[i], seg.set(i, 1);
    swap(a[0], a[a[n - 1] % (n - 1)]);

    ll idx = 0;
    for(int i = 0;i < n;i++){
        result[idx] = a[i];
        if(i == n - 1) break;
        seg.set(idx, 0);

        ll pl = a[i] % (n - i - 1);
        if(!pl) pl += n - i - 1;
        idx = lb(idx, pl);
    }

    for(int i = 0;i < n;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}