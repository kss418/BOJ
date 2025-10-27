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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
vector <pll> adj[MAX];
ll dp[MAX], sum[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur]; 
    if(ret != -1) return ret; ret = 0;

    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ret += solve(nxt, cur);
        ll now = sum[nxt] % MOD;
        now *= co; now += co; now %= MOD;

        ret += (now * sum[cur]) % MOD;

        ret += now; ret %= MOD;
        sum[cur] += now; sum[cur] %= MOD;
    }

    return ret %= MOD; 
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    cout << solve(1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}