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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX];

class node{
public:
    ll x, y, t;
    bool operator < (const node& ot) const{
        return t < ot.t;
    }
} a[MAX];

ld dist(pll v1, pll v2){
    ld dx = v1.x - v2.x;
    ld dy = v1.y - v2.y;
    return sqrtl(dx * dx + dy * dy);
}

void run(){
    cin >> n >> m; memset(dp, -0x3f, sizeof(dp)); dp[0] = 0;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y >> a[i].t;
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < i;j++){
            node cur = a[i], pre = a[j];
            if(dist({cur.x, cur.y}, {pre.x, pre.y}) > (ld)m * (ld)(cur.t - pre.t)) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++) result = max(result, dp[i]);

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

