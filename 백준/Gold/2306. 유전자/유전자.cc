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
ll n, m, k, t = 1; string st;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX];

ll solve(ll s, ll e){
    ll& ret = dp[s][e];
    if(ret != -1) return ret; ret = 0;
    if(s > e) return ret;

    if(e - s == 1){
        if(st[s] == 'a' && st[e] == 't') return ret = 2;
        if(st[s] == 'g' && st[e] == 'c') return ret = 2;
    }
    else{
        for(int mid = s;mid < e;mid++){
            ret = max(ret, solve(s, mid) + solve(mid + 1, e));
        }

        if(st[s] == 'a' && st[e] == 't') ret = max(ret, solve(s + 1, e - 1) + 2);
        if(st[s] == 'g' && st[e] == 'c') ret = max(ret, solve(s + 1, e - 1) + 2);
    }

    return ret;
}

void run(){
    cin >> st; n = st.size(); 
    memset(dp, -1, sizeof(dp));

    cout << solve(0, n - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}