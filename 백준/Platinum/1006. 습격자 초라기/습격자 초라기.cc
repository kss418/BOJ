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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][2], dp[MAX][3][4];

void run(){
    cin >> n >> m; memset(dp, 0x3f, sizeof(dp));
    for(int i = 0;i <= 1;i++){
        for(int j = 1;j <= n;j++) cin >> a[j][i];
    }
    a[n + 1][0] = a[1][0]; a[n + 1][1] = a[1][1];

    if(a[1][0] + a[1][1] <= m) dp[1][2][2] = 1;
    else dp[1][2][2] = 2;
    dp[1][2][1] = 1; dp[1][2][0] = 1; dp[1][2][3] = 0;

    ll z = 0, o = 0;
    z += (a[1][0] + a[2][0] <= m) ? 1 : 2;
    o += (a[1][1] + a[2][1] <= m) ? 1 : 2;
    dp[2][0][0] = z; dp[2][1][1] = o; dp[2][2][2] = o + z;

    for(int i = 2;i <= n + 1;i++){
        for(int j = 0;j < 4;j++){
            dp[i][0][j] = min(dp[i][0][j], dp[i - 1][2][j] + 1);
            dp[i][1][j] = min(dp[i][1][j], dp[i - 1][2][j] + 1);
            dp[i][2][j] = min(dp[i][2][j], dp[i - 1][2][j] + 2);

            if(a[i][0] + a[i][1] <= m) dp[i][2][j] = min(dp[i][2][j], dp[i - 1][2][j] + 1);
            ll z = 0, o = 0;
            z += (a[i][0] + a[i - 1][0] <= m) ? 1 : 2;
            o += (a[i][1] + a[i - 1][1] <= m) ? 1 : 2;

            dp[i][0][j] = min(dp[i][0][j], dp[i - 1][1][j] + z);
            dp[i][1][j] = min(dp[i][1][j], dp[i - 1][0][j] + o);
            if(i > 2) dp[i][2][j] = min(dp[i][2][j], dp[i - 2][2][j] + z + o);

            dp[i][2][j] = min({dp[i][2][j], dp[i][0][j] + 1, dp[i][1][j] + 1});
        }
    }
    
    cout << min({dp[n + 1][1][0], dp[n + 1][0][1], dp[n][2][2], dp[n + 1][2][3]}) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

