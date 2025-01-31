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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> adj[MAX];
ll dp[MAX], pre[MAX];
vector <ll> tr;

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    for(auto& nn : adj[cur]){
        auto[nxt, co] = nn;
        if(ret >= solve(nxt) + co) continue;
        ret = solve(nxt) + co;
        pre[cur] = nxt;
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp)); dp[1] = 0;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[e].push_back({s, c});
    }

    ll result = 0, cur = 0;
    for(auto& i : adj[1]){
        auto[nxt, co] = i;
        if(result >= solve(nxt) + co) continue;
        result = solve(nxt) + co; cur = nxt;
    }
    cout << result << "\n";

    tr.push_back(1);
    while(cur != 1){
        tr.push_back(cur);
        cur = pre[cur];
    }
    tr.push_back(1); reverse(all(tr));
    for(auto& i : tr) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

