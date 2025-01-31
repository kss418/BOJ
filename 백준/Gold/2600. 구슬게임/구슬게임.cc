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
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[3], dp[MAX][MAX][2];

ll solve(ll s, ll e, ll t){
    if(s < 0 || e < 0) return t ^ 1;
    ll& ret = dp[s][e][t];
    if(ret != -1) return ret;
    ret = (t ? 1 : 0);

    for(int i = 0;i < 3;i++){
        if(t){
            ret = min(ret, solve(s - a[i], e, t ^ 1));
            ret = min(ret, solve(s, e - a[i], t ^ 1));
        }
        else{
            ret = max(ret, solve(s - a[i], e, t ^ 1));
            ret = max(ret, solve(s, e - a[i], t ^ 1));
        }
    }

    return ret;
}

void run(){
    for(int i = 0;i <= 2;i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));

    for(int i = 1;i <= 5;i++){
        ll a, b; cin >> a >> b; 
        cout << (solve(a, b, 0) ? "A" : "B") << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

