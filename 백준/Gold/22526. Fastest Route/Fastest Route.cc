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
constexpr ll MAX = 17; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], dp[MAX][1ll << MAX];

ll solve(ll cur, ll v){
    ll& ret = dp[cur][v];
    if(v == (1ll << n + 1) - 1) return ret = 0;
    if(ret != -1) return ret; ret = INF;

    for(ll nxt = 1;nxt <= n;nxt++){
        if(v & (1ll << nxt)) continue;
        ll mn = INF;
        for(ll use = 0;use <= n;use++){
            if(v & (1ll << use)) mn = min(mn, a[nxt][use]);
        }

        ret = min(ret, solve(nxt, v | (1ll << nxt)) + mn);
    }

    return ret;
}

void run(){
    while(1){
        cin >> n; if(!n) return;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= n;j++) cin >> a[i][j];
        }
        
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 1) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}