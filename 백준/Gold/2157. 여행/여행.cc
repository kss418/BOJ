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
constexpr ll MAX = 301; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> adj[MAX];
ll dp[MAX][MAX];

void run(){
    cin >> n >> m >> k;
    while(k--){
        ll s, e, c; cin >> s >> e >> c;
        if(s >= e) continue;
        adj[s].push_back({e, c});
    }

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++) dp[i][j] = -INF;
    }
    dp[1][1] = 0;

    for(int i = 1;i <= n;i++){
        for(auto& nn : adj[i]){
            auto[nxt, co] = nn;
            for(int j = 1;j <= m;j++) {
                dp[nxt][j] = max(dp[nxt][j], dp[i][j - 1] + co);
            }
        }
    }

    ll result = 0;
    for(int i = 1;i <= m;i++) result = max(result, dp[n][i]);

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}