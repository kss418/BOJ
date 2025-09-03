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
ll a[MAX];

class _mt{ // 1-based index 
public:
    vector <ll> arr; ll n;
    vector <vector <ll>> tree;
    _mt(){} 
    _mt(ll n) : n(n), arr(n + 1), tree(4 * n + 1){}

    void set(ll idx, ll val){
        arr[idx] = val;
    }

    void init(){ init(1, n); }
    void init(ll l, ll r, ll node = 1){
        vector <ll>& cur = tree[node];
        if(l == r){
            cur.push_back(arr[l]);
            return;
        }

        ll mid = (l + r) >> 1ll;
        init(l, mid, node * 2);
        init(mid + 1, r, node * 2 + 1);

        vector <ll>& lv = tree[node * 2], &rv = tree[node * 2 + 1];
        cur.resize(lv.size() + rv.size());
        merge(all(lv), all(rv), cur.begin());
    }

    ll greater(ll s, ll e, ll val){ return greater(s, e, 1, n, val); }
    ll greater(ll s, ll e, ll l, ll r, ll val, ll node = 1){
        if(s > e) return 0;
        if(l > e || r < s) return 0;
        if(l >= s && r <= e){
            vector <ll>& cur = tree[node];
            return cur.end() - upper_bound(all(cur), val);
        }

        ll mid = (l + r) >> 1ll;
        ll ret = greater(s, e, l, mid, val, node * 2);
        ret += greater(s, e, mid + 1, r, val, node * 2 + 1);
        return ret;
    }

    ll less(ll s, ll e, ll val){ return less(s, e, 1, n, val); }
    ll less(ll s, ll e, ll l, ll r, ll val, ll node = 1){
        if(s > e) return 0;
        if(l > e || r < s) return 0;
        if(l >= s && r <= e){
            vector <ll>& cur = tree[node];
            return lower_bound(all(cur), val) - cur.begin();
        }

        ll mid = (l + r) >> 1ll;
        ll ret = less(s, e, l, mid, val, node * 2);
        ret += less(s, e, mid + 1, r, val, node * 2 + 1);
        return ret;
    }
};

void run(){
    cin >> n; _mt mt(n);
    for(int i = 1;i <= n;i++) cin >> a[i], mt.set(i, a[i]);
    mt.init();

    cin >> m;
    while(m--){
        ll l, r, v; cin >> l >> r >> v;
        cout << mt.greater(l, r, v) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}