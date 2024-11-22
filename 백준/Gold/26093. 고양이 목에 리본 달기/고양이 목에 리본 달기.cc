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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[101][MAX], dp[101][MAX];
multiset <ll> num[2];


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= m;i++) num[0].insert(0);
    for(int i = 1;i <= n;i++){
        ll cur = i & 1, pre = cur ^ 1;
        for(int j = 1;j <= m;j++){
            num[pre].erase(num[pre].find(dp[i - 1][j]));
            dp[i][j] = *--num[pre].end() + a[i][j];
            num[pre].insert(dp[i - 1][j]);
            num[cur].insert(dp[i][j]);
        }
        num[pre].clear();
    }

    ll result = 0;
    for(int i = 1;i <= m;i++) result = max(result, dp[n][i]);

    cout << result;


    return 0;
}

