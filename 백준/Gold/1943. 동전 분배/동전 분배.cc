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
ll n, m, k, t = 3; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 50101;
ll a[MAX], dp[MAX][101010];

void run(){
    cin >> n; memset(dp, 0, sizeof(dp));
    dp[0][MID] = 1;

    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> m;
        for(int j = 0;j < 101010;j++) {
            if(!dp[i - 1][j]) continue;
            for(int k = -m;k <= m;k += 2){
                ll now = j + a[i] * k;
                if(now < 0 || now >= 101010) continue;
                dp[i][now] = 1;
            }
        }
    }

    cout << dp[n][MID] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}