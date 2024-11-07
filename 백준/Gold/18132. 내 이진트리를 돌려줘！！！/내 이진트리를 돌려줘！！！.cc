#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 5010;
constexpr ll MOD = 1e9 + 7;
ll dp[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret;
    if(cur <= 1) return ret = 1;
    ret = 0;

    for(int i = 0;i < cur;i++){
        ll l = solve(i), r = solve(cur - i - 1);
        ret += l * r; ret %= MOD;
    }

    return ret;
}

int main() {
    fastio;


    cin >> t; memset(dp, -1, sizeof(dp));
    while(t--){
        cin >> n;
        cout << solve(n + 1) << "\n";
    }


    return 0;
}

