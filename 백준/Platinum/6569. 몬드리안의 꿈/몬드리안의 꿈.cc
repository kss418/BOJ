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
constexpr ll MAX = 14; // SET MAX SIZE
constexpr ll MOD = 9901;
ll dp[MAX * MAX + 1][1ll << MAX];


ll solve(ll cur, ll cnt){
    if(cur > n * m) return 0;
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(cur == n * m && !cnt) return ret = 1;
    
    if(cnt & 1) ret += solve(cur + 1, cnt >> 1ll);
    else{
        if(cur % m != m - 1 && (cnt & 2) == 0) ret += solve(cur + 2, cnt >> 2ll);
        ret += solve(cur + 1, (cnt >> 1ll) | 1ll << (m - 1));
    }

    return ret;
}

void run(){
    while(1){
        cin >> m >> n; memset(dp, -1, sizeof(dp));
        if(!m && !n) return;
        cout << solve(0, 0) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

