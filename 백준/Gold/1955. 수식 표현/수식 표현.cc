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

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;

    for(int i = 1;i < cur;i++) ret = min(ret, solve(i) + solve(cur - i));
    for(int i = 2;i * i <= cur;i++){
        if(cur % i) continue;
        ret = min(ret, solve(i) + solve(cur / i));
    }

    ll cnt = 1, mul = 1;
    while(mul < cur) mul *= cnt++;
    if(mul == cur) ret = min(ret, solve(cnt - 1));

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp)); dp[1] = 1;
    cout << solve(n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

