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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[101][MAX];

void run(){
    cin >> n >> m; memset(dp, 0xc0, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++) {
        ll a, b; cin >> a >> b;
        for(int j = 0;j <= m;j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j >= a) dp[i][j] = max(dp[i][j], dp[i - 1][j - a] + b);
        }
    }

    ll result = 0;
    for(int i = 0;i <= m;i++) result = max(result, dp[n][i]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

