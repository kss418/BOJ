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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

ll solve(ll cur){
    ll ret = 0;
    for(int i = 0;cur >= (1ll << i);i++){
        ll now = 1ll << i;
        ll cnt = max(cur - now + 1, 0ll);
        ll div = cnt / now;

        if(div % 2 == 0) ret += cnt % now;
        div = (div + 1) / 2;

        ret += div * now;
    }
    
    return ret;
}


int main() {
    fastio;

    cin >> n >> m;
    cout << solve(m) - solve(n - 1) << "\n";


    return 0;
}

