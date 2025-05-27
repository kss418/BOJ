#include <bits/stdc++.h>
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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][2], result, cnt, dp[MAX][2];
vector <ll> adj[MAX];

ll solve(ll cur, ll cnt, ll pre = -1){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(a[cur][cnt] < a[cur][cnt ^ 1]) return ret;
    ret = 0;

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ret += min(solve(nxt, cnt, cur), solve(nxt, cnt ^ 1, cur) + 1); 
    }
    
    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i][0];
    for(int i = 1;i <= n;i++) cin >> a[i][1];
    for(int i = 1;i <= n;i++) result += max(a[i][0], a[i][1]);

    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    cout << result << " " << min(solve(1, 0), solve(1, 1) + 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}