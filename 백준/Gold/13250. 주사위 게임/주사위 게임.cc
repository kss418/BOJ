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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ld dp[MAX];

ld solve(ll cur){
    ld& ret = dp[cur];
    if(ret > -0.5) return ret;
    ret = 0;

    for(int i = 1;i <= 6ll;i++){
        ret += (solve(max(cur - i, 0ll)) + 1) / 6ll; 
    }

    return ret;
}  

int main() {
    fastio;

    cin >> n; cout.precision(20); dp[0] = 0;
    for(int i = 1;i <= n;i++) dp[i] = -1;
    cout << solve(n);

     
    return 0;
}