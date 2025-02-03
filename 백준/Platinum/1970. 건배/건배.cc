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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX], result;

void solve(){
    for(int i = 1;i < 2 * n;i++) dp[i][i + 1] = (a[i] == a[i + 1]);
    for(int d = 2;d < n;d++){
        for(int i = 1;i <= 2 * n;i++){
            if(i + d > 2 * n) break;
            dp[i][i + d] = dp[i + 1][i + d - 1] + (a[i] == a[i + d]);
            for(int j = 0;j < d;j++){
                dp[i][i + d] = max(dp[i][i + d], dp[i][i + j] + dp[i + j + 1][i + d]);
            }
        }
    }
}

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = n + 1;i <= 2 * n;i++) a[i] = a[i - n];
    solve();

    for(int i = 1;i <= n;i++) result = max(result, dp[i][i + n - 1]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}