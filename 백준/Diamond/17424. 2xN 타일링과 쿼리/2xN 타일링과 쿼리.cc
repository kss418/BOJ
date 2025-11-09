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
constexpr ll MOD = 1e9 + 7;
ll a[MAX];

class node{
public:
    ll arr[4][4];
    node(){
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 4;j++) arr[i][j] = (i == j);
        }
    } // identity

    node(const ll v[4][4]){
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 4;j++) arr[i][j] = v[i][j];
        }
    }

    operator ll(){ // query
        return arr[0][0];
    }
};

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n, sz;
    vector <node> seg;

    _seg(){}
    _seg(ll n) : n(n){ 
        sz = 1; while(sz < n) sz <<= 1ll;
        seg.assign(2 * sz, node());
    }

    node merge(node& l, node& r){
        auto& lv = l.arr, &rv = r.arr;
        ll ret[4][4] = {};
        
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 4;j++){
                unsigned long long sum = 0;
                for(int k = 0;k < 4;k++){
                    sum += lv[i][k] * rv[k][j];
                }

                ret[i][j] = sum % MOD;
            }
        }

        return ret;
    }

    node query(ll st, ll en) {
        st = max(1ll, st); en = min(n, en);
        if(st > en) return node();

        node l = node(), r = node();
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

    void clear(){ fill(all(seg), node()); }
};

ll v[4][4][4] = {
    {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    },
    {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0}
    },
    {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }
};

void run(){
    cin >> n >> m; _seg <ll> seg(n);
    for(int i = 1;i <= n;i++) seg.set(i, v[0]);

    while(m--){
        ll op, x, y; cin >> op >> y >> x;
        a[x] ^= (1ll << (y - 1));
        seg.set(x, v[a[x]]);

        cout << seg.seg[1].arr[0][0] << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}