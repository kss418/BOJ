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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
vector <ll> adj[MAX], org[MAX];
ll dp[MAX][MAX];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(cnt <= 1) return ret = 1;

    ll tmp[MAX][MAX] = {0}; tmp[0][0] = 1;
    for(int i = 0;i < adj[cur].size();i++){
        ll nxt = adj[cur][i];
        for(int j = 0;j < cnt;j++){
            for(int k = 0;k <= j;k++){
                tmp[i + 1][j] += tmp[i][j - k] * solve(nxt, k);
                tmp[i + 1][j] %= MOD;
            }
        }
    }

    ret = tmp[adj[cur].size()][cnt - 1];
    return ret %= MOD;
}

void mktree(ll cur, ll pre = -1){
    for(auto& nxt : org[cur]){
        if(nxt == pre) continue;
        adj[cur].push_back(nxt);
        mktree(nxt, cur);
    }
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        org[s].push_back(e);
        org[e].push_back(s);
    }
    mktree(1);

    ll result = 0;
    for(int i = 1;i <= n;i++){
        result += solve(i, m);
        result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}