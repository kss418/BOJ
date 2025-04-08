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
ll a[MAX];
vector <pll> adj[MAX];

ll dfs(ll cur, ll v, ll now = INF, ll pre = -1){
    ll ret = (now >= v);
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ret += dfs(nxt, v, min(co, now), cur);
    }

    return ret;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    while(m--){
        ll cur, v; cin >> v >> cur;
        cout << dfs(cur, v) - 1 << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

