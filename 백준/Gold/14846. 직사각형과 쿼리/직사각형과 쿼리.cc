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
constexpr ll MAX = 301; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], dp[MAX][MAX][11];

int main() {
    fastio;
    
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= 10;k++){
                dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
                if(k == a[i][j]) dp[i][j][k]++;
            }
        }
    }

    cin >> m;
    while(m--){
        ll result = 0;
        ll x1, x2, y1, y2; cin >> y1 >> x1 >> y2 >> x2;
        for(int i = 1;i <= 10;i++){
            ll now = dp[y2][x2][i] - dp[y2][x1 - 1][i];
            now += -dp[y1 - 1][x2][i] + dp[y1 - 1][x1 - 1][i];
            if(now) result++;
        }

        cout << result << "\n";
    }
    
    
    return 0;
}