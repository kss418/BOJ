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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 3010; // PLZ CHK!
constexpr ll MOD = 998244353;
ld a[MAX], dp[MAX][11];
ld per[MAX][MAX], sum[MAX][MAX];

ld solve(ll cur, ll use){
    ld& ret = dp[cur][use];
    if(ret > -0.5) return ret;
    if(!use) return ret = 0;
    if(cur == n + 1) return ret = 0;

    for(int nxt = cur + 1;nxt <= n + 1;nxt++){
        ld now = solve(nxt, use - 1) + sum[cur][nxt - 1];
        ret = max(ret, now);
    }
    
    return ret;
}


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        per[i][i] = 1 - a[i];
        sum[i][i] = per[i][i];

        for(int j = i + 1;j <= n;j++){  
            per[i][j] = per[i][j - 1] * (1 - a[j]);
            sum[i][j] = sum[i][j - 1] + per[i][j];
        }
    }

    memset(dp, -2, sizeof(dp));

    cout.precision(11);
    cout << solve(1, m);

    
    return 0;
}