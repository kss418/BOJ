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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][10101][2];
class node{
public:
    ll e, c1, c2;
};
vector <node> adj[MAX];

ll solve(ll cur, ll cd, ll cnt){
    if(cd < 0) return 0;
    ll& ret = dp[cur][cd][cnt];
    if(ret != -1) return ret; ret = 0;

    for(auto& [nxt, c1, c2] : adj[cur]){
        ret = max(ret, solve(nxt, cd - (cnt ? c1 : c2), cnt));
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    while(m--){
        ll s, e, c, d; cin >> s >> e >> c >> d;
        adj[e].push_back({s, c, d});
    }

    ll result = INF; dp[1][0][0] = dp[1][0][1] = 1;
    for(int i = 1;i < 10101;i++){
        if(!solve(n, i, 0) || !solve(n, i, 1)) continue;
        cout << i; return;
    }
    cout << "IMPOSSIBLE";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

