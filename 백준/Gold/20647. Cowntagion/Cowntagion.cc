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
ll a[MAX], ind[MAX], dp[MAX];
vector <ll> adj[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;
    if(pre != -1) ind[cur]--;

    ret += ind[cur];
    while(ind[cur]){
        ind[cur] >>= 1ll; ret++;
    }

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ret += solve(nxt, cur);
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        ind[s]++; ind[e]++;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    cout << solve(1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}