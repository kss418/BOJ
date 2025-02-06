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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX][2];

ll solve(ll cur, ll cnt, ll use){
    if(cur <= 0) return (cnt ? INF : 0);
    ll& ret = dp[cur][cnt][use];
    if(ret != -1) return ret; ret = INF;

    if(!use){
        ret = min(ret, solve(cur - 1, cnt, 0));
        ret = min(ret, solve(cur - 1, cnt, 1));
    }
    else if(cnt){
        ll nxt = (cur == n) ? 0 : max(a[cur + 1] - a[cur] + 1, 0ll);
        ll pre = (cur == 1) ? 0 : max(a[cur - 1] - a[cur] + 1, 0ll);
        ret = min(ret, solve(cur - 2, cnt - 1, 0) + nxt + pre);

        if(cur > 2){
            if(a[cur - 2] <= a[cur - 1]) pre = max(a[cur - 2] - a[cur], 0ll);
            else pre = max(a[cur - 1] - a[cur] + 1, 0ll);
        }
        pre = (cur == 2) ? max(a[cur - 1] - a[cur] + 1, 0ll) : pre;
        ret = min(ret, solve(cur - 2, cnt - 1, 1) + nxt + pre);
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    a[0] = a[n + 1] = MINF;
    for(int i = 1;i <= (n + 1) / 2;i++) cout << min(solve(n, i, 0), solve(n, i, 1)) << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

