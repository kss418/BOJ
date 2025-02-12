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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll result;

ll dfs(ll cur, ll pre = -1){
    ll ret = 0, mx1 = 0, mx2 = 0;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ll now = dfs(nxt, cur) + 1;
        ret = max(ret, now);
        if(now > mx1) mx2 = mx1, mx1 = now;
        else if(now > mx2) mx2 = now;
    }

    if(mx1 + mx2 < m) return ret;
    result++; return ret = -1;
}

void run(){
    cin >> n >> m; 
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    dfs(1); cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}