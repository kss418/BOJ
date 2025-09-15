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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
vector <ll> arr;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n, sz;
    class node{
    public:
        int v;
        node() : node(0xc0c0c0c0){} // identity
        node(int v) : v(v) {}
        
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
        ll p = idx + sz - 1;
        seg[p] = max<T>(seg[p], val);
        for(p >>= 1ll; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void clear(){ fill(all(seg), node()); }
};

void run(){
    cin >> n; _seg <int> seg[6];
    for(int i = 0;i < 6;i++) seg[i] = {n};
    for(int i = 1;i <= n;i++) cin >> a[i], arr.push_back(a[i]);
    sort(all(arr));

    for(int i = 1;i <= n;i++) a[i] = lower_bound(all(arr), a[i]) - arr.begin() + 1;

    for(int i = 1;i <= n;i++){
        seg[0].set(a[i], 1); seg[3].set(a[i], 1);

        seg[1].set(a[i], seg[0].query(1, a[i] - 1) + 1);
        seg[1].set(a[i], seg[5].query(1, a[i] - 1) + 1);

        seg[2].set(a[i], seg[1].query(1, a[i] - 1) + 1);
        seg[2].set(a[i], seg[2].query(1, a[i] - 1) + 1);

        seg[4].set(a[i], seg[2].query(a[i] + 1, n) + 1);
        seg[4].set(a[i], seg[3].query(a[i] + 1, n) + 1);

        seg[5].set(a[i], seg[4].query(a[i] + 1, n) + 1);
        seg[5].set(a[i], seg[5].query(a[i] + 1, n) + 1);
    }

    ll result = max<int>({seg[2].query(1, n), seg[5].query(1, n), 0});
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}