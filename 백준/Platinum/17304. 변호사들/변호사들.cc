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
ll ind[MAX], cnt[MAX];
set <ll> st[MAX];
vector <ll> adj[MAX];
vector <pll> cy;
bool f[MAX], ex[MAX];

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
        f[a] |= f[b]; ex[a] |= ex[b];
    }

    ll size(ll num){ return sz[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void clear(){ p.assign(n + 1, -1); sz.assign(n + 1, 1); }
}; 

void run(){
    cin >> n >> m; _uf uf(n);
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        st[s].insert(e);
        if(st[e].count(s)){
            cnt[s]++; cnt[e]++;
            cy.push_back({s, e});
        }
        ind[e]++;
    }

    bool flag = 1;
    for(int i = 1;i <= n;i++) if(!ind[i]) flag = 0;

    for(auto& [s, e] : cy){
        bool rs = cnt[s] == ind[s];
        bool re = cnt[e] == ind[e];

        if(!rs && !re) continue;
        if(rs ^ re){
            ex[uf.find(rs ? s : e)] = 1;
            continue;
        }

        if(uf.same(s, e)) f[uf.find(s)] = 1;
        uf.merge(s, e);
    }

    for(int i = 1;i <= n;i++){
        if(uf.find(i) != i || uf.size(i) == 1) continue;
        if(!f[uf.find(i)] && !ex[uf.find(i)]) flag = 0;
    }

    cout << (flag ? "YES" : "NO");
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}