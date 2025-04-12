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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
ll dp[MAX][4];
vector <ll> adj[MAX];

ll solve(ll cur, ll num, ll pre = -1){
    ll& ret = dp[cur][num];
    if(ret != -1) return ret; ret = 1;

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ll now = 0;
        for(int i = 1;i <= 3;i++){
            if(i == num) continue;
            now += solve(nxt, i, cur);
            now %= MOD;
        }
        ret *= now; ret %= MOD;
    }

    return ret %= MOD;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    memset(dp, -1, sizeof(dp));
    while(m--){
        ll idx, v; cin >> idx >> v;
        for(int i = 1;i <= 3;i++){
            if(i == v) continue;
            dp[idx][i] = 0;
        }
    }

    cout << (solve(1, 1) + solve(1, 2) + solve(1, 3)) % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

