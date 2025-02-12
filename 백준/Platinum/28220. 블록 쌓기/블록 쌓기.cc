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
constexpr ll MAX = 105; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 101;
ll a[MAX], dp[MAX][MAX][10101];
ll sum[MAX];

ll solve(ll cur, ll num, ll all){
    if(all < 0 || num < 0) return INF;
    if(all > cur * k) return INF;
    ll& ret = dp[cur][num][all];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = (all ? INF : 0);

    ret = min(ret, solve(cur - 1, num, all - num) + abs(sum[cur] - all));
    ret = min(ret, solve(cur, num - 1, all));

    return ret;
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; a[i] -= m;
        sum[i] = sum[i - 1] + a[i];
    }
    k -= m; m = 0; memset(dp, -1, sizeof(dp));
    if(sum[n] < 0 || sum[n] > k * n){ cout << -1; return; }

    cout << solve(n, k, sum[n]);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

