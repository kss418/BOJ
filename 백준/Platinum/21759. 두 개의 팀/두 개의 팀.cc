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
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX], dp[MAX][3];
vector <ll> adj[MAX];

ll solve1(ll cur){
    ll& ret = dp[cur][0];
    if(ret != MINF) return ret; ret = a[cur];
    for(auto& nxt : adj[cur]){
        ret += max(solve1(nxt), 0ll);
    }

    return ret;
}

ll solve2(ll cur){
    ll& ret = dp[cur][1];
    if(ret != MINF) return ret; ret = dp[cur][0];
    for(auto& nxt : adj[cur]){
        ret = max(ret, solve2(nxt));
    }

    return ret;
}

ll solve3(ll cur){
    ll& ret = dp[cur][2];
    if(ret != MINF) return ret; ret = MINF + 1;
    for(auto& nxt : adj[cur]){
        ll now = solve3(nxt);
        if(dp[nxt][0] > 0) ret = max(ret, now);
        else ret = max(ret, dp[nxt][1]);
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, 0xc0, sizeof(dp));
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> p[i];
        if(p[i] != -1) adj[p[i]].push_back(i);
    }
    solve1(1); solve2(1); solve3(1);
    
    ll result = MINF;
    for(int i = 1;i <= n;i++){
        result = max(result, dp[i][0] + dp[i][2]);
        if(adj[i].size() < 2) continue;
        sort(all(adj[i]), [&](ll a, ll b){
            return dp[a][1] > dp[b][1];
        });
        result = max(result, dp[adj[i][0]][1] + dp[adj[i][1]][1]);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}