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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;

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

vector <ll> adj[MAX];
map <string, ll> num;
ll dep[MAX], mx = 1;

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

void mk_tree(ll cur){
    if(dep[cur] > dep[mx]) mx = cur; 
    for(auto& nxt : adj[cur]){
        dep[nxt] = dep[cur] + 1;
        mk_tree(nxt);
    }
}

void run(){
    string a, b; cin >> n >> a >> b;
    num[a] = 1; num[b] = 2; 
    _lca lca(10101); _uf uf(10101);
    ll cnt = 2;
    for(int i = 1;i <= n;i++){
        string s, e; cin >> s >> e;
        if(!num.count(s)) num[s] = ++cnt;
        if(!num.count(e)) num[e] = ++cnt;
        lca.add(num[e], num[s]);
        uf.merge(num[s], num[e]);
        adj[num[e]].push_back(num[s]);
    }

    mk_tree(1); lca.init(mx);
    if(!uf.same(1, 2)){ cout << "NOT RELATED"; return; }
    
    ll l = lca.ret(1, 2);
    if(lca.d[1] < lca.d[2]) swap(a, b);
    if(lca.d[num[b]] - lca.d[l] > 1) { cout << "COUSINS"; return; }
    
    ll diff = lca.d[num[a]] - lca.d[l];
    if(lca.d[num[b]] == lca.d[l]){
        cout << b << " is the ";
        for(int i = 3;i <= diff;i++) cout << "great-";
        if(diff >= 2) cout << "grand-"; 
        cout << "mother of " << a;
    }
    else if(diff > 1){
        cout << b << " is the ";
        for(int i = 3;i <= diff;i++) cout << "great-";
        cout << "aunt of " << a;
    }
    else cout << "SIBLINGS";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

