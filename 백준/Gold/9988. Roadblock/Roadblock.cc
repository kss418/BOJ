#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 303; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll adj[MAX][MAX], d[MAX];
ll pre[MAX], result;
priority_queue <pll, vector<pll>, greater<pll>> pq;

ll dij(bool flag = 0){
    memset(d, 0x3f, sizeof(d));
    while(!pq.empty()) pq.pop();

    pq.push({0, 1});
    d[1] = 0;
    while(!pq.empty()){
        auto[cd, cur] = pq.top(); pq.pop();
        if(cd > d[cur]) continue;
        
        for(int i = 1;i <= n;i++){
            if(adj[cur][i] == INF) continue;
            ll nd = cd + adj[cur][i];
            if(d[i] <= nd) continue; d[i] = nd; 
            if(flag) pre[i] = cur;
            pq.push({nd, i});
        }
    }

    return d[n];
}

void run(){
    cin >> n >> m; memset(adj, 0x3f, sizeof(adj));
    memset(pre, -1, sizeof(pre));
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s][e] = min(adj[s][e], c);
        adj[e][s] = min(adj[e][s], c);
    }
    
    ll org = dij(1), cur = n;
    while(pre[cur] != -1){
        adj[pre[cur]][cur] <<= 1;
        adj[cur][pre[cur]] <<= 1;
        result = max(dij() - org, result);
        adj[pre[cur]][cur] >>= 1;
        adj[cur][pre[cur]] >>= 1;
        cur = pre[cur];
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}