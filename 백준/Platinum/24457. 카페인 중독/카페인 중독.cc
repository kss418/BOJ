#include <bits/stdc++.h>
#include <ext/rope>
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
pll a[MAX];
ll dp[MAX][MAX];

ll solve(ll cur, ll use){
    ll& ret = dp[cur][use];
    if(ret != -1) return ret;
    if(cur == n + 1) return ret = 0;
    if(!use) return ret = 0;
    ret = 0;

    ret = max(ret, solve(cur + 1, use));
    ret = max(ret, solve(cur + 1, use - 1) + a[cur].y - a[cur].x * (use - 1));

    return ret;
}

int main() {
    fastio;

    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].y;
    for(int i = 1;i <= n;i++) cin >> a[i].x;
    sort(a + 1, a + n + 1);

    ll result = 0;
    for(int i = 0;i <= n;i++) {
        result = max(result, solve(1, i));
    }

    cout << result;


    return 0;
}

