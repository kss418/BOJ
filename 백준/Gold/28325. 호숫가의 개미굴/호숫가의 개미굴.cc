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
constexpr ll MAX = 251010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][2][2];

void run(){
    cin >> n; memset(dp, -0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    dp[1][0][0] = a[1]; dp[1][1][1] = 1;
    
    for(int i = 2;i <= n;i++){
        for(int j = 0;j <= 1;j++){
            dp[i][0][j] = max(dp[i - 1][1][j], dp[i - 1][0][j]) + a[i];
            dp[i][1][j] = dp[i - 1][0][j] + 1;
        }
    }

    cout << max({dp[n][0][1], dp[n][1][0], dp[n][0][0]});
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}