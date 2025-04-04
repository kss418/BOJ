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
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX];
vector <ll> adj[MAX];

class _prop { 
public:
    vector<ll> seg, lazy; ll n;

    _prop(){}
    _prop(ll n) {
        this->n = n; 
        seg.resize(4 * n + 1); lazy.resize(4 * n + 1);
    }

    void propagate(ll l, ll r, ll node) {
        if (!lazy[node]) return;
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] += lazy[node] * (r - l + 1);
        lazy[node] = 0;
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] += val; propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return 0;
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2);
        ret += query(st, en, mid + 1, r, node * 2 + 1);

        return ret;
    }
};
_prop seg;

ll in[MAX], out[MAX], cnt;
void init(ll cur){
    in[cur] = ++cnt;
    for(auto& nxt : adj[cur]) init(nxt);
    out[cur] = cnt;
}

void run(){
    cin >> n >> m; seg = {n};
    cin >> a[1]; 
    for(int i = 2;i <= n;i++) {
        cin >> a[i] >> p[i];
        adj[p[i]].push_back(i);
    }

    init(1); seg.add(in[1], in[1], a[1]);
    for(int i = 2;i <= n;i++) seg.add(in[i], in[i], a[i]);

    while(m--){
        char c; cin >> c;
        if(c == 'p'){
            ll idx, v; cin >> idx >> v;
            if(in[idx] == out[idx]) continue;
            seg.add(in[idx] + 1, out[idx], v);
        }
        else{ 
            ll idx; cin >> idx;
            cout << seg.query(in[idx], in[idx]) << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

