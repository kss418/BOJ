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
constexpr ll MAX = 5050; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll dp[MAX][MAX], ind[MAX], p[MAX], sz[MAX];
i128 tmp[MAX];
deque <ll> q;

void mktree(ll cur, ll pre = -1){
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        mktree(nxt, cur); 
        p[nxt] = cur; ind[cur]++; 
    }
}

void run(){
    cin >> n >> m; 
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    mktree(1);
    for(int i = 1;i <= n;i++){
        dp[i][0] = dp[i][1] = sz[i] = 1;
        if(ind[i]) continue;
        q.push_back(i); sz[i] = 1;
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        ll nxt = p[cur]; memset(tmp, 0, sizeof(tmp));

        for(int i = sz[nxt];i >= 1;i--){
            for(int j = 0;j <= sz[cur];j++){
                if(i + j > n) break;
                tmp[i + j] += min<ll>(dp[nxt][i] * dp[cur][j], 1e18 + 1);
                tmp[i + j] = min<ll>(tmp[i + j], 1e18 + 1);
            }
        }

        sz[nxt] += sz[cur];
        for(int i = 2;i <= n;i++) dp[nxt][i] = tmp[i];
        if(!--ind[nxt]) q.push_back(nxt);
    }

    i128 sum = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            sum += dp[j][i];
            if(sum < m) continue;
            cout << i; return;
        }
    }

    cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}