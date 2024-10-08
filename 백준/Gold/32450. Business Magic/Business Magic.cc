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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301010;
constexpr ll MOD = 998244353;
ll dp[MAX][3], a[MAX];

ll solve(ll cur, ll cnt){
    if(!cur) return 0;
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret;
    ret = -INF;

    if(cnt == 1){
        ll fi = solve(cur - 1, 1) + 2 * a[cur];
        ll se = solve(cur - 1, 2) + 2 * a[cur];
        ret = max(fi, se);
    }
    else if(cnt == 0){
        ll fi = solve(cur - 1, 1) + abs(a[cur]);
        ll se = solve(cur - 1, 0) + abs(a[cur]);
        ret = max(fi, se);
    }
    else if(cnt == 2){
        ll fi = solve(cur - 1, 2) + abs(a[cur]);
        ret = fi;
    }

    return ret;
}

int main() {
    fastio;

    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    cout << max(solve(n, 0), solve(n, 1));


    return 0;
}