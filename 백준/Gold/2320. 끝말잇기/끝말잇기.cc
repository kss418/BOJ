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
constexpr ll MAX = 17; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll dp[MAX][1ll << MAX];

ll solve(ll cur, ll v){
    ll& ret = dp[cur][v];
    if(ret != -1) return ret; ret = 0;

    char bck = st[cur].back();
    for(ll i = 0;i < n;i++){
        if(v & 1ll << i) continue;
        char fr = st[i].front(); 
        if(fr != bck) continue;

        ret = max<ll>(ret, solve(i, v | (1ll << i)) + st[i].size());
    }

    return ret;
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];
    
    ll result = 0; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++){
        result = max<ll>(result, solve(i, 1ll << i) + st[i].size());
    }
    
    cout << result;
}

int main() {
    fastio;

    // cin >> t;
    while(t--) run();
    

    return 0;
}