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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
map <ll, ll> dp;

ll solve(ll cur){
    if(dp.count(cur)) return dp[cur];
    ll& ret = dp[cur]; ret = 0;

    if(cur <= 2) return ret = 0;
    else if(cur <= 4) return ret = 1;

    ll div = (cur - 2) / 3;
    ll mod = (cur - 2) % 3;

    if(mod != 2){
        for(int i = 1;i <= mod;i++) ret += solve(div + 1);
        for(int i = mod + 1;i <= 3;i++) ret += solve(div);
        ret += 2;
    }
    else{
        ll mx = 0;
        mx = max(solve(div + 2) + 2 * solve(div), 2 * solve(div + 1) + solve(div));
        ret = mx + 2;
    }

    return ret;
}

int main() {
    fastio;

    cin >> n;
    cout << solve(n);
    
    
    return 0;
}