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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX];
string st;

ll solve(ll a, ll b){
    ll& ret = dp[a][b];
    if(a == s.size() && b == st.size()) return ret = 0;
    if(a > s.size() || b > st.size()) return ret = INF;
    if(ret != -1) return ret; ret = INF;

    if(a < s.size() && b < st.size()){
        if(s[a] == st[b]) ret = min(ret, solve(a + 1, b + 1));
        else ret = min(ret, solve(a + 1, b + 1) + 1);
    }

    ret = min(ret, solve(a + 1, b) + 1);
    ret = min(ret, solve(a, b + 1) + 1);

    return ret;
}

void run(){
    cin >> s >> st; memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

