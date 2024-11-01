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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll dp[MAX][2], g, pg;
vector <pll> adj[MAX];

bool chk(ll cur, ll pre, bool r){
    if(adj[cur].size() >= 3) return 1;
    if(adj[cur].size() == 1 && !r) return 1;
    if(adj[cur].size() == 2 && r) return 1;
    return 0;
}

void init(ll cur, ll pre, bool r){
    if(chk(cur, pre, r)) { 
        g = cur; pg = pre; return; 
    }

    for(auto& i : adj[cur]){
        auto&[nxt, co] = i;
        if(nxt == pre) continue;
        init(nxt, cur, 0);
    }
}

ll solve(ll cur, ll pre, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret;
    ret = 0;
    if(!cnt && cur == g) return ret;

    for(auto& i : adj[cur]){
        auto&[nxt, co] = i;
        if(pre == nxt) continue;
        ret = max(ret, solve(nxt, cur, cnt) + co);
    }

    return ret;
}

int main() {
    fastio;

    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    init(m, -1, 1);
    cout << solve(m, -1, 0) << " " << solve(g, pg, 1);

    
    return 0;
}