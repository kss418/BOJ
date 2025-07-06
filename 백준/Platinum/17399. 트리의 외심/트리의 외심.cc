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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result, num;

class _lca { // 1-based index
public:
    ll n, m; vector <ll> d;
    vector <vector<ll>> p;
    vector <vector<pll>> adj;

    class node{
    public:
        ll v;
        node() : node(0) {}
        node(ll v) : v(v) {}

        operator ll(){ // query
            return v;
        }
    };
    vector <vector<node>> arr;

    _lca() {}
    _lca(ll n, bool m = 0) { //n 개수
        this->n = n; this->m = m; 
        p.resize(log2(n + 1) + 1, vector<ll>(n + 1, -1));
        d.resize(n + 1); adj.resize(n + 1);
        fill(d.begin(), d.end(), -1);

        if(m) arr.resize(log2(n + 1) + 1, vector<node>(n + 1, node()));
    }

    void add(ll a, ll b, ll c = 1) { // 양방향
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    void addsol(ll a, ll b, ll c = 1) { // 단방향
        adj[a].push_back({b, c});
    }

    node merge(const node& a, const node& b){
        return {
            max(a.v, b.v)
        };
    }

    node merge(ll a, const node& b){
        return{
            max(a, b.v)
        };
    }

    void mktree(ll cur) {
        for (auto& [nxt, co] : adj[cur]) {
            if (d[nxt] != -1) continue;
            p[0][nxt] = cur;
            d[nxt] = d[cur] + 1;

            if(m) arr[0][nxt] = co;
            mktree(nxt);
        }
    }

    void init() {
        for(int i = 1;i <= n;i++){
            if(d[i] != -1) continue;
            d[i] = 0; mktree(i);
        }

        for (int i = 1; i <= log2(n); i++) {
            for (int j = 1; j <= n; j++) {
                if (p[i - 1][j] == -1) continue;
                p[i][j] = p[i - 1][p[i - 1][j]];
                if(m) arr[i][j] = merge(arr[i - 1][p[i - 1][j]], arr[i - 1][j]);
            }
        }
    }

    ll shift(ll a, ll diff){
        if(diff <= 0) return a;
        for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)){
                if(a == -1) return -1;
                a = p[i][a];
            }
        }

        return a;
    }

    ll ret(ll a, ll b) {
        if (d[a] < d[b]) swap(a, b);

        a = shift(a, d[a] - d[b]);
        if (a == b) return a;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[i][a] == -1) continue;
            if (p[i][a] == p[i][b]) continue;

            a = p[i][a]; b = p[i][b];
        }

        return p[0][a];
    }

    ll num(ll a, ll b){
        if(!m) return MINF;

        node ret = node();
        if (d[a] < d[b]) swap(a, b);

        ll diff = d[a] - d[b];
        if (diff) for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)){
                ret = merge(ret, arr[i][a]);
                a = p[i][a];
            }
        }
        if (a == b) return ret;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[i][a] == -1) continue;
            if (p[i][a] == p[i][b]) continue;

            ret = merge(ret, arr[i][a]);
            ret = merge(ret, arr[i][b]);
            a = p[i][a]; b = p[i][b];
        }

        ret = merge(ret, arr[0][a]);
        ret = merge(ret, arr[0][b]);
        return ret;
    }
}; _lca lca;

ll len(ll a, ll b){
    if(a == -1 || b == -1) return INF;
    ll l = lca.ret(a, b);
    if(l == -1) return INF;
    return lca.d[a] + lca.d[b] - 2 * lca.d[l];
}

void cal(ll a, ll b, ll c, ll& num){
    ll l = lca.ret(a, b);
    if(l == -1) return;

    ll d = len(a, b);
    if(lca.d[a] < lca.d[b]) swap(a, b);

    if(d % 2) return;
    ll m = lca.shift(a, d >> 1);
    ll d1 = len(a, m), d2 = len(b, m), d3 = len(c, m);
    if(d1 < num && d1 == d2 && d2 == d3){
        num = d1;
        result = m;
    }
}

void run(){
    cin >> n; lca = {n};
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        lca.add(s, e);
    }
    lca.init();

    cin >> m;
    while(m--){
        ll a, b, c; cin >> a >> b >> c;
        result = -1; num = INF;
        cal(a, b, c, num);
        cal(b, c, a, num);
        cal(c, a, b, num);

        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

