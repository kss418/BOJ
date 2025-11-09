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

class node{
public:
    ll x1, y1, x2, y2;
    bool operator < (const node& ot) const{
        return x1 < ot.x1;
    }
}; node a[MAX];
priority_queue <tll, vector<tll>, greater<tll>> pq;

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
            max(l.v, r.v)
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
        seg[p] = merge(seg[p], val);
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
    cin >> n; _seg seg(MAX);
    for(int i = 1;i <= n;i++){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        auto& [x1, y1, x2, y2] = a[i];
        while(!pq.empty() && get<0>(pq.top()) < x1){
            auto [x, y, c] = pq.top(); pq.pop();
            seg.set(y, c);
        }

        ll q = seg.query(0, y1 - 1);
        pq.push({x2, y2, q + 1});
    }

    while(!pq.empty()){
        auto [x, y, c] = pq.top(); pq.pop();
        seg.set(y, c);
    }

    cout << seg.query(0, MAX - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}