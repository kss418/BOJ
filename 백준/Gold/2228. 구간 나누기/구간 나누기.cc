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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX];

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i <= n;i++){
        for(int j = 1;j <= m;j++) dp[i][j] = -INF;
    }


    for(int cur = 1;cur <= n;cur++){
        dp[cur][1] = a[cur];
        for(int cnt = 1;cnt <= m;cnt++){
            dp[cur][cnt] = max(dp[cur][cnt], dp[cur - 1][cnt] + a[cur]);
            for(int pre = 0;pre < cur - 1;pre++){
                dp[cur][cnt] = max(dp[cur][cnt], dp[pre][cnt - 1] + a[cur]);
            }
        }
    }

    ll result = -INF;
    for(int i = 1;i <= n;i++) result = max(result, dp[i][m]);

    cout << result;


    return 0;
}