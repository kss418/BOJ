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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 15746;
ll dp[MAX];

ll solve(ll num){
    ll& ret = dp[num];
    if(num == 1) return ret = 1;
    if(num == 2) return ret = 2;
    if(ret != -1) return ret; ret = 0;

    ret = solve(num - 1) % MOD + solve(num - 2) % MOD;
    return ret %= MOD;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    cout << solve(n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}