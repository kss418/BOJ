#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
constexpr ll MOD = 998244353;
ll ind[MAX], dp[MAX];
vector <pll> adj[MAX];
deque <ll> q;

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> dp[i];
    while(k--){
        ll s, e, c; cin >> s >> e >> c;
        ind[e]++; adj[s].push_back({e, c});
    }

    for(int i = 1;i <= n;i++){
        if(ind[i]) continue;
        q.push_back(i);
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        for(auto& [nxt, co] : adj[cur]){
            dp[nxt] = max(dp[nxt], dp[cur] + co);
            if(!--ind[nxt]) q.push_back(nxt);
        }
    }

    for(int i = 1;i <= n;i++) cout << dp[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}