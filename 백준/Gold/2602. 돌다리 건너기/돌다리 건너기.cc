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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string a, b, c;
ll dp[MAX][MAX][2];

ll solve(ll cur, ll cs, ll t){
    ll& ret = dp[cur][cs][t];
    if(cs == c.size()) return 1;
    if(ret != -1) return ret; ret = 0;

    if(cur != a.size()) ret += solve(cur + 1, cs, t);
    if(cur != a.size() && a[cur] == c[cs] && !t) ret += solve(cur + 1, cs + 1, 1);
    if(cur != b.size() && b[cur] == c[cs] && t) ret += solve(cur + 1, cs + 1, 0);

    return ret;
}

void run(){
    cin >> c >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) + solve(0, 0, 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

