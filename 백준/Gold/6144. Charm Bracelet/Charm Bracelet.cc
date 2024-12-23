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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 13101; // SET MAX SIZE
constexpr ll MOD = 998244353;
short c[MAX], v[MAX], dp[3501][MAX];

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> c[i] >> v[i];

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j >= c[i]) dp[i][j] = max<short>(dp[i][j], dp[i - 1][j - c[i]] + v[i]);
        }
    }

    short result = 0;
    for(int i = 0;i <= m;i++) result = max<short>(result, dp[n][i]);

    cout << result;

     
    return 0;
}