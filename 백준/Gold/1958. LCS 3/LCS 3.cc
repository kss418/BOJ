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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][MAX];

int main() {
    fastio;

    string a, b, c; cin >> a >> b >> c;
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < b.size();j++){
            for(int k = 0;k < c.size();k++){
                if(a[i] == b[j] && b[j] == c[k]){
                    dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
                }
                else{
                    dp[i + 1][j + 1][k + 1] = max({dp[i + 1][j + 1][k], dp[i][j + 1][k + 1], dp[i + 1][j][k + 1]});
                }
            }
        }
    }

    cout << dp[a.size()][b.size()][c.size()];
    
     
    return 0;
}