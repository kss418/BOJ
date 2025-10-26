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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> adj[MAX];
vector <ll> result;
ll ind[MAX];
bool v[MAX];

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

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void dfs(ll cur, ll pre = -1){
    if(v[cur]) return; v[cur] = 1;

    for(auto& [nxt, idx] : adj[cur]){
        if(nxt == pre || v[nxt]) continue;
        dfs(nxt, cur);
        if(ind[nxt]) continue;
        ind[cur] ^= 1; result.push_back(idx);
    }
}

void run(){
    cin >> n >> m; _uf uf(n);
    for(int i = 1;i <= m;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back({e, i});
        adj[e].push_back({s, i});
        uf.merge(s, e);
    }

    for(int i = 1;i <= n;i++){
        if(uf.find(i) != i || uf.size(i) % 2 == 0) continue;
        cout << -1; return;
    }

    for(int i = 1;i <= n;i++){
        if(uf.find(i) != i) continue;
        dfs(i);
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << "\n"; 
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}