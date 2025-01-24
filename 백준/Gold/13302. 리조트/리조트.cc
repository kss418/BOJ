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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX];

ll solve(ll cur, ll cnt){
    if(cur > n) return 0;
    ll& ret = dp[cur][cnt]; 
    if(ret != -1) return ret; ret = INF;
    if(a[cur]) ret = min(ret, solve(cur + 1, cnt));
    if(cnt >= 3) ret = min(ret, solve(cur + 1, cnt - 3));
    ret = min(ret, solve(cur + 1, cnt) + 10000);
    ret = min(ret, solve(cur + 3, cnt + 1) + 25000);
    ret = min(ret, solve(cur + 5, cnt + 2) + 37000);

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= m;i++) cin >> k, a[k] = 1;
    cout << solve(1, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

