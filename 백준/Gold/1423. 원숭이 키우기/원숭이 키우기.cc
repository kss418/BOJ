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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], f[MAX], dp[MAX][101][101], use;

ll solve(ll cur, ll pl, ll use){
    ll& ret = dp[cur][pl][use];
    if(cur == n + 1) return ret = 0;
    if(ret != -1) return ret; ret = -INF;

    for(int i = 0;i <= min(use, a[cur] + pl);i++){
        ret = max(ret, solve(cur + 1, i, use - i) + (f[cur + 1] - f[cur]) * i);
    }

    return ret;
}

void run(){
    cin >> n; ll mx = 0, sum = 0; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> f[i];
    cin >> use;

    for(int i = 1;i <= n;i++) sum += a[i] * f[i];
    cout << sum + solve(0, 0, use);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

