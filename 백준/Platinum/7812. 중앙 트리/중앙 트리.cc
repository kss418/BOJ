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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX], cnt[MAX];
vector <pll> adj[MAX];

void init(){
    for(int i = 0;i < n;i++) {
        adj[i].clear();
        cnt[i] = dp[i] = 0;
    }
}

ll dfs1(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    for(auto& nn : adj[cur]){
        auto[nxt, co] = nn;
        if(pre == nxt) continue;
        ret += cnt[nxt] * co + dfs1(nxt, cur);
    }
    return ret;
}

ll dfs2(ll cur, ll pre = -1){
    ll& ret = cnt[cur]; ret = 1;
    for(auto& nn : adj[cur]){
        auto[nxt, co] = nn;
        if(pre == nxt) continue;
        ret += dfs2(nxt, cur);
    }
    return ret;
}

ll solve(ll cur, ll pl, ll pre = -1){
    ll ret = pl + dp[cur];
    for(auto& nn : adj[cur]){
        auto[nxt, co] = nn;
        if(nxt == pre) continue;
        ll npl = pl + dp[cur] - dp[nxt] + (n - 2 * cnt[nxt]) * co;
        ret = min(ret, solve(nxt, npl, cur));
    }
    return ret;
}

int main() {
    fastio;
    
    while(1){
        cin >> n; if(!n) break; init();

        for(int i = 1;i < n;i++) {
            ll s, e, c; cin >> s >> e >> c;
            adj[s].push_back({e, c});
            adj[e].push_back({s, c});
        }

        dfs2(0); dfs1(0); 
        cout << solve(0, 0) << "\n";
    }
    
    
    return 0;
}