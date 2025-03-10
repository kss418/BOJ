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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pos[1010101], result, dp[MAX][MAX];

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++) cin >> a[i], pos[a[i]] = i;

    for(int i = n;i >= 1;i--){
        for(int j = i - 1;j >= 1;j--){
            ll cur = a[i], pre = a[j], nxt = 2 * cur - pre;
            ll nidx = (nxt >= 1010101 ? 0 : pos[nxt]), diff = cur - pre;
            dp[j][i] = (nidx ? dp[i][nidx] + 1 : 2);
            ll now = dp[j][i] * a[j] + diff * (dp[j][i] - 1) * dp[j][i] / 2;
            if(dp[j][i] >= 3) result = max(result, now);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

