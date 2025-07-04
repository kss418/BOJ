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
pll a[MAX];
bool use[MAX], v[MAX];
vector <pll> adj[MAX];
deque <ll> q;
vector <pll> cy[MAX];

class _lca {
public:
    ll n; vector <ll> d;
    vector <vector<ll>> p, adj;
    _lca() {}
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

    void init() {
        for(int i = 1;i <= n;i++){
            if(d[i] != -1) continue;
            d[i] = 0; mktree(i);
        }

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
        if(diff > 0) for (int i = log2(diff); i >= 0; i--) {
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
}; _lca lca;

void track(ll s, ll e){
    ll l = lca.ret(s, e);
    vector <ll> now, result;
    while(s != l){
        result.push_back(s);
        s = lca.p[s][0];
    }
    result.push_back(l);

    while(e != l){
        now.push_back(e);
        e = lca.p[e][0];
    }

    reverse(all(now));
    for(auto& i : now) result.push_back(i);
    for(auto& i : result) cout << i << " ";
}

void run(){
    cin >> n; lca = {n + 1};
    for(int i = 1;i <= 2 * n - 3;i++){
        cin >> a[i].x >> a[i].y;
        adj[a[i].x].push_back({a[i].y, i});
        adj[a[i].y].push_back({a[i].x, i});
    }

    for(int i = 1;i <= n;i++){
        if(v[i]) continue;
        q.push_back(i); v[i] = 1;
        while(!q.empty()){
            auto cur = q.front(); q.pop_front();
            for(auto& [nxt, idx] : adj[cur]){
                if(v[nxt]) continue;
                use[idx] = 1; v[nxt] = 1;
                lca.add(cur, nxt);
                q.push_back(nxt);
            }
        }
    }

    lca.init();
    for(int i = 1;i <= 2 * n - 3;i++){
        if(use[i]) continue;
        auto [s, e] = a[i];
        ll l = lca.ret(s, e);
        if(l == -1) continue;
        ll len = lca.d[s] + lca.d[e] - 2 * lca.d[l];
        
        cy[len + 1].push_back({s, e});
    }

    for(int i = 3;i <= n;i++){
        if(cy[i].size() < 2) continue;
        auto [s1, e1] = cy[i][0];
        auto [s2, e2] = cy[i][1];

        cout << i << "\n";
        track(s1, e1); cout << "\n";
        track(s2, e2); cout << "\n";
        
        return;
    }

    cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

