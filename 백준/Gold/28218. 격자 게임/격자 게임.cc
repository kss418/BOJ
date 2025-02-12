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
constexpr ll MAX = 301; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][2];
string st[MAX];

ll solve(ll cy, ll cx, ll t){
    if(cy >= n || cx >= m) return (t ? -INF : INF);
    ll& ret = dp[cy][cx][t];
    if(ret != -1) return ret; ret = (t ? INF : -INF);
    if(st[cy][cx] == '#') return ret = (t ? -INF : INF);
    if(cy == n - 1 && cx == m - 1) return ret = t;
    
    if(t){
        ret = min(ret, solve(cy + 1, cx, 0));
        ret = min(ret, solve(cy, cx + 1, 0));
        for(int i = 1;i <= k;i++){
            ret = min(ret, solve(cy + i, cx + i, 0));
        }
    }
    else{
        ret = max(ret, solve(cy + 1, cx, 1));
        ret = max(ret, solve(cy, cx + 1, 1));
        for(int i = 1;i <= k;i++){
            ret = max(ret, solve(cy + i, cx + i, 1));
        }
    }

    if(abs(ret) >= INF) return ret = (t ? -INF : INF);
    return ret;
}

void run(){
    cin >> n >> m >> k; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> st[i];

    ll q; cin >> q;
    while(q--){
        ll cy, cx; cin >> cy >> cx;
        cout << (solve(cy - 1, cx - 1, 0) ? "First" : "Second") << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}