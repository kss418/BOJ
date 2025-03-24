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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX], result;
vector <ll> adj[MAX];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != INF) return ret; ret = MINF;
    if(!cnt) return ret;

    for(auto& nxt : adj[cur]){
        ret = max(ret, solve(nxt, cnt - 1) + a[cur]);
    }

    return ret;
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
    }

    memset(dp, 0x3f, sizeof(dp)); dp[1][0] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 1000;j++) solve(i, j);
    }

    for(ll i = 1;i <= 1000;i++){
        for(ll j = 1;j <= 1000;j++){
            ll now = solve(1, i) * j - k * (i * j) * (i * j);
            result = max(result, now);
            if(now < 0) break;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}