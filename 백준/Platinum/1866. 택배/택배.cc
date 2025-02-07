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
ll a[MAX], result = INF, dp[MAX][2];
ll pre[MAX], suf[MAX];

ll solve(ll cur, ll use){
    if(!cur) return (use ? INF : 0);
    ll& ret = dp[cur][use];
    if(ret != -1) return ret; ret = INF;
    
    for(int i = 0;i < cur;i++){
        ret = min(ret, solve(i, 0) + (pre[cur] - pre[i]) * m + ((use) ? k : 0));
        ret = min(ret, solve(i, 1) + (pre[cur] - pre[i] - (cur - i) * a[i]) * m + ((use) ? k : 0));
        if(use) {
            ret = min(ret, solve(i, 1) + abs(suf[i + 1] - suf[cur + 1] - (cur - i) * a[cur]) * m + k);
            ret = min(ret, solve(i, 0) + abs(suf[i + 1] - suf[cur + 1] - (cur - i) * a[cur]) * m + k);
        }
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> m >> k; sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
    for(int i = n;i >= 1;i--) suf[i] = suf[i + 1] + a[i];

    cout << min(solve(n, 0), solve(n, 1));
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

