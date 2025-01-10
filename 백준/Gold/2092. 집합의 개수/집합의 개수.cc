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
constexpr ll MAX = 4010; // SET MAX SIZE
constexpr ll MOD = 1e6;
ll cnt[MAX], dp[MAX][201];

ll solve(ll cur, ll mx){
    if(mx < 0) return 0;
    ll& ret = dp[cur][mx];
    if(!cur) return ret = 1;
    if(ret != -1) return ret; ret = 0;

    for(int i = 0;i <= min(cnt[mx], cur);i++){
        ret += solve(cur - i, mx - 1);
        ret %= MOD;
    }

    return ret %= MOD;
}

void run(){
    ll l, r, mx; cin >> mx >> n >> l >> r;
    for(int i = 1;i <= n;i++) cin >> m, cnt[m]++;
    
    ll result = 0; memset(dp, -1, sizeof(dp));
    for(int i = l;i <= r;i++){
        result += solve(i, 200);
        result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

