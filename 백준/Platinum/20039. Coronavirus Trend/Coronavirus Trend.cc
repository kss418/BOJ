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
map <ll, ll> idx;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        int v;
        node() : node(0xc0c0c0c0){}
        node(int v) : v(v) {}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return v;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(node l, node r){
        return{
            max(l.v, r.v)
        };
    }

    T query(ll st, ll en) { return query(st, en, 1, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if(st > en) return _seg::node();
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    node update(ll idx, int val) { return update(idx, val, 1, n); }
    node update(ll idx, int val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) {
            seg[node] = max(seg[node].v, val);
            return seg[node];
        }
        ll mid = (l + r) >> 1;
        return seg[node] = merge(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));;
    }

    void clear(){ seg.clear(); seg.assign(4 * n + 1, node()); }
};

void run(){
    cin >> n; _seg <int> seg[6];
    for(int i = 0;i < 6;i++) seg[i] = {n};
    for(int i = 1;i <= n;i++) cin >> a[i], arr.push_back(a[i]);
    sort(all(arr));

    for(int i = 1;i <= n;i++) a[i] = lower_bound(all(arr), a[i]) - arr.begin() + 1;

    for(int i = 1;i <= n;i++){
        seg[0].update(a[i], 1); seg[3].update(a[i], 1);

        seg[1].update(a[i], seg[0].query(1, a[i] - 1) + 1);
        seg[1].update(a[i], seg[5].query(1, a[i] - 1) + 1);

        seg[2].update(a[i], seg[1].query(1, a[i] - 1) + 1);
        seg[2].update(a[i], seg[2].query(1, a[i] - 1) + 1);

        seg[4].update(a[i], seg[2].query(a[i] + 1, n) + 1);
        seg[4].update(a[i], seg[3].query(a[i] + 1, n) + 1);

        seg[5].update(a[i], seg[4].query(a[i] + 1, n) + 1);
        seg[5].update(a[i], seg[5].query(a[i] + 1, n) + 1);
    }

    ll result = max({seg[2].query(1, n), seg[5].query(1, n), 0});
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}