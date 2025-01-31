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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX]; ll dp[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;

    ll mx = 2 * abs(a[cur].y);
    ret = min(ret, solve(cur - 1) + mx);
    for(int i = cur - 1;i >= 1;i--){
        mx = max(mx, a[cur].x - a[i].x);
        mx = max(mx, 2 * abs(a[i].y));
        ret = min(ret, solve(i - 1) + mx);
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp)); dp[0] = 0;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);
    cout << solve(n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

