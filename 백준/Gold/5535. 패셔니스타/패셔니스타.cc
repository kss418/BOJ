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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][101];
ll mn[MAX], mx[MAX], num[MAX];

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> mn[i] >> mx[i] >> num[i];

    for(int i = 0;i <= n;i++){
        for(int j = 0;j < 101;j++) dp[i][j] = -INF;
    }
    
    for(int j = 1;j <= m;j++){
        if(a[1] < mn[j] || a[1] > mx[j]) continue;
        dp[1][num[j]] = 0;
    }

    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i] < mn[j] || a[i] > mx[j]) continue;
            for(int k = 0;k <= 100;k++) dp[i][num[j]] = max(dp[i - 1][k] + abs(num[j] - k), dp[i][num[j]]);
        }
    }

    ll result = 0;
    for(int i = 0;i <= 100;i++) result = max(result, dp[n][i]);

    cout << result;
    
     
    return 0;
}