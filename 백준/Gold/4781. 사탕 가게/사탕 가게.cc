#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 5010;
constexpr ll MOD = 998244353;
ll v[MAX], co[MAX], dp[10101];


int main() {
    fastio;

    while(1){
        ld m; cin >> n >> m;
        ll use = 100 * m + 0.5;
        if(!n) break;

        memset(dp, 0, sizeof(dp));
        for(int i = 1;i <= n;i++){
            cin >> v[i] >> m;
            co[i] = 100 * m + 0.5;
        }

        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= use;j++){
                if(j >= co[i]) dp[j] = max(dp[j], dp[j - co[i]] + v[i]);
            }
        }
   

        ll result = 0;
        for(int i = 0;i <= use;i++) result = max(result, dp[i]);

        cout << result << "\n";
    }
    

    return 0;
}