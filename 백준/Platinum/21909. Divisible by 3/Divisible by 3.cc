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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][3][3];
ll result;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], a[i] %= 3;

    for(int i = 1;i <= n;i++){
        dp[i][0][a[i]]++;
        for(int j = 0;j < 3;j++){
            for(int k = 0;k < 3;k++) dp[i][(j + k * a[i]) % 3][(k + a[i]) % 3] += dp[i - 1][j][k];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int k = 0;k < 3;k++) result += dp[i][0][k];
    }
    cout << result;

     
    return 0;
}