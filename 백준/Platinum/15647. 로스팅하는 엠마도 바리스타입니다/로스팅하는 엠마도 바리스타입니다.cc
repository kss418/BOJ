#include <bits/stdc++.h>
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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX], sz[MAX], result[MAX];
vector <pll> adj[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    sz[cur] = 1;
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ret += solve(nxt, cur);
        ret += sz[nxt] * co;
        sz[cur] += sz[nxt];
    }

    return ret;
}

void reroot(ll cur, ll cnt, ll pl, ll pre = -1){
    result[cur] = dp[cur] + pl;
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ll nc = cnt + sz[cur] - sz[nxt];
        ll d = dp[cur] - dp[nxt] - sz[nxt] * co;
        reroot(nxt, nc, pl + nc * co + d, cur);
    }
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    solve(1); reroot(1, 0, 0);
    for(int i = 1;i <= n;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}