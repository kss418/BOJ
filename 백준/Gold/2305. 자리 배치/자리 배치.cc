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
constexpr ll MAX = 41; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][2][1 << 2], result;

ll solve(ll cur, ll use, ll v){
    ll& ret = dp[cur][use][v];
    if(cur == n + 1) return 1;
    if(ret != -1) return ret; ret = 0;

    if(cur == m) ret += solve(cur + 1, use, v >> 1ll);
    else{
        if(cur - 1 != m && cur != 1 && !(v & 1)) ret += solve(cur + 1, use, v >> 1ll);
        if(!(v & 2)) ret += solve(cur + 1, use, (v | (1ll << 1)) >> 1ll);
        if(cur + 1 != m && cur + 1 != n + 1) ret += solve(cur + 1, use, (v | (1ll << 2)) >> 1ll);

        if(!use) ret += solve(cur + 1, 1, v >> 1ll);
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    cout << solve(1, 0, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

