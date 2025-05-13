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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], ind[MAX], dp[MAX];
vector <ll> adj[MAX];
deque <ll> q;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        ind[e]++;
    }

    for(int i = 1;i <= n;i++){
        if(!ind[i]) q.push_back(i);
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        dp[cur] += a[cur];
        for(auto& nxt : adj[cur]){
            dp[nxt] = max(dp[nxt], dp[cur]);
            if(!--ind[nxt]) q.push_back(nxt);
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++) result = max(result, dp[i]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}