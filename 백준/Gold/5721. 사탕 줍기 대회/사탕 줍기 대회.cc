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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

int main() {
    fastio;

    while(1){
        cin >> n >> m; if(!n) break;
        vector <vector <ll>> a, dp;
        a.resize(n + 1, vector <ll>(m + 1));
        dp.resize(n + 1, vector <ll>(m + 1));

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++) cin >> a[i][j];
        }

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(j == 1) dp[i][j] = a[i][j];
                else dp[i][j] = max(dp[i][j - 1], dp[i][j - 2] + a[i][j]);
            }
        }

        vector <ll> result(n + 1);
        for(int i = 1;i <= n;i++){
            if(i == 1) result[i] = dp[i][m];
            else result[i] = max(result[i - 1], result[i - 2] + dp[i][m]);
        }

        cout << result[n] << "\n";
    }
    
     
    return 0;
}