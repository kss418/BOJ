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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result, p[MAX], ind[MAX], sz[MAX];
pll dp[MAX][MAX], tmp[MAX], r[MAX];
vector <ll> adj[MAX];
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
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= n;j++) dp[i][j] = {INF, MINF};
    }

    for(int i = 1;i <= m;i++) cin >> k, dp[k][1] = {1, 1};
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    mktree(1);
    for(int i = 1;i <= n;i++){
        sz[i] = 1;
        if(dp[i][1].x != 1) dp[i][0] = {1, 1};
        if(ind[i]) continue;
        q.push_back(i);
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        ll nxt = p[cur];

        for(int i = 0;i <= sz[cur] + sz[nxt];i++) tmp[i] = {INF, MINF};
        for(int i = sz[nxt];i >= 0;i--){
            for(int j = 0;j <= sz[cur];j++){
                tmp[i + j].x = min(dp[nxt][i].x + dp[cur][j].x, tmp[i + j].x);
                tmp[i + j].y = max(dp[nxt][i].y + dp[cur][j].y, tmp[i + j].y);
            }
        }

        sz[nxt] += sz[cur];
        for(int i = 0;i <= sz[nxt];i++){
            dp[nxt][i].x = min(dp[nxt][i].x, tmp[i].x);
            dp[nxt][i].y = max(dp[nxt][i].y, tmp[i].y);
        }

        if(!--ind[nxt]) q.push_back(nxt);
    }

    for(int i = 0;i <= n;i++) r[i] = {INF, MINF};
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= n;j++){
            r[j].x = min(r[j].x, dp[i][j].x);
            r[j].y = max(r[j].y, dp[i][j].y);
        }
    }

    ll q; cin >> q;
    while(q--){
        ll sz, cnt; cin >> sz >> cnt;
        result += (sz >= r[cnt].x && sz <= r[cnt].y);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}