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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], ind[MAX], cnt;
vector <pll> adj[MAX];
vector <ll> sz;
bool use[MAX];
vector <ll> l[2], v[2];

class _uf { 
public:
    ll n; vector <ll> p, sz;
    
    _uf(){}
    _uf(ll n) {  
        this->n = n;
        p.resize(n + 1, -1); sz.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, sz[a] += sz[b];
    }

    ll size(ll num){ return sz[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void clear(){ p.assign(n + 1, -1); sz.assign(n + 1, 1); }
}; 

void dfs(ll cur, ll c = 0){
    use[cur] = 1; v[c].push_back(cur); cnt++;
    for(auto& [nxt, num] : adj[cur]){
        if(use[nxt]) continue;
        if(cnt + 1 >= n && sz.size() == 1){
            v[1].push_back(nxt);
            use[nxt] = 1; return;
        }
        dfs(nxt, c); l[c].push_back(num);
    }
}

void run(){
    cin >> n >> m; _uf uf(n);
    for(int i = 1;i <= m;i++){
        ll s, e; cin >> s >> e;
        uf.merge(s, e);
        adj[s].push_back({e, i});
        adj[e].push_back({s, i}); 
        ind[s]++; ind[e]++;
    }

    for(int i = 1;i <= n;i++){
        if(uf.find(i) != i) continue;
        sz.push_back(uf.size(i));
    }

    if(n <= 2 || sz.size() >= 3 || (sz.size() == 2 && sz[0] == sz[1])){ cout << -1; return; }

    if(sz.size() == 1){
        dfs(1);
    }
    else{
        ll c = 0;
        for(int i = 1;i <= n;i++){
            if(use[i]) continue;
            dfs(i, c); c++;
        }
    }

    cout << v[0].size() << " " << v[1].size() << "\n";
    for(int i = 0;i < 2;i++){
        for(auto& j : v[i]) cout << j << " ";
        cout << "\n";
        for(auto& j : l[i]) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}