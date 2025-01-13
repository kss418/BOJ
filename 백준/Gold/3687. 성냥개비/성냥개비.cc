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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll mn[8] = { 0, 0, 1, 7, 4, 2, 0, 8 }, dp[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;
    for(int i = 2;i <= 7;i++) ret = min(ret, solve(cur - i) * 10 + mn[i]);
    return ret;
}

void run(){
    cin >> n;
    cout << solve(n) << " ";

    cout << (n % 2 ? 7 : 1);
    for(int i = 1;i < n / 2;i++) cout << 1; cout << "\n";
}

int main() {
    fastio; cin >> t;
    memset(dp, -1, sizeof(dp));
    dp[1] = 9; dp[2] = 1; dp[3] = 7; dp[4] = 4;
    dp[5] = 2; dp[6] = 6; dp[7] = 8;
    while(t--) run(); 

    return 0;
}

