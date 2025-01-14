#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], d[MAX], cnt;
ll in[MAX], out[MAX];
vector <ll> adj[MAX];

class _sseg {
public:
    ll n; vector <ll> arr, seg;
    _sseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return 0;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }

    void add(ll idx, ll val) { add(idx, val, 1, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);
    }

    ll update(ll idx, ll val) { return update(idx, val, 1, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2);
        seg[node] += update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    ll cnt(ll val) { return cnt(val, 1, n); }
    ll cnt(ll val, ll l, ll r, ll node = 1){
        if(l == r) return r;
        ll mid = (l + r) >> 1;

        if(seg[node * 2] < val) return cnt(val - seg[node * 2], mid + 1, r, node * 2 + 1);
        else return cnt(val, l, mid, node * 2);
    }
};

void dfs(ll cur, ll dep, ll pre = -1){
    d[cur] = dep; in[cur] = ++cnt;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, dep + 1, cur);
    }

    out[cur] = cnt;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    cin >> k; dfs(m, 1);
    _sseg seg(cnt);
    while(k--){
        ll op, v; cin >> op >> v;
        if(op == 1) seg.add(in[v], 1);
        else cout << seg.query(in[v], out[v]) * d[v] << "\n"; 
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

