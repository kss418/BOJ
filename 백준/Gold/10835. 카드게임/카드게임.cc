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
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], dp[MAX][MAX];

ll solve(ll l, ll r){
    ll& ret = dp[l][r];
    if(l == n + 1 || r == n + 1) return ret = 0;
    if(ret != -1) return ret; ret = 0;

    ret = max(ret, solve(l + 1, r));
    ret = max(ret, solve(l + 1, r + 1));
    if(a[l] > b[r]) ret = max(ret, solve(l, r + 1) + b[r]);

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    cout << solve(1, 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

