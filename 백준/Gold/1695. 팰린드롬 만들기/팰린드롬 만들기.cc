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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
int dp[MAX][MAX], arr[MAX];

int solve(ll a, ll b){
    int& ret = dp[a][b];
    if(ret != -1) return ret; ret = 1e5;
    if(a > b + 1) return ret;
    if(a == b || a == b + 1) return ret = 0;

    ret = min(ret, solve(a + 1, b) + 1);
    ret = min(ret, solve(a, b - 1) + 1);
    ret = min(ret, solve(a + 1, b - 1) + (arr[a] == arr[b] ? 0 : 2));

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> arr[i];

    cout << solve(1, n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

