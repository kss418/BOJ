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
ll a[MAX], dp[MAX];
vector <ll> adj[MAX], arr;

class _lca {
public:
    ll n; vector <ll> d;
    vector <vector<ll>> p, adj;
    _lca(ll n) { //n 개수
        this->n = n;
        p.resize(n + 1, vector<ll>(log2(n + 1) + 1, -1));
        d.resize(n + 1); adj.resize(n + 1);
        fill(d.begin(), d.end(), -1);
    }

    void add(ll a, ll b) { // 양방향
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void addsol(ll a, ll b) { // 단방향
        adj[a].push_back(b);
    }

    void mktree(ll cur) {
        for (auto& nxt : adj[cur]) {
            if (d[nxt] != -1) continue;
            p[nxt][0] = cur;
            d[nxt] = d[cur] + 1;
            mktree(nxt);
        }
    }

    void init(ll root) {
        d[root] = 0;
        mktree(root);

        for (int i = 1; i <= log2(n); i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j][i - 1] == -1) continue;
                p[j][i] = p[p[j][i - 1]][i - 1];
            }
        }
    }

    ll ret(ll a, ll b) {
        if (d[a] < d[b]) swap(a, b);

        ll diff = d[a] - d[b];
        for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)) a = p[a][i];
        }
        if (a == b) return a;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[a][i] == -1) continue;
            if (p[a][i] == p[b][i]) continue;

            a = p[a][i]; b = p[b][i];
        }

        return p[a][0];
    }
};

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll l, ll r) {
        l = find(l); r = find(r);
        if (l == r) return;
        ll mx = (a[l] > a[r] ? l : r);
        ll mn = (a[l] > a[r] ? r : l);
        p[mn] = mx;
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void run(){
    cin >> n; _uf uf(n); _lca lca(n);
    for(int i = 1;i <= n;i++) cin >> a[i];
    arr.resize(n); iota(all(arr), 1ll);

    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
        lca.add(s, e);
    }
    lca.init(1);

    sort(all(arr), [](ll l, ll r){
        return a[l] < a[r];
    });
    
    for(auto& cur : arr){
        for(auto& nxt : adj[cur]){
            if(a[nxt] > a[cur]) continue;
            ll nf = uf.find(nxt);
            ll l = lca.ret(cur, nf);
            ll d = lca.d[cur] + lca.d[nf] - 2 * lca.d[l];
            dp[cur] = max(dp[cur], dp[nf] + d);
            uf.merge(cur, nxt);
        }
    }

    cout << dp[arr.back()];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

