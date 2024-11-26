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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
ll up[MAX][MAX], dw[MAX][MAX];


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            up[i][j] = dw[i][j] = a[i][j];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            up[i][j] = max(up[i][j], max(up[i - 1][j], up[i][j - 1]) + a[i][j]);
        }
    }

    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= m;j++){
            dw[i][j] = max(dw[i][j], max(dw[i + 1][j], dw[i][j - 1]) + a[i][j]);
        }
    }

    ll result = -INF;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            result = max({result, up[i][j], dw[i][j]});
        } 
    }

    cout << result;
    
     
    return 0;
}