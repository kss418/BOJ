#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll v[MAX], result, cnt[MAX];
vector <ll> adj[MAX];
bool flag = 1;

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

void dfs(ll cur, ll idx, ll num = 0){
    if(v[cur] != -1){
        if(v[cur] != num) flag = 0;
        return;
    }

    v[cur] = num;
    if(!num) cnt[idx]++;
    for(auto& nxt : adj[cur]) dfs(nxt, idx, num ^ 1);
}

void run(){
    cin >> n >> m; _uf uf(n);
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
        uf.merge(s, e);
    }

    memset(v, -1, sizeof(v));
    for(int i = 1;i <= n;i++){
        if(v[i] != -1) continue;
        dfs(i, i);
        result += max(uf.size(i) - cnt[i], cnt[i]);
    }

    cout << (flag ? result : -1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}