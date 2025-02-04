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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 1e9 + 9;
ll dp[MAX][7];

void pm(ll &a, ll b){
    b %= MOD;
    a += b; a %= MOD;
}

void run(){
    cin >> n >> m; dp[0][0] = 1;
    for(int i = 0;i < n;i++){
        for(int cnt = 0;cnt < 7;cnt++){
            ll now = dp[i][cnt];
            if(!cnt){
                pm(dp[i + 1][cnt + 1], now);
                pm(dp[i + 1][0], (m - 1) * now);
            }
            else if(cnt == 2){
                pm(dp[i + 1][0], (m - 2) * now);
                pm(dp[i + 1][3], now);
                pm(dp[i + 1][5], now);
            }
            else if(cnt == 6){
                pm(dp[i + 1][0], (m - 2) * now);
                pm(dp[i + 1][5], now);
            }
            else{
                if(cnt != 4) pm(dp[i + 1][cnt + 1], now);
                pm(dp[i + 1][1], now);
                pm(dp[i + 1][0], (m - 2) * now);
            }
        }
    }

    ll result = 0;
    for(int i = 0;i < 7;i++) pm(result, dp[n][i]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}