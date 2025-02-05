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
constexpr ll MAX = 251010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll a[MAX], p[MAX];
bool c[MAX];

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n; p.resize(n + 1, -1);
        si.resize(n + 1, 1);
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

void dfs(ll cur, ll pre = 0){
    p[cur] = pre;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
    }
}

void run(){
    cin >> n;
    for(int i = 1;i < n;i++) {
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    dfs(1);

    cin >> m; _uf uf(n);
    while(m--){
        ll cnt; cin >> cnt;
        for(int i = 1;i <= cnt;i++) cin >> a[i], c[a[i]] = 1;
        for(int i = 1;i <= cnt;i++){
            if(!c[p[a[i]]]) continue;
            uf.merge(a[i], p[a[i]]);
        }

        ll result = 0;
        for(int i = 1;i <= cnt;i++){
            if(a[i] == uf.find(a[i])) result += uf.size(a[i]) * (uf.size(a[i]) - 1) / 2;
        }

        for(int i = 1;i <= cnt;i++){
            uf.p[a[i]] = -1; uf.si[a[i]] = 1; c[a[i]] = 0;
        }

        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}