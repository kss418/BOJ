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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> adj[MAX];
ll d[MAX][2];

void dfs(ll cur, ll num, ll dist, ll pre = -1){
    d[cur][num] = dist;
    for(auto& nn : adj[cur]){
        auto[nxt, co] = nn;
        if(nxt == pre) continue;
        dfs(nxt, num, dist + co, cur);
    }
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i < n;i++) {
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }
    
    ll result = INF;
    dfs(m, 0, 0); dfs(k, 1, 0);
    for(int i = 1;i <= n;i++){
        result = min(result, d[i][0] + d[i][1]);
        for(auto& nn : adj[i]){
            auto[j, co] = nn;
            result = min(result, d[i][0] + d[j][1]);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

