#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][1ll << 5];
vector <ll> adj[MAX];

ll solve(ll cur, ll v){
    ll& ret = dp[cur][v];
    if(ret != -1) return ret; ret = 1;
    for(auto& nxt : adj[cur]){
        if(v & (1ll << a[nxt])) continue;
        ret += solve(nxt, v | (1ll << a[nxt]));
    }

    return ret;
}

void run(){
    cin >> n >> m >> k; ll result = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i], a[i]--;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e); adj[e].push_back(s);
    }

    for(int i = 1;i <= n;i++) result += solve(i, 1ll << a[i]);
    cout << result - n;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

