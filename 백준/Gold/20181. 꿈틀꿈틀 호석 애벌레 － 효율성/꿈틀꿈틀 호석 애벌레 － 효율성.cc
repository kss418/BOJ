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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], nxt[MAX];
ll dp[MAX], pl[MAX], sum[MAX];

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for(int i = 1;i <= n;i++){
        ll num = lower_bound(sum + 1, sum + n + 1, sum[i - 1] + m) - sum;
        nxt[i] = num + 1;
        if(nxt[i] != n + 2) pl[i] = sum[num] - sum[i - 1] - m;
    }

    for(int i = 1;i <= n;i++){
        dp[i] = max(dp[i], dp[i - 1]);
        dp[nxt[i]] = max(dp[i] + pl[i], dp[nxt[i]]);
    }
    dp[n + 1] = max(dp[n + 1], dp[n]);

    cout << dp[n + 1];

     
    return 0;
}