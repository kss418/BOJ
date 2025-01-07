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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 1e9;
int dp[MAX][20], result;

void run(){
    cin >> n;

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 19;j++){
            ll pre = i - (1ll << j);
            if(pre == 0) dp[i][j] = 1;
            if(pre <= 0) break;
            for(int k = 0;k <= j;k++) {
                dp[i][j] += dp[pre][k];
                dp[i][j] %= MOD;
            }
            dp[i][j] %= MOD;
        }
    }

    for(int i = 0;i < 20;i++) {
        result += dp[n][i];
        result %= MOD;
    }

    cout << result % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}